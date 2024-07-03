section .data
section .bss
section .text
global _start
_start:
mov eax, 3
mov eax, 3
mov eax, 3
mov a, eax
mov eax, 4
mov eax, 4
mov eax, 3
mov eax, a
mov eax, 3
imul eax, 3
mov eax, 4
add eax, 9
mov eax, 13
mov b, eax
mov eax, a
mov eax, 3
mov eax, 3
mov eax, 3
call print_int
mov eax, b
mov eax, 13
mov eax, 13
mov eax, 13
call print_int
