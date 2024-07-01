nasm -f elf32 hello-world.asm -o hello-world.o
ld -m elf_i386 hello-world.o -o hello-world
chmod +x hello-world
./hello-world
