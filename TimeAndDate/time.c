#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "time.h"
static char monArr[12][128]={"January","February" ,"March" ,"April" ,"May","June","July","August","September","October","November","December"};
static int daysInM [12]={31,28,31,30,31,30,31,31,30,31,30,31};
cTime_t* updateT(cTime_t* ct,int hour,int minute,int sec)
{
	ct->hour=hour;
	ct->minute=minute;
	ct->sec=sec;
	return ct; 
}

void printTime(cTime_t* ct,int format )
{	
	if(format==1)
		printf("%d:%d:%d\n",ct->hour,ct->minute,ct->sec);
	if(format==2)
		printf("%d:%d:%d %s\n",(ct->hour)%12,ct->minute,ct->sec,ct->hour>=12?"PM":"AM");
	return;
}

int getHour(cTime_t* ct)
{
	return ct->hour;
}
int getMinute(cTime_t* ct)
{
	return ct->minute;
}
int getSec(cTime_t* ct)
{
	return ct->sec;
}

cTime_t* addTime(cTime_t* ct1,cTime_t* ct2)

{	int secF,minuteF;
	secF=(ct1->sec+ct2->sec)/60;
	minuteF=(ct1->minute+ct2->minute+secF)/60;
	ct1->sec=(ct1->sec+ct2->sec)%60;
	ct1->minute=(ct1->minute+ct2->minute+secF)%60;
	ct1->hour=(ct1->hour+ct2->hour+minuteF)%24;
return ct1;
}
cDate_t* updateD(cDate_t* cd,int day,int month,int year)
{
	cd->day=day;
	cd->month=month;
	cd->year=year;
	return cd; 
}

void printDate(cDate_t* cd,int format )
{	
	if(format==1)
		printf("%d,%d,%d\n",cd->day,cd->month,cd->year);
	if(format==2)
		printf("%d,%d,%d\n",cd->month,cd->day,cd->year);
	if(format==3)
		printf("%d,%s,%d\n",cd->day,monArr[(cd->month)-1],cd->year);
	return;
}

int getDay(cDate_t* cd)
{
	return cd->day;
}
int getMonth(cDate_t* cd)
{
	return cd->month;
}
int getYear(cDate_t* cd)
{
	return cd->year;
}
int getYearDay(cDate_t* cd)
{ int sumDays=0,i=0;
	for(i=0;i<(cd->month)-1;i++)
		sumDays+=daysInM[i];
	sumDays+=cd->day;
	if(leapYear(cd)==1&&cd->month>2)
		sumDays++;
	return sumDays;
}
int leapYear(cDate_t* cd)
{
	if((cd->year)%4==0)
		return 1;
	return 0;
}
char* getMonthName(cDate_t* cd)
{
	return monArr[(cd->month)-1];
}
cDate_t* addDate(cDate_t* cd1,cDate_t* cd2)
{
	int dayF,monthF;
	dayF=(cd1->day+cd2->day)>daysInM[(cd1->month)-1]?1:0;
	monthF=(cd1->month+dayF)/12;
	cd1->day=(cd1->day+cd2->day)%(daysInM[(cd1->month)-1]);
	cd1->month=(cd1->month+dayF)%12;
	cd1->year=(cd1->year+monthF);
}







