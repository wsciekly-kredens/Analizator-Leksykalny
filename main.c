#include <stdio.h>              
#include <stdlib.h> // exit - ale exit trzeba kiedyś usunąć i nie będzie to potrzebne
#include "alex.h"       // analizator leksykalny                                     
#include "fun_stack.h" // stos funkcji

int main(int argc, char **argv){
int i=1;
if(*argv[1]==NULL)
  fprintf(stderr, "Blad - nie moge czytac pliku!\n");
while(*argv[i]!=NULL)
 {analizatorSkladni (*argv[i]);
  ++i;}


return 0;
}