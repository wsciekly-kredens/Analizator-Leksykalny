#ifndef _STORE_H_IS_INCLUDED_
#define _STORE_H_IS_INCLUDED_

#include <stdio.h>

typedef struct store{
    char *fun;
    int ln;
    char *ipname;
    char *type; //typ pojawienia się
} *store; //struktura do przechowywania informacji i jednym konkretnym pojawieniu się funckcji

store *funkcje;

void store_add_def(char *fun, int ln, char *ipname);
void store_add_proto(char *fun, int ln, char *ipname);
void store_add_call(char *fun, int ln, char *ipname);

#endif