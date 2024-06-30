flex -o exo14.lex.yy.c exo14.lex
gcc -pedantic -Wall -O2 exo14.lex.yy.c -o exo14 -lfl
echo "12+4*56" | ./exo14 