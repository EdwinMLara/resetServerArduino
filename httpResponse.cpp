#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "httpResponse.h"

Response* createResponseStruct(){
    static Response *r = static_cast<Response*>(malloc(sizeof (Response)));
    return r;
}
