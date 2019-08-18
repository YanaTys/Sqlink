#ifndef BITM_T
#define BITM_T
typedef struct 
{
unsigned int right :4;
unsigned int left :4;
}LRChar;

typedef union 
{  LRChar lr;
  unsigned char c;
}un;
void ItoB( unsigned int num);
int transTo4Bits( char* chArr);
int transTo4Bits2( char* chArr);

#endif
