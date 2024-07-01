
%{
#include <stdio.h>
#include "lexer.h"
int yylex(void);
int yyerror(const char *s);
%}

%token INTEGER

%%
S: E { printf("Reduction: S -> E  Fin!!\n"); }
  ;

E: E '+' T { printf("Reduction: E -> E + T \n"); }
  | T {printf("Réduction E -> T \t\t $1=%d\t$$=%d\n",$1,$$); }
  ;

T: T '*' F { printf("Reduction: T -> T * F\n"); }
  | F   {printf("Réduction T -> F   \t\t $1=%d\t$$=%d\n",$1,$$); }
  ;

F: INTEGER { printf("Reduction: F -> int   \t\t $1=%d\t$$=%d\n",$1,$$); }

  ;
%%

int main() {
    yyparse();
    return 0;
}

int yyerror(const char *s) {
    printf("Erreur syntaxique: %s\n", s);
    return 0;
}
