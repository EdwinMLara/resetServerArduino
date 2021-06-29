#include <stdlib.h>
#include <string.h>
#include "item.h"

int numValues(const char *strbody){
    int count = 0,i=0;
    while(strbody[i] != '\0'){
        if(strbody[i] == ':')
            count++;
        i++;
    }
    return count;
}

