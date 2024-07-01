section .data
    hello db 'Hello, World!', 0x0A, 0    ; Le message à afficher avec un saut de ligne (\n)

section .text
    global _start

_start:
    ; Écrire le message sur la sortie standard
    mov eax, 4                    ; sys_write
    mov ebx, 1                    ; file descriptor 1 (stdout)
    mov ecx, hello                ; adresse du message
    mov edx, 14                   ; longueur du message (y compris le saut de ligne)
    int 0x80                      ; appel système

    ; Terminer le programme
    mov eax, 1                    ; sys_exit
    xor ebx, ebx                  ; code de sortie 0
    int 0x80                      ; appel système
