%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"  // Inclut le fichier de définition des tokens généré par Bison
%}

%%
[a-zA-Z][a-zA-Z0-9]*   { yylval.sval = strdup(yytext); return ID; }
[0-9]+                 { yylval.ival = atoi(yytext); return INT; }
"+"                    { return PLUS; }
"*"                    { return TIMES; }
"="                    { return ASSIGN; }
";"                    { return SEMI; }
"=="                   { yylval.ival = 1; return EQ; }
"!="                   { yylval.ival = 0; return NE; }
"<"                    { yylval.ival = 0; return LT; }
">"                    { yylval.ival = 1; return GT; }
"("                    { return LPAREN; }
")"                    { return RPAREN; }
"if"                   { return IF; }
"then"                 { return THEN; }
"fi"                   { return FI; }
"while"                { return WHILE; }
"do"                   { return DO; }
"endwhile"             { return ENDWHILE; }
[ \t\n]                ;  // Ignorer les espaces, tabulations et sauts de ligne
.                      { fprintf(stderr, "Caractère non reconnu: %s\n", yytext); exit(1); }
%%

int yywrap() {
    return 1;
}
