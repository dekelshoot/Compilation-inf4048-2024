extern printf,scanf 
section .data
; declaration des variables en memoire
a:  dd  0
b:  dd  0
c:  dd  0
d:  dd  0
fmt:db "%d", 10, 0 
fmtlec:db "%d",0
section .text
global _start

_start:

mov dword [a], 0
debutFor1:
mov eax, [a]
cmp eax, 5
jg finFor1

; instructions à exécuter dans la boucle
mov eax, [a]
push eax
push dword fmt
call printf

add dword [a], 1
jmp debutFor1
finFor1:

mov eax,1 ; sys_exit 
mov ebx,0; Exit with return code of 0 (no error)
int 80h
