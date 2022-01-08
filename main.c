#include <stdio.h>              
#include <stdlib.h> // exit - ale exit trzeba kiedyś usunąć i nie będzie to potrzebne
#include "alex.h"       // analizator leksykalny                                     
#include "fun_stack.h" // stos funkcji
#include "store.h"
#include "analizatorSkladni.h"

int main(int argc, char **argv){
int i=1;
if(argv[1]==NULL)
  fprintf(stderr, "Blad - nie moge czytac pliku!\n");
while(argv[i]!=NULL)
 {analizatorSkladni (argv[i]);
  ++i;}

funkcje=malloc(sizeof(store));

int i=0;
while(*funkcje[i]!=NULL)
{

printf("Funkcja:%s\n", funkcje[i]->fun);
printf("\tPrototyp:\n");
printf("\t\tplik od linia %d do linia %d\n", funkcje[i]->ln, funkcje[i]->ln);
printf("\tDefinicja:\n");
printf("\t\tplik od linia do linia\n");
printf("\tUzycie:\n");
printf("\t\tplik od linia do linia\n");
printf("\tWywoluje:\n");
printf("\t\tplik od linia do linia\n");

++i;
}
return 0;
}