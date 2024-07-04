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

push 0
 ;affectation
pop eax
mov [b], eax

;lire
push  a 
push dword fmtlec
call scanf

;lire
push  b 
push dword fmtlec
call scanf

;********Lieu de l'étiquete
debutWhile1:
 ;recuperation en memoire
mov eax, [a] 
push eax
 ;recuperation en memoire
mov eax, [b] 
push eax
;Teste de différence
pop ebx
pop eax
cmp eax, ebx

jne test1
push 0
jmp fintest1 
test1:
push 1
fintest1:


;*************** ***** ****Réduction de la condition
pop eax
cmp eax,1
jne finWhile1
;*************** ***** ****Réduction du do
 ;recuperation en memoire
mov eax, [a] 
push eax
 ;recuperation en memoire
mov eax, [b] 
push eax
;Teste de superiorité
pop ebx
pop eax
cmp eax, ebx

jg test2
push 0
jmp fintest2 
test2:
push 1
fintest2:


;Réduction du alors1
pop eax
cmp eax,1
jne sinon1
 ;recuperation en memoire
mov eax, [b] 
push eax
 ;recuperation en memoire
mov eax, [a] 
push eax
 ; soustraction
pop eax
pop ebx
sub eax,ebx
push eax

  ;affectation
pop eax
mov [a], eax

jmp suite1
sinon1:
;Réduction du sinon1
 ;recuperation en memoire
mov eax, [a] 
push eax
 ;recuperation en memoire
mov eax, [b] 
push eax
 ; soustraction
pop eax
pop ebx
sub eax,ebx
push eax

  ;affectation
pop eax
mov [b], eax

suite1:
;Réduction du fsis1
;Condition detectée 2
;*************** ***** ****Réduction du done
jmp debutWhile1
finWhile1:
;*************** ***** ****Réduction du bloc while
;afficher
mov eax, [a] 
push eax
push dword fmt
call printf

;afficher
mov eax, [b] 
push eax
push dword fmt
call printf

mov eax,1 ; sys_exit 
mov ebx,0; Exit with return code of 0 (no error)
int 80h