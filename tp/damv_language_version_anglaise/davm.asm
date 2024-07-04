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

push 6
 ;affectation
pop eax
mov [c], eax

;********Lieu de l'étiquete
debutWhile1:
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

 ;recuperation en memoire
mov eax, [a] 
push eax
 ;recuperation en memoire
mov eax, [c] 
push eax
;Teste d'infériorité
pop ebx
pop eax
cmp eax, ebx

jge test1
push 1
jmp fintest1 
test1:
push 0
fintest1:


;*************** ***** ****Réduction de la condition
pop eax
cmp eax,1
jne finWhile1
;*************** ***** ****Réduction du done
jmp debutWhile1
finWhile1:
mov eax,1 ; sys_exit 
mov ebx,0; Exit with return code of 0 (no error)
int 80h