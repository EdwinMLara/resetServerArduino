#ifndef ITEM_H
#define ITEM_H
#include <stdio.h>

struct Item {
    char * key;
    char * value;
};

int numValues(const char *);

#endif // ITEM_H
