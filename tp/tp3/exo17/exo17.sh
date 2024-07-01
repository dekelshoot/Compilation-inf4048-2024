bison -d parser.y
flex lexer.l
gcc -o parser parser.tab.c lex.yy.c -lfl
# echo "a=3; b=4+3*a; print a; print b;" | ./parser
./parser < input.txt