%{
#include<stdio.h>
#include "simple.h"
%}

entier [0-9]+
multiplication \*
lparen \(
rparen \)

point_virgule \;
non_egal \!\=
variable [a-d]

%%
{entier} { yylval=atoi(yytext);return INTEGER;}
{multiplication} {return MUL;}
{point_virgule} {return SEMI;}
{non_egal} {return NEQ;}
{lparen} {return LPAREN;}
{rparen} {return RPAREN;}
{variable}  {yylval=*yytext; return VARIABLE;}
akok_lo {return AKOK_LO;}
anoan {return ANOAN;}
dzam_deuh {return DZAM_DEUH;}
abah {return ABAH;}
aboite {return ABOITE;}
abui {return ABUI;}
nge {return NGE;}
ndo {return NDO;}
nde_ya {return NDEYA;}
aman_nge {return AMANNGE;}
lan {return LAN;}
ntie_te {return NTIETE;}
bo {return BO;}
aman {return AMAN;}
asu {return ASU;}
ya {return YA;}
itie {return ITIE;}
aman_asu {return AMANASU;}
[\n] ;
[ ] ;
[\t] ;
. { printf("parse error (lex) + %s -\n",yytext); }

%%

