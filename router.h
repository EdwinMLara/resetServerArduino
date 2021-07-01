#ifndef ROUTER_H
#define ROUTER_H
#include <stdio.h>
#include "httpRequest.h"
#include "httpResponse.h"
#include "requestBody.h"

typedef struct Path{
    char *method;
    char *Path;
    void (*callback)(RequestBody*,Response *);
}Path;

struct Router{
    size_t numPaths;
    Path *paths;
};

Path createPath(char *,char *,char *,void (*f)(RequestBody*,Response *));
Router createRouter(char*);
void addPath(Router *,char *,char *,void (*f)(RequestBody*,Response *));
void runRouter(Router*,Request*,Response *);

#endif // ROUTER_H
