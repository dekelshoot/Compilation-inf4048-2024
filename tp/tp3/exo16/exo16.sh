bison -d parser.y
flex lexer.l
gcc -o parser parser.tab.c lex.yy.c -lfl
echo "12+6*8" | ./parser