bison --defines=simple.h -v -o parser.c parser.y
flex -o lexer.yy.c lexer.lex
gcc lexer.yy.c parser.c -o davm -lfl
nasm -f elf -o asm.o davm.asm
ld -s -o asm asm.o -melf_i386 -I/lib/ld-linux.so.2 -lc

chmod +x davm
cat commande.mes | ./davm

chmod +x asm
./asm