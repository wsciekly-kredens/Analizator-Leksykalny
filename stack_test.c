#include <stdio.h>
#include <stdlib.h>
#include "fun_stack.h"

int main(){
    char *slowa[4] = {"Ala","ma","kota","szyszka"};
    int liczby[4] = {3,2,4,10};
    for(int i= 0; i<=3;i++)
        put_on_fun_stack(liczby[i],slowa[i]);

    if(top->next->par_level == liczby[2])
        printf("Globalna zmienna top dziala poprawnie\n");
    else
        printf("Blad globalnelnej zmiennej top");
    for(int i = 3; i>=0;i--){
        if(get_from_fun_stack()==slowa[i])
            printf("Odczytano ze stosu poprawnie\n");
        else
            printf("Błąd stosu!\n");
    }
    printf("Wynik czytania z pustego stosu: %s\n",get_from_fun_stack());
    printf("Wynik czytania liczby z pustego stosu: %d\n",top_of_funstack());
}