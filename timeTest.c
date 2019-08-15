#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "time.h"
int main()
{	int hour,minute,sec,format,day,month,year;
	cTime_t* ct;
	cTime_t* ct2;
	cDate_t* cd;
	cDate_t* cd2;
	ct=malloc(sizeof(cTime_t));
	ct2=malloc(sizeof(cTime_t));
	cd=malloc(sizeof(cDate_t));
	cd2=malloc(sizeof(cDate_t));
	printf("Enter hour\n");
	scanf("%d",&hour);
	printf("Enter minute\n");
	scanf("%d",&minute);
	printf("Enter sec\n");
	scanf("%d",&sec);
	updateT(ct,hour,minute,sec);
	printf("Enter format\n");
	scanf("%d",&format);
	printTime(ct,format);
	printf("hour=%d\n",getHour(ct));
	printf("minute=%d\n",getMinute(ct));
	printf("sec=%d\n",getSec(ct));
	

	printf("Enter hour2\n");
	scanf("%d",&hour);
	printf("Enter minute2\n");
	scanf("%d",&minute);
	printf("Enter sec2\n");
	scanf("%d",&sec);
	updateT(ct2,hour,minute,sec);
	addTime(ct,ct2);
	printTime(ct,format);
	

	printf("Enter day\n");
	scanf("%d",&day);
	printf("Enter month\n");
	scanf("%d",&month);
	printf("Enter year\n");
	scanf("%d",&year);
	updateD(cd,day,month,year);
	printf("Enter format\n");
	scanf("%d",&format);
	printDate(cd,format);
	printf("Year Day=%d\n",getYearDay(cd));
	printf("Leap Year=%d\n",leapYear(cd));
	printf("Month name=%s\n",getMonthName(cd));
	printf("Enter day\n");
	scanf("%d",&day);
	printf("Enter month\n");
	scanf("%d",&month);
	printf("Enter year\n");
	scanf("%d",&year);
	updateD(cd2,day,month,year);
	addDate(cd,cd2);
	printf("Enter format\n");
	scanf("%d",&format);

	printDate(cd,format);
	if(ct!=NULL)
		free(ct);
	if(ct2!=NULL)
		free(ct2);
	if(cd!=NULL)
		free(cd);
	if(cd2!=NULL)
		free(cd2);
return 0;	
}
