%{
#include "parser.tab.h"
%}

%%
[0-9]+      { yylval = atoi(yytext); return INTEGER; }
"+"         { return '+'; }
"*"         { return '*'; }
\n          { return '\n'; }
[ \t]       ;  // ignore spaces and tabs
.           { return yytext[0]; }
%%

int yywrap() {
    return 1;
}
