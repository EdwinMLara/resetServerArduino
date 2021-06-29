#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "httpRequest.h"
#include "requestBody.h"

char* getMethod(char *request){
    if(strstr(request,"GET") != nullptr || strstr(request,"get") != nullptr)
        return const_cast<char*>("GET");
    if(strstr(request,"POST") != nullptr || strstr(request,"post") != nullptr)
        return const_cast<char*>("POST");
    if(strstr(request,"PUT") != nullptr || strstr(request,"put") != nullptr)
        return const_cast<char*>("PUT");
    if(strstr(request,"DELETE") != nullptr || strstr(request,"delete") != nullptr)
        return const_cast<char*>("DELETE");
    return const_cast<char*>("error");
}

char* getPath(char *request){
    int i=0,count=0;
    int positions[2] = {0,0};

    while(request[i] != '\0'){
        if(request[i] == ' '){
            positions[count] = i;
            count++;
        }
        if(count ==  2){
            break;
        }
        i++;
    }
    size_t difPath = (positions[1]-positions[0])-1;
    char *auxPath = static_cast<char*>(malloc(difPath*sizeof (char)));
    memcpy(auxPath,&request[positions[0]+1],difPath);
    auxPath[difPath] = '\0';

    return auxPath;
}


int* getBodyIndexPositions(char *request){
  static int positions[2] = {0,0};
  int i=0;
  while(request[i] != '\0'){
      switch(request[i]){
        case '{':
          positions[0] = i;
          break;
        case '}':
          positions[1] = i;
          break;
     }
    i++;
  }
  return positions;
}

char* getBody(char *request){
    int *pos = getBodyIndexPositions(request);
    int bodyLength = (pos[1] - pos[0]) + 3;
    char *body = static_cast<char*>(malloc(bodyLength*sizeof (char)));
    memcpy(body,&request[pos[0]],bodyLength);
    return body;
}

Request getValuesRequest(char *request){
    Request req;
    req.method = getMethod(request);
    if(strcmp(req.method,"GET") == 0){
        req.body = nullptr;
    }else{
        req.body = getBodyFromStr(getBody(request));
    }
    req.path = getPath(request);
    return req;
}
