#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H
#include "requestBody.h"

struct Request{
    char *method;
    char *path;
    RequestBody *body;
};

char* getMethod(char *);
char* getPath(char *);
int* getBodyIndexPositions(char *);
char* getBody(char *);
Request getValuesRequest(char *);

#endif // HTTPREQUEST_H
