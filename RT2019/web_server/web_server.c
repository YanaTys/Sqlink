#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

const int max_request=4096;
const int max_filesize=4096;
const int port=8080;
const char* response=
"HTTP/1.1 200 OK\n"
"\n";

void check_error(int val) {
	if(val==-1)
	{
		perror("myserver");
		exit(1);
	}
}

void write_to_fd(int fd, const char* buff, int size) {
	int written=0;
	const char* pos=buff;
	while(written<size) {
		written+=write(fd, pos, size-written);
		pos+=written;
	}
}

void read_from_fd(int fd, char* buff, int size) {
	int read_size=0;
	char* pos=buff;
	while(read_size<size) {
		read_size+=read(fd, pos, size-read_size);
		pos+=read_size;
	}
}

void clientServerChat(int connectionfd)
{
	const char* filename="index.html";

	/* allocate buffer for request */
	char* request=malloc(max_request);

	/* read the request */
	int ret=read(connectionfd, request, max_request);
	check_error(ret);
	printf("Data I got from client follows...\n");
	request[ret]=0;
	printf("%s", request);

	/* free the buffer for the request */
	free(request);
	
	/* handle the header part of the response */
	write_to_fd(connectionfd, response, strlen(response));

	/* find the size of the file */
	struct stat statbuf;
	check_error(stat(filename, &statbuf));
	int file_size=statbuf.st_size;
	
	/* write the html file */
	char* file_content = (char*)malloc(file_size);
	int fd = open(filename, O_RDONLY);
	check_error(fd);
	read_from_fd(fd, file_content, file_size);
	check_error(close(fd));
	write_to_fd(connectionfd, file_content, file_size);
	free(file_content);

	/* close the connection */
	check_error(close(connectionfd));
}

int main()
{

	/*socket create and verification */
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	check_error(sockfd);
	printf("Socket successfully created..\n");

	/* prepare address and bind */
	struct sockaddr_in servaddr, cli;
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(port);
	check_error(bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)));
	printf("Socket successfully binded..\n");

	/* Now server is ready to listen and verification */
	check_error(listen(sockfd, 5));
	printf("Server listening..\n");

	socklen_t len=sizeof(cli);
	while(1)
	{
		/*Accept the data packet from client and verification */
		int connfd = accept(sockfd, (struct sockaddr*)&cli, &len);
		check_error(connfd);
		printf("server acccept the client...\n");
		/* clientServerChattion for chatting between client and server */
		clientServerChat(connfd);
	}
	/* Shut down the entire server */
	close(sockfd);
	return EXIT_SUCCESS;
}

/*
1.epol_create -create epol file dsc.
2.epol_ctl - add more file descriptor to epol fd.
3. epoll_pwail - sleep until I can do i/o on 1 or more fd of epol.
epoll_wail
array of fd.
*/

/*what is file descriptor ? - allows user space to speak with kernel (straming of data)*/
