section .data
result dd 0
msg db "Le résultat est: ", 0
num db "0000", 0
newline db 10, 0  ; Caractère de nouvelle ligne
section .bss
temp resb 10
section .text
global _start
_start:
push 2
push 3
push 2
pop ebx
pop eax
imul eax, ebx
push eax
pop ebx
pop eax
add eax, ebx
push eax
mov eax, [esp]
add esp, 4
mov [result], eax
mov esi, result
mov eax, [esi]
mov edi, num + 3
mov ecx, 10
convert_loop:
xor edx, edx
div ecx
add dl, '0'
mov [edi], dl
dec edi
test eax, eax
jnz convert_loop
mov ecx, num
mov edi, num + 3
skip_leading_zeros:
cmp byte [ecx], '0'
jnz print_number
inc ecx
cmp ecx, edi
jbe skip_leading_zeros
print_number:
mov edx, num + 4
sub edx, ecx
mov eax, 4
mov ebx, 1
mov ecx, ecx
int 0x80
mov eax, 4
mov ebx, 1
mov ecx, newline
mov edx, 1
int 0x80
mov eax, 1
xor ebx, ebx
int 0x80
