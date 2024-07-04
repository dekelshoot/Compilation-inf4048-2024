%{
#include<stdio.h>
#include "simple.h"
%}

entier [0-9]+
addition \+
multiplication \*
lparen \(
rparen \)
egal \=
point_virgule \;
egal_egal \=\=
non_egal \!\=
inferieur \<
superieur \>
variable [a-d]

%%
{entier} { yylval=atoi(yytext);return INTEGER;}
{addition} {return ADD;}
{multiplication} {return MUL;}
{egal} {return EQUAL;}
{point_virgule} {return SEMI;}
{egal_egal} {return EQEQ;}
{non_egal} {return NEQ;}
{inferieur} {return LT;}
{superieur} {return GT;}
{lparen} {return LPAREN;}
{rparen} {return RPAREN;}
{variable}  {yylval=*yytext; return VARIABLE;}
print {return PRINT;}
if {return SI;}
then {return ALORS;}
else {return SINON;}
fi {return FSI;}
read {return READ;}
while {return WHILE;}
do {return DO;}
done {return DONE;}
for {return FOR;}
to {return TO;}
step {return STEP;}
endfor {return ENDFOR;}
[\n] ;
[ ] ;
[\t] ;
. { printf("parse error (lex) + %s -\n",yytext); }

%%

