#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "requestBody.h"
#include "item.h"

RequestBody* getBodyFromStr(const char*strbody){
    size_t  i=0,countFlag=0;
    size_t flag[4]={0,0,0,0};
    int cant = numValues(strbody);
    Item *items = static_cast<Item*>(malloc(cant*sizeof (Item)));
    int loadItem = 0;
    while(strbody[i] != '\0'){
        if(strbody[i] == '\''){
            flag[countFlag] = i;
            countFlag++;
        }

        if(countFlag == 4){
            size_t difKey = (flag[1]-flag[0])-1;
            size_t difValue = (flag[3]-flag[2])-1;

            char *auxKey = static_cast<char*>(malloc(difKey*sizeof (char)));
            char *auxValue = static_cast<char*>(malloc(difValue*sizeof (char)));

            memcpy(auxKey,&strbody[flag[0]+1],difKey);
            memcpy(auxValue,&strbody[flag[2]+1],difValue);
            auxKey[difKey] = '\0';
            items[loadItem].key = auxKey;
            auxValue[difValue] = '\0';
            items[loadItem].value = auxValue;

            countFlag = 0;
            loadItem++;
        }
        i++;
    }

    static RequestBody *b = static_cast<RequestBody*>(malloc(sizeof (RequestBody)));
    b->cant = cant;
    b->data = items;
    return  b;
}

void printRequestBody(RequestBody *body){
    if(body != nullptr){
        for(int i=0;i<body->cant;i++){
            printf("%s,%s\n",body->data[i].key,body->data[i].value);
        }
    }
}

bool keyExist(RequestBody *b,const char key[]){
    char *ptrKey = const_cast<char*>(key);
    for(int i=0;i<b->cant;i++){
        if(strcmp(b->data[i].key,ptrKey) == 0){
            return true;
        }
    }
    return false;
}

const char* getKeyValue(RequestBody *b,const char *key){
    char *ptrKey = const_cast<char*>(key);
    for(int i=0;i<b->cant;i++){
        if(strcmp(b->data[i].key,ptrKey) == 0){
            return b->data[i].value;
        }
    }
    return "error";
}
