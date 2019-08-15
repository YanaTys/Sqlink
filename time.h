#ifndef DA_T1
#define DA_T1

typedef struct {
int hour;
int minute;
int sec;
} cTime_t;


typedef struct {
int day;
int month;
int year;
} cDate_t;


cTime_t* updateT(cTime_t*,int,int,int);
void printTime(cTime_t*,int );
int getHour(cTime_t*);
int getMinute(cTime_t*);
int getSec(cTime_t*);
cTime_t* addTime(cTime_t*,cTime_t*);




cDate_t* updateD(cDate_t*,int,int,int);
void printDate(cDate_t*,int );
int getDay(cDate_t*);
int getMonth(cDate_t*);
int getYear(cDate_t*);
int getYearDay(cDate_t*);
int leapYear(cDate_t*);
char* getMonthName(cDate_t*);
cDate_t* addDate(cDate_t*,cDate_t*);

#endif
