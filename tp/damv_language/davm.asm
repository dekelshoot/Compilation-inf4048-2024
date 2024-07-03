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

push 0
 ;affectation
pop eax
mov [a], eax

push 10
 ;affectation
pop eax
mov [d], eax

push 0
push 5
push 1
;*************** Boucle for***** ****
mov dword [b], 0
debutFor1:
mov eax, [b]
cmp eax, 5
jg finFor1
; code du bloc
push 0
push 2
push 1
;*************** Boucle for***** ****
mov dword [c], 0
debutFor2:
mov eax, [c]
cmp eax, 2
jg finFor2
; code du bloc
;afficher
mov eax, [d] 
push eax
push dword fmt
call printf

add dword [c], 1
jmp debutFor2
finFor2:
 ;recuperation en memoire
mov eax, [a] 
push eax
push 1
 ; addition
pop eax
pop ebx
add eax,ebx
push eax

  ;affectation
pop eax
mov [a], eax

;afficher
mov eax, [a] 
push eax
push dword fmt
call printf

add dword [b], 1
jmp debutFor1
finFor1:
mov eax,1 ; sys_exit 
mov ebx,0; Exit with return code of 0 (no error)
int 80h