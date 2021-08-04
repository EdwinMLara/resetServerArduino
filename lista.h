#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct nodeL {
    const char* key;
    const char* dato;
    struct nodeL *sig;
}nodeL;

void insertL(nodeL*&,const char*, const char*);
bool removeL(nodeL*&,const char*);
bool updateL(nodeL*&,const char*,const char*);
void showListL(nodeL*&);

#endif // LISTA_H
