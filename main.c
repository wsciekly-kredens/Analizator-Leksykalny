#include <stdio.h>              
#include <stdlib.h> // exit - ale exit trzeba kiedyś usunąć i nie będzie to potrzebne
#include "alex.h"       // analizator leksykalny                                     
#include "fun_stack.h" // stos funkcji
#include <ctype.h>
#include <string.h>

static int  ln= 0;
static char ident[256];
static FILE *ci= NULL;


typedef struct store{
    char *fun;
    int ln;
    char *ipname;
    char *type; //typ pojawienia się
} *store; //struktura do przechowywania informacji i jednym konkretnym pojawieniu się funckcji

store *funkcje;

void    alex_init4file( FILE *in ) {
   ln= 0;
   ci= in;
}

int  isKeyword(char* str)
{
    if (!strcmp(str, "auto") || !strcmp(str, "default") 
        || !strcmp(str, "signed") || !strcmp(str, "enum") 
        ||!strcmp(str, "extern") || !strcmp(str, "for") 
        || !strcmp(str, "register") || !strcmp(str, "if") 
        || !strcmp(str, "else")  || !strcmp(str, "int")
        || !strcmp(str, "while") || !strcmp(str, "do")
        || !strcmp(str, "break") || !strcmp(str, "continue") 
        || !strcmp(str, "double") || !strcmp(str, "float")
        || !strcmp(str, "return") || !strcmp(str, "char")
        || !strcmp(str, "case") || !strcmp(str, "const")
        || !strcmp(str, "sizeof") || !strcmp(str, "long")
        || !strcmp(str, "short") || !strcmp(str, "typedef")
        || !strcmp(str, "switch") || !strcmp(str, "unsigned")
        || !strcmp(str, "void") || !strcmp(str, "static")
        || !strcmp(str, "struct") || !strcmp(str, "goto")
        || !strcmp(str, "union") || !strcmp(str, "volatile"))
        return 1;
    return 0;
}
lexem_t alex_nextLexem( void ) {
  int c;
  while( (c= fgetc(ci)) != EOF ) {
    if( isspace( c ) )
      continue;
    else if( c == '\n' )
      ln++;
    else if( c == '(' )
      return OPEPAR;
    else if( c == ')' )
      return CLOPAR;
    else if( c == '{' )
      return OPEBRA;
    else if( c == '}' )
      return CLOBRA;
    else if( isalpha( c ) ) {    
        int i= 1;
      ident[0] = c;
      while( isalnum( c= fgetc(ci) ) || c == '_')
        ident[i++] = c;
      ident[i] = '\0';
      return isKeyword(ident) ? OTHER : IDENT;
    } 
    else if( c == '"' ) {
      /* Uwaga: tu trzeba jeszcze poprawic obsluge nowej linii w trakcie napisu
         i \\ w napisie 
      */
      while( (c= fgetc(ci)) != EOF && c != '"'  ) 
      return c==EOF ? EOFILE : OTHER; 
    } 
    else if( c == '/' ) {
      /* moze byc komentarz */
      while((c = fgetc(ci)) != EOF && c != '/')
      return c==EOF ? EOFILE : OTHER; 
    } 
    if( isdigit( c ) || c == '.' ) {
      /* liczba */
      while((c = fgetc(ci)) != EOF &&(isdigit( c ) || c == '.'))
      return c==EOF ? EOFILE : OTHER; 
    } 
    else {
      return OTHER;
    }
  }       
  return EOFILE;
}

char *  alex_ident( void ) {
   return ident;
}

int     alex_getLN() {
        return ln;
}                                           

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
if (funkcje[j]->type=="proto")
{printf("\tPrototyp:\n");
printf("\t\tplik %s linia %d\n", funkcje[j]->ipname, funkcje[j]->ln);}
if (funkcje[j]->type=="def")
{printf("\tDefinicja:\n");
printf("\t\tplik %s linia %d\n", funkcje[j]->ipname, funkcje[j]->ln);}
if (funkcje[j]->type=="call")
{"printf("\tUzycie:\n");
printf("\t\tplik %s linia %d\n", funkcje[j]->ipname, funkcje[j]->ln);}


++j;
}
return 0;

}
