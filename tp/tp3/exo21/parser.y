%{
#include <stdio.h>
#include "lexer.h"
int yylex(void);
int yyerror(const char *s);

FILE *outfile;

void print_assembly(const char *instr);
%}

%token INTEGER

%%
S: E { printf("Reduction: S -> E  Fin!! \n"); print_assembly("mov eax, [esp]"); print_assembly("add esp, 4"); print_assembly("mov [result], eax"); }
  ;

E: E '+' T { printf("Reduction: E -> E + T\n"); 
             print_assembly("pop ebx");
             print_assembly("pop eax");
             print_assembly("add eax, ebx");
             print_assembly("push eax"); }
  | T { printf("Réduction E -> T\n"); }
  ;

T: T '*' F { printf("Reduction: T -> T * F\n"); 
             print_assembly("pop ebx");
             print_assembly("pop eax");
             print_assembly("imul eax, ebx");
             print_assembly("push eax"); }
  | F { printf("Réduction T -> F\n"); }
  ;

F: INTEGER { printf("Reduction: F -> int   \t\t $1=%d\n", $1); 
             char buffer[50];
             sprintf(buffer, "push %d", $1);
             print_assembly(buffer); }
  ;
%%

int main() {
    outfile = fopen("exo21.asm", "w");
    if (outfile == NULL) {
        fprintf(stderr, "Erreur: Impossible d'ouvrir le fichier exo21.asm\n");
        return 1;
    }

    fprintf(outfile, "section .data\n");
    fprintf(outfile, "result dd 0\n");
    fprintf(outfile, "msg db \"Le résultat est: \", 0\n");
    fprintf(outfile, "num db \"0000\", 0\n");
    fprintf(outfile, "newline db 10, 0  ; Caractère de nouvelle ligne\n");
    fprintf(outfile, "section .bss\n");
    fprintf(outfile, "temp resb 10\n");
    fprintf(outfile, "section .text\n");
    fprintf(outfile, "global _start\n");
    fprintf(outfile, "_start:\n");

    yyparse();
// Écrire les instructions pour afficher le résultat
    fprintf(outfile, "mov esi, result\n");
    fprintf(outfile, "mov eax, [esi]\n");
    fprintf(outfile, "mov edi, num + 3\n");
    fprintf(outfile, "mov ecx, 10\n");
    fprintf(outfile, "convert_loop:\n");
    fprintf(outfile, "xor edx, edx\n");
    fprintf(outfile, "div ecx\n");
    fprintf(outfile, "add dl, '0'\n");
    fprintf(outfile, "mov [edi], dl\n");
    fprintf(outfile, "dec edi\n");
    fprintf(outfile, "test eax, eax\n");
    fprintf(outfile, "jnz convert_loop\n");
    fprintf(outfile, "mov ecx, num\n");
    fprintf(outfile, "mov edi, num + 3\n");
    fprintf(outfile, "skip_leading_zeros:\n");
    fprintf(outfile, "cmp byte [ecx], '0'\n");
    fprintf(outfile, "jnz print_number\n");
    fprintf(outfile, "inc ecx\n");
    fprintf(outfile, "cmp ecx, edi\n");
    fprintf(outfile, "jbe skip_leading_zeros\n");
    fprintf(outfile, "print_number:\n");
    fprintf(outfile, "mov edx, num + 4\n");
    fprintf(outfile, "sub edx, ecx\n");
    fprintf(outfile, "mov eax, 4\n");
    fprintf(outfile, "mov ebx, 1\n");
    fprintf(outfile, "mov ecx, ecx\n");
    fprintf(outfile, "int 0x80\n");
    fprintf(outfile, "mov eax, 4\n");
    fprintf(outfile, "mov ebx, 1\n");
    fprintf(outfile, "mov ecx, newline\n");
    fprintf(outfile, "mov edx, 1\n");
    fprintf(outfile, "int 0x80\n");
    fprintf(outfile, "mov eax, 1\n");
    fprintf(outfile, "xor ebx, ebx\n");
    fprintf(outfile, "int 0x80\n");

    fclose(outfile);
    return 0;
}

int yyerror(const char *s) {
    printf("Erreur syntaxique: %s\n", s);
    return 0;
}

void print_assembly(const char *instr) {
    printf("%s\n", instr);
    fprintf(outfile, "%s\n", instr);
}
