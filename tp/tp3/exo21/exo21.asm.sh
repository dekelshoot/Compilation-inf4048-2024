nasm -f elf32 exo21.asm -o exo21.o
ld -m elf_i386 exo21.o -o exo21
chmod +x exo21
./exo21
