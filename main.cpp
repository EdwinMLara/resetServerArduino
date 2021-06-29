#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "requestBody.h"
#include "httpRequest.h"
#include "router.h"

#define EXAMPLE_REQUEST "GET / HTTP/1.1\nUser-Agent: Mozilla/4.0 (compatible; MSIE5.01; Windows NT)mm\nHost: www.tutorialspoint.com\nAccept-Language: en-us\nAccept-Encoding: gzip, deflate\nConnection: Keep-Alive\n"
#define EXAMPLE_REQUEST_POST "POST / HTTP/1.1\nUser-Agent: Mozilla/4.0 (compatible; MSIE5.01; Windows NT)mm\nHost: www.tutorialspoint.com\nAccept-Language: en-us\nAccept-Encoding: gzip, deflate\nConnection: Keep-Alive\n\n{'conf':'time','time':'min'}\n"

void tempo(RequestBody *data){
    printRequestBody(data);
    char response[] = "{'response':'iniciando Tempo'}\n";
    printf("%s",response);
}

void lamp(RequestBody* data){
    printRequestBody(data);
    char response[] = "{'response':'encendiendo las putas lamparas'}\n";
    printf("%s",response);
}

int main()
{
    Request req = getValuesRequest(const_cast<char*>(EXAMPLE_REQUEST));

    Router ro = createRouter(const_cast<char*>("/"));
    addPath(&ro,const_cast<char*>("POST"),const_cast<char*>("/tempo"),tempo);
    addPath(&ro,const_cast<char*>("POST"),const_cast<char*>("/lamp"),lamp);
    runRouter(&ro,&req);

    return 0;
}

