#ifndef MQ_H
#define MQ_H

#define MQ_SEND_MSG 150
#define MQ_RECV_MSG 151

#pragma pack(push,1)
struct mqReg
{
    char* data;
    int size;
};
#pragma pack(pop)

#endif
