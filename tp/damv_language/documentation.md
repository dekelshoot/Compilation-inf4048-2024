# Documentation

- if -----> nge
- finsi -----> aman_nge
- do -----> bo
- done -----> aman
- for -----> asu
- step -----> itie
- to -----> ya
- endfor -----> aman_asu
- "+" -----> akok_lo
- "\*" -----> a_pouli
- "-" -----> a_vah
- = -----> anoan
- == -----> Dzam_deuh
- != -----> asseulen
- ">" -----> abui
- < -----> aboite
- while -----> ntie_te
- else -----> nde_ya
- then -----> ndo
- print -----> abah
- read -----> lan

# Exemple

### boucle while

le code ci(do while):

```C

a=0;
c=6;
do
a=a+1;
print a;
while(a < c)
done
```

devient :

```davm

a anoan 0;
c anoan 8;
bo
a anoan a akok_lo 1;
abah a;
ntie_te(a aboite c)
aman
```

### boucle for

le code ci (for):

```C

for a = 0 to 5 step 1
do
  print a;
endfor
```

devient:

```davm

asu a anoan 0 ya 5 itie 1
bo
 a anoan a;
  abah a;
aman_asu
```

### condition if else

Le code ci: (if else)

```C

a = 10;
b = 20;
si (a < b) alors
    print a;
sinon
    print b;
fsi
```

devient:

```C

a anoan 10;
b anoan 20;
nge (a aboite b) ndo
    abah a;
nde_ya
    abah b;
aman_nge

```

### boucle tantque et if associés

Le code ci(tanque et if):

```C

if(a!=2) then
    print a;
  fi
a = 0;

read b;
read c;

while(a < c)
do
  a = a + b;

  if(a!----->2) then
    print a;
  fi
done

```

devient:

```C
nge(a asseulen 2) ndo
    abah a;
  aman_nge
a anoan 0;

lan b;
lan c;

ntie_te(a aboite c)
bo
  a anoan a akok_lo b;
  nge(a asseulen 2) ndo
    abah a;
  aman_nge
aman

```

### boucle for imbriqué

Le code ci(for imbriqué):

```C

a=0;
d= 10;
for b =0 to 5 step 1
do
  for c = 0 to 2 step 1
  do
    print d;
  endfor

  a = a + 1;
  print a;
endfor
```

devient:

```C

a anoan 0;
d anoan 10;
asu b anoan 0 ya 5 itie 1
bo
  asu c anoan 0 ya 2 itie 1
  bo
    abah d;
  aman_asu

  a anoan a akok_lo 1;
  abah a;
aman_asu
```

### condition switch case

le code ci

```C

a=10;
switch a
case 10:
  a=a+2;
  print a;
break

case 2:
  a=a+2;
  print a;
break

case 11:
  a=a+3;
  print a;
break

endswitch
```

devient:

```C
a anoan 10;

switch a

case 10 :
a anoan a akok_lo 2;
abah a;
break

case 2 :
a anoan a akok_lo 2;
abah a;
break

case 11 :
a anoan a akok_lo 3;
abah a;
break

endswitch
```
