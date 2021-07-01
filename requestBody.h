#ifndef REQUESTBODY_H
#define REQUESTBODY_H
#include "item.h"

struct RequestBody{
    int cant;
    Item *data;
};

RequestBody* getBodyFromStr(const char*);
void printRequestBody(RequestBody*);
bool keyExist(RequestBody *,const char key[]);
const char* getKeyValue(RequestBody *,const char*);

#endif // REQUESTBODY_H
