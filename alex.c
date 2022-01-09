#include "alex.h"

#include <ctype.h>
#include <string.h>

static int  ln= 0;
static char ident[256];
static FILE *ci= NULL;

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

