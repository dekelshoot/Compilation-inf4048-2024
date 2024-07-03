if = nge
finsi = aman_nge
do = bo
done = aman
for = asu
step = itie
to = ya
endfor = aman_asu

"+" = akok_lo
= = anoan
== = Dzam_deuh  
 != = asseulen
">" = abui
< = Aboite
while = ntie_te
else = nde_ya
then = ndo
print = abah
read = lan

le code ci:

`a=0;
c=6;
do
a=a+1;
print a;
while(a < c)
done`

devient :

`
a anoan 0;
c anoan 8;
bo
a anoan a akok_lo 1;
abah a;
ntie_te(a aboite c)
aman`

ça :
`for a = 0 to 5 step 1 
do
  print a;
endfor
`

devient:
`asu a anoan 0 ya 5 itie 1 
bo
 a anoan a;
  abah a;
aman_asu`
