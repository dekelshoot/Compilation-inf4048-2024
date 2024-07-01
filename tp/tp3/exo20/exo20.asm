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
    ; Calculer 4 * 5
    mov eax, 4          ; Charger 4 dans eax
    imul eax, 5         ; Multiplier eax par 5

    ; Ajouter 1
    add eax, 1          ; Ajouter 1 à eax

    ; Sauvegarder le résultat dans la variable result
    mov [result], eax

    ; Convertir le résultat en chaîne de caractères
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

    ; Afficher le message "Result: "
    mov eax, 4          ; sys_write
    mov ebx, 1          ; file descriptor (stdout)
    mov ecx, msg        ; adresse de la chaîne à écrire
    mov edx, 17          ; longueur de la chaîne
    int 0x80            ; appel système

    ; Afficher le résultat sans les zéros devant
    mov ecx, num
    mov edi, num + 3
skip_leading_zeros:
    cmp byte [ecx], '0'
    jnz print_number
    inc ecx
    cmp ecx, edi
    jbe skip_leading_zeros

print_number:
    ; Afficher les chiffres restants
    mov edx, num + 4
    sub edx, ecx
    mov eax, 4          ; sys_write
    mov ebx, 1          ; file descriptor (stdout)
    int 0x80            ; appel système

    ; Afficher un retour à la ligne
    mov eax, 4          ; sys_write
    mov ebx, 1          ; file descriptor (stdout)
    mov ecx, newline    ; adresse de la nouvelle ligne
    mov edx, 1          ; longueur de la nouvelle ligne
    int 0x80            ; appel système

    ; Terminer le programme proprement
    mov eax, 1          ; sys_exit
    xor ebx, ebx        ; code de retour 0
    int 0x80            ; appel système
