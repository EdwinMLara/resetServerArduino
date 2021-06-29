#ifndef ROUTER_H
#define ROUTER_H
#include <stdio.h>
#include "httpRequest.h"
#include "requestBody.h"

typedef struct Path{
    char *method;
    char *Path;
    void (*callback)(RequestBody*);
}Path;

struct Router{
    size_t numPaths;
    Path *paths;
};

Path createPath(char *,char *,char *,void (*f)(RequestBody*));
Router createRouter(char*);
void addPath(Router *,char *,char *,void (*f)(RequestBody*));
void runRouter(Router*,Request*);

#endif // ROUTER_H
