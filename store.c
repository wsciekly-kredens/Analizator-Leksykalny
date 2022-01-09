#include <stdlib.h>
#include "store.h"

static int i = 0;

void store_add_def(char *fun, int ln, char *ipname){
    store funkcja;
    funkcja->fun = fun;
    funkcja->ln = ln;
    funkcja->ipname = ipname;
    funkcja->type = "def";
    funkcje[i] = funkcja;
    i++;
}
void store_add_proto(char *fun, int ln, char *ipname){
    store funkcja;
    funkcja->fun = fun;
    funkcja->ln = ln;
    funkcja->ipname = ipname;
    funkcja->type = "proto";
    funkcje[i] = funkcja;
    i++;
}
void store_add_call(char *fun, int ln, char *ipname){
    store funkcja;
    funkcja->fun = fun;
    funkcja->ln = ln;
    funkcja->ipname = ipname;
    funkcja->type = "call";
    funkcje[i] = funkcja;
    i++;
}