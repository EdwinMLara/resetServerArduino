#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "requestBody.h"
#include "httpRequest.h"
#include "router.h"
#include "httpResponse.h"

#define EXAMPLE_REQUEST "GET / HTTP/1.1\nUser-Agent: Mozilla/4.0 (compatible; MSIE5.01; Windows NT)mm\nHost: www.tutorialspoint.com\nAccept-Language: en-us\nAccept-Encoding: gzip, deflate\nConnection: Keep-Alive\n"
#define EXAMPLE_REQUEST_TEMPO "POST /tempo HTTP/1.1\nUser-Agent: Mozilla/4.0 (compatible; MSIE5.01; Windows NT)mm\nHost: www.tutorialspoint.com\nAccept-Language: en-us\nAccept-Encoding: gzip, deflate\nConnection: Keep-Alive\n\n{'conf':'time','time':'1432'}\n"
#define EXAMPLE_REQUEST_LAMP "POST /lamp HTTP/1.1\nUser-Agent: Mozilla/4.0 (compatible; MSIE5.01; Windows NT)mm\nHost: www.tutorialspoint.com\nAccept-Language: en-us\nAccept-Encoding: gzip, deflate\nConnection: Keep-Alive\n\n{'conf':'lamp','l1':'on'}\n"

void tempo(RequestBody *data,Response *res){
    if(keyExist(data,"conf")){
        printf("%s\n",getKeyValue(data,"time"));
        printf("Configurando Tempo\n");
        res->data[3].b = true;
    }
    char response[] = "{'response':'iniciando Tempo'}\n";
    printf("%s",response);
}

void lamp(RequestBody* data,Response *res){
    if(keyExist(data,"conf")){
        printf("%s\n",getKeyValue(data,"l1"));
        printf("%d\n",res->data[1].b);
        res->data[1].b = true;
     }
    char response[] = "{'response':'encendiendo las putas lamparas'}\n";
    printf("%s",response);
}

int main()
{
    Response *res = createResponseStruct();
    res->cantData = 4;
    Data d[4];
    int rele[2] = {1,2};
    int confTempo[4] = {1,3,4,2};
    bool generalStatus = false;
    bool statusTempo = false;
    d[0].a = rele;
    d[1].b = generalStatus;
    d[2].a = confTempo;
    d[3].b = statusTempo;

    res->data = d;

    Request req = getValuesRequest(const_cast<char*>(EXAMPLE_REQUEST_TEMPO));

    Router ro = createRouter(const_cast<char*>("/"));
    addPath(&ro,const_cast<char*>("POST"),const_cast<char*>("/tempo"),tempo);
    addPath(&ro,const_cast<char*>("POST"),const_cast<char*>("/lamp"),lamp);
    runRouter(&ro,&req,res);

    return 0;
}

