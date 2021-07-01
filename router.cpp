#include <stdlib.h>
#include <string.h>
#include "router.h"
#include "httpRequest.h"
#include "httpResponse.h"
#include "item.h"
#include "requestBody.h"

void froot(RequestBody *data,Response *g){
    printRequestBody(data);
    if(g!=nullptr){
        printf("crear Response\n");
    }
    char response[] = "{'response':'200'}\n";
    printf("%s",response);
}

Path createPath(char *method,char *newpath,void (*f)(RequestBody *,Response *)){
 Path r;
 r.method = method;
 r.Path = newpath;
 r.callback = f;
 return r;
}

Router createRouter(char* root){
    Router ro;
    ro.numPaths = 1;
    Path r = createPath(const_cast<char*>("GET"),root,froot);
    ro.paths = static_cast<Path*>(malloc(sizeof (Path)));
    ro.paths[0] = r;
    return ro;
}

void addPath(Router *ro,char *method,char *newpath,void (*f)(RequestBody *,Response *)){
    ro->numPaths++;
    ro->paths = static_cast<Path*>(realloc(ro->paths,ro->numPaths*sizeof(Path)));
    Path r = createPath(method,newpath,f);
    ro->paths[(ro->numPaths)-1] = r;
}

void runRouter(Router *ro,Request *req,Response *g){
    bool bandera = false;
    size_t nPaths = ro->numPaths;
    for(size_t i=0;i<nPaths;i++){
        if(strcmp(ro->paths[i].Path,req->path) == 0){
            if(strcmp(req->method,"GET") == 0){
                (ro->paths[i].callback)(nullptr,nullptr);
            }else{
                (ro->paths[i].callback)(req->body,g);
            }
            bandera = true;
            break;
        }
    }
    if(!bandera){
        printf("UnKnown Endpoint\n");
    }
}
