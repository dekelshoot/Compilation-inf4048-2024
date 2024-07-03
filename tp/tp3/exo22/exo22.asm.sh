# nasm -f elf32 exo22.asm -o exo22.o
# ld -m elf_i386 exo22.o -o exo22
# chmod +x exo22
# ./exo22

nasm -f elf32 -o exo22.o exo22.asm
ld -s -o exo22 exo22.o -melf_i386 -I/lib/ld-linux.so.2 -lc
chmod +x exo22
./exo22