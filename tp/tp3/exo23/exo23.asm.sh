# nasm -f elf32 exo23.asm -o exo23.o
# ld -m elf_i386 exo23.o -o exo23
nasm -f elf -o test.o exo23.asm
ld -s -o test test.o -melf_i386 -I/lib/ld-linux.so.2 -lc
chmod +x test
./test
