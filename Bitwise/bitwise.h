#ifndef BITM_T
#define BITM_T
typedef struct {
int m_nf;
unsigned int* m_bitArr;
} bitMap_t;

typedef int (*bitsFunc)(bitMap_t*,int) ;

bitMap_t* createBitMap(int nf);
int bitOn(bitMap_t*,int);
int bitOff(bitMap_t*,int);
int bitStatus(bitMap_t*,int);
void printBitMap(bitMap_t*);
void destroyBitMap(bitMap_t*);

#endif
