#ifndef DA_T1
#define DA_T1
typedef struct Calendar_t Calendar_t1;
typedef struct {
float begin;
float end;
int room;
} Meeting_t;
struct Calendar_t{
Meeting_t ** day;
int cap;
int index;
};


Calendar_t1* createAD(int cap);
Meeting_t* CreateMeeting();
int insert(Calendar_t1*,Meeting_t*);
int Remove(Calendar_t1*,float);
Meeting_t* find(Calendar_t1*,float);
void printAD(Calendar_t1*);
void destroyAD(Calendar_t1*);

#endif
