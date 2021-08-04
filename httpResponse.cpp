#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "httpResponse.h"

Response* createResponseStruct(int cantData){
    static Response *r = static_cast<Response*>(malloc(sizeof (Response)));
    r->cantData = cantData;
    r->responseResults = nullptr;
    r->data = static_cast<Data *>(malloc(cantData*sizeof(Data)));
    for(size_t i=0;i<static_cast<size_t>(cantData);i++){
        r->data[i].a = nullptr;
        r->data[i].b = nullptr;
     }
    return r;
}

char* response2Str(Response* res){
    static char *strResponse = static_cast<char*>(malloc(100*sizeof(char)));
    strcpy(strResponse,"HTTP/1.1 200 OK\n{");
    nodeL *auxLabels = res->responseResults;
    while(auxLabels != nullptr){
        strcat(strResponse,"'");
        strcat(strResponse,auxLabels->key);
        strcat(strResponse,"',");
        strcat(strResponse,auxLabels->dato);
        if(auxLabels->sig != nullptr)
            strcat(strResponse,",");
        auxLabels = auxLabels->sig;
    }
    strcat(strResponse,"}\n");
    return strResponse;
}
