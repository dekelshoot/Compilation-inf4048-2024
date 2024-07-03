extern printf, scanf
section .data
; déclaration des variables en mémoire
a: dd 0
b: dd 0
c: dd 0
d: dd 0
fmt: db "%d", 10, 0
fmtlec: db "%d", 0
section .text
global _start

_start:

push 3
; affectation
pop eax
mov [3], eax

push 4
push 3
; récupération en mémoire
mov eax,  [3]
push eax
; multiplication
pop eax
pop ebx
imul eax, ebx
push eax

; addition
pop eax
pop ebx
add eax, ebx
push eax

; affectation
pop eax
mov [13], eax

; afficher
mov eax,  [a] 
push eax
push dword fmt
call printf

; afficher
mov eax,  [b] 
push eax
push dword fmt
call printf

mov eax, 1 ; sys_exit
mov ebx, 0 ; Exit avec le code de retour 0 (pas d'erreur)
int 80h