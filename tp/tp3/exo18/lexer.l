%{
#include "parser.tab.h"
#include <stdlib.h>
#include <string.h>
void yyerror(const char *s);
%}

%%

"print"         { return PRINT; }
[0-9]+          { yylval.ival = atoi(yytext); return INT; }
[a-zA-Z][a-zA-Z0-9]* { yylval.sval = strdup(yytext); return ID; }
"="             { return ASSIGN; }
";"             { return SEMI; }
"+"             { return PLUS; }
"*"             { return TIMES; }
[ \t\n]         { /* Ignore whitespace */ }
.               { yyerror("Unknown character"); }

%%

int yywrap() {
    return 1;
}
