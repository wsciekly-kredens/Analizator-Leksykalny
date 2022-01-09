#include <stdio.h>
#include <stdlib.h>
#include "fun_stack.h"

funstack top;

int top_of_funstack( void ){
    if(top == NULL){
        return 1;
    }
    else{
        return top->par_level;
    }
}

void put_on_fun_stack( int par_level, char *funame ){
    if(top == NULL){
        printf("%d\n",top);
        top = malloc(sizeof(top));
        top->par_level = par_level;
        top->funame = funame;
        top->next = NULL;
        printf("%d\n",top);
        printf("%s\n",top->funame);
    }
    else{
        printf("okazuje się że stos nie jest pusty");
        funstack newElem;
        newElem = malloc(sizeof(newElem));
        newElem->par_level = par_level;
        newElem->funame = funame;
        newElem->next = top;
        top = newElem;
    }
}

char *get_from_fun_stack( void ){
    if(top == NULL){
        printf("Stos jest pusty!");
        return "blad";
    }
    else{
        char *tmp = top->funame;
        funstack tmp2;
        tmp2 = top->next;
        free(top);
        top = tmp2;
        printf("to funkcja z gory stosu %s\n",tmp);
        return tmp;
    }
}
