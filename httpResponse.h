#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H
typedef union{
    int *a;
    bool b;
    char c;
    double d;
}Data;

struct Response{
    int cantData;
    Data *data;
};

Response* createResponseStruct();
#endif // HTTPRESPONSE_H
