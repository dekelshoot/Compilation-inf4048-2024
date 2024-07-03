bison -d parser.y
flex lexer.l
gcc -o parser parser.tab.c lex.yy.c -lfl
./parser < input.txt