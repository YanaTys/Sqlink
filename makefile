 

CFLAGS= -ansi -pedantic -g 

prog : md5.o findDup.o fileOps.o hashTable.o init.o 
	gcc -o prog md5.o findDup.o  fileOps.o  hashTable.o  init.o -lcrypto
md5.o : md5.c md5.h
	gcc -c $(CFLAGS) md5.c
findDup.o : findDup.c findDup.h  fileOps.h  hashTable.h md5.h init.h
	gcc -c $(CFLAGS)  findDup.c
fileOps.o : fileOps.c fileOps.h 
	gcc -c $(CFLAGS)  fileOps.c 
hashTable.o : hashTable.c hashTable.h  
	gcc -c $(CFLAGS) hashTable.c	
init.o : init.c init.h hashTable.h fileOps.h
	gcc -c $(CFLAGS) init.c	

