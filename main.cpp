#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "requestBody.h"
#include "httpRequest.h"
#include "router.h"
#include "httpResponse.h"
#include "lista.h"

#define EXAMPLE_REQUEST "GET / HTTP/1.1\nUser-  "
": Mozilla/4.0 (compatible; MSIE5.01; Windows NT)mm\nHost: www.tutorialspoint.com\nAccept-Language: en-us\nAccept-Encoding: gzip, deflate\nConnection: Keep-Alive\n"
#define EXAMPLE_REQUEST_TEMPO "POST /tempo HTTP/1.1\nUser-Agent: Mozilla/4.0 (compatible; MSIE5.01; Windows NT)mm\nHost: www.tutorialspoint.com\nAccept-Language: en-us\nAccept-Encoding: gzip, deflate\nConnection: Keep-Alive\n\n{'conf':'tempo','status':'on','time':'min','ciclo':'1451'}\n"
#define EXAMPLE_REQUEST_LAMP "POST /lamp HTTP/1.1\nUser-Agent: Mozilla/4.0 (compatible; MSIE5.01; Windows NT)mm\nHost: www.tutorialspoint.com\nAccept-Language: en-us\nAccept-Encoding: gzip, deflate\nConnection: Keep-Alive\n\n{'conf':'lamp','l1':'on'}\n"

void configuracionTiempo(const char * conf,Response *res){
    int multiplicador = 0;
    if(strcmp(conf,"min") == 0){
        //printf("configurando en minutos\n");
        multiplicador = 60;
    }
    if(strcmp(conf,"hr") == 0){
        //printf("configurando a horas\n");
        multiplicador = 3600;
    }
    for(int i=0;i<4;i++){
       char aux[2];
       aux[0] = conf[i];
       aux[1] = '\0';
       res->data[2].c[i] = atoi(aux)*multiplicador;
    }
}

void tempo(RequestBody *data,Response *res){
    if(keyExist(data,"conf")){
        const char *confTime = getKeyValue(data,"time");
        configuracionTiempo(confTime,res);
        *res->data[3].b = true;
    }
}

void lamp(RequestBody* data,Response *res){
    if(keyExist(data,"conf")){
        printf("%s\n",getKeyValue(data,"l1"));
        printf("%d\n",*res->data[1].b);
        *res->data[1].b = true;
     }
    char response[] = "{'response':'encendiendo las putas lamparas'}\n";
    printf("%s",response);
}

int main()
{
    Response *res = createResponseStruct(4);
    Data d[4];
    int rele[2] = {1,2};
    unsigned long confTempo[4] = {0,0,0,0};
    bool generalStatus = false;
    bool statusTempo = false;
    d[0].a = rele;
    d[1].b = &generalStatus;
    d[2].c = confTempo;
    d[3].b = &statusTempo;

    nodeL *responseResults = nullptr;
    insertL(responseResults,"Overall_state","false");
    insertL(responseResults,"Tempo_state","false");

    res->responseResults = responseResults;

    res->data = d;

    Router ro = createRouter(const_cast<char*>("/"));
    addPath(&ro,const_cast<char*>("POST"),const_cast<char*>("/tempo"),tempo);
    addPath(&ro,const_cast<char*>("POST"),const_cast<char*>("/lamp"),lamp);

    /**En arduino hay que liberar la memorira ya que cambia continuamente por cada peticion*/
    Request req = getValuesRequest(const_cast<char*>(EXAMPLE_REQUEST_TEMPO));

    runRouter(&ro,&req,res);
    char *strResponse = response2Str(res);
    printf("%s",strResponse);



    return 0;
}

