#ifndef REQUESTBODY_H
#define REQUESTBODY_H
#include "item.h"

struct RequestBody{
    int cant;
    Item *data;
};

RequestBody* getBodyFromStr(const char*);
void printRequestBody(RequestBody*);
bool keyExist(RequestBody *b,char *key);

#endif // REQUESTBODY_H
