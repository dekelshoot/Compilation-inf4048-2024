%{
#include <stdio.h>  // Inclusion de la bibliothèque standard d'entrée/sortie
#include <ctype.h>  // Inclusion de la bibliothèque de fonctions de classification de caractères


void yyerror(const char *s); // Déclaration de la fonction yyerror pour gérer les erreurs de syntaxe
%}

/* Un operateur est défini comme les caractères \+|\*|\-  */
operateur  \+|\*|\-

/* Un chiffre est défini comme un caractère entre '0' et '9' */
DIGIT      [0-9]  

/* Un entier à deux chiffres est défini comme deux chiffres consécutifs */
INTEGER    {DIGIT}{DIGIT} 

%%

{INTEGER}          { printf("<int:%s>", yytext); }
{operateur}          { printf("<operateur:%s>", yytext); }
[ \t\n\r]          { /* Ignore whitespace */ }
.                  { yyerror("parse error"); }

%%

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <expression>\n", argv[0]);
        return 1;
    }

    yy_scan_string(argv[1]);
    yylex();
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
}
