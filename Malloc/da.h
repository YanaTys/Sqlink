#ifndef DA_T1
#define DA_T1
typedef struct {
int index;
int cap;
int* ip;
} DA_T;

DA_T* createDA(int cap);
int insert(DA_T* daptr,int num);
void printDA(DA_T*);
void destroyDA(DA_T*);

#endif
