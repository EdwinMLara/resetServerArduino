#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H
#include <tgmath.h>
#include <stdio.h>
#include "lista.h"

typedef union{
    int *a;
    bool *b;
    unsigned long *c;
}Data;

struct Response{
    int cantData;
    nodeL *responseResults;
    Data *data;
};

Response* createResponseStruct(int);
char* response2Str(Response*);

#endif // HTTPRESPONSE_H
