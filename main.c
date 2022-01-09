#include <stdio.h>              
#include <stdlib.h> // exit - ale exit trzeba kiedyś usunąć i nie będzie to potrzebne
#include "alex.h"       // analizator leksykalny                                     
#include "fun_stack.h" // stos funkcji
#include "store.h"
#include "analizatorSkladni.h"

int main(int argc, char **argv){
int k=1;
if(argv[1]==NULL)
  fprintf(stderr, "Blad - nie moge czytac pliku!\n");
while(argv[k]!=NULL)
 {analizatorSkladni (argv[k]);
  ++k;}

funkcje=malloc(sizeof(store));

int j=0;
while(funkcje[j]!=NULL)
{

printf("Funkcja:%s\n", funkcje[j]->fun);
printf("\tPrototyp:\n");
printf("\t\tplik %s od linia %d do linia %d\n", funkcje[j]->ipname, funkcje[j]->ln, funkcje[j]->ln);
printf("\tDefinicja:\n");
printf("\t\tplik %s od linia %d do linia %d\n", funkcje[j]->ipname, funkcje[j]->ln, funkcje[j]->ln);
printf("\tUzycie:\n");
printf("\t\tplik %s od linia %d do linia %d\n", funkcje[j]->ipname, funkcje[j]->ln, funkcje[j]->ln);
printf("\tWywoluje:\n");
printf("\t\tplik %s od linia %d do linia %d\n", funkcje[j]->ipname, funkcje[j]->ln, funkcje[j]->ln);

++j;
}
return 0;
}
