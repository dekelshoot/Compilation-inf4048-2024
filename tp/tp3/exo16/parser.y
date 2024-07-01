%{
#include <stdio.h>
#include "lexer.h"

int yylex(void);
int yyerror(const char *s);


int calculate(int left, char op, int right);

%}

%token INTEGER

%left '+' '-'
%left '*' '/'

%%

S: E { printf("Réduction: S -> E  Fin!!\n\nRésultat: %d\n\n",$$); }
  ;

E: E '+' T { $$ = calculate($1, '+', $3); printf("Réduction: E -> E + T\n"); }
  | T { $$ = $1; printf("Réduction: E -> T\t\t$1=%d\t$$=%d\n", $1, $$); }
  ;

T: T '*' F { $$ = calculate($1, '*', $3); printf("Réduction: T -> T * F\n"); }
  | F { $$ = $1; printf("Réduction: T -> F\t\t$1=%d\t$$=%d\n", $1, $$); }
  ;

F: INTEGER { $$ = $1; printf("Réduction: F -> int \t\t$1=%d\t$$=%d\n", $1, $$); }
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

/* Fonction pour calculer le résultat des opérations arithmétiques */
int calculate(int left, char op, int right) {
    switch (op) {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/': return left / right; 
        default: return 0; 
    }
}
