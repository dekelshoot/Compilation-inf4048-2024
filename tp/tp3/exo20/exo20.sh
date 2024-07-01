nasm -f elf32 exo20.asm -o exo20.o
ld -m elf_i386 exo20.o -o exo20
chmod +x exo20
./exo20
