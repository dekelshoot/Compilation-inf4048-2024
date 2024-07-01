# flex -o exo15.yy.c exo15.lex
# gcc -pedantic -Wall -O2 exo15.yy.c -o exo15 -lfl
# echo "12+6*8" | ./exo15 

bison -d parser.y
flex lexer.l
gcc -o parser parser.tab.c lex.yy.c -lfl
echo "12+6*8" | ./parser