%{
#include<stdio.h>
#include "simple.h"
%}

entier [0-9]+

lparen \(
rparen \)
double_mark \:
point_virgule \;
variable [a-d]

%%
{entier} { yylval=atoi(yytext);return INTEGER;}
{point_virgule} {return SEMI;}
{lparen} {return LPAREN;}
{rparen} {return RPAREN;}
{double_mark} {return DOUBLEMARK;}
{variable}  {yylval=*yytext; return VARIABLE;}
akok_lo {return AKOK_LO;}
anoan {return ANOAN;}
a_pouli {return A_POULI;}
a_vah {return AVAH;}
asseulen {return ASSEULEN;}
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
switch {return SWITCH;}
case {return CASE;}
fincase {return FINCASE;}
break { return BREAK;}
endswitch {return ENDSWITCH;}
[\n] ;
[ ] ;
[\t] ;
. { printf("parse error (lex) + %s -\n",yytext); }

%%

