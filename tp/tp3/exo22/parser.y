%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char* name;
    int value;
} variable;

variable vars[100];
int var_count = 0;

int yylex(void);
void yyerror(const char *s);
int find_var_index(const char* name);
int get_var_value(const char* name);
void set_var_value(const char* name, int value);

FILE *outfile;



char *header = "extern printf, scanf\nsection .data\n; déclaration des variables en mémoire\na: dd 0\nb: dd 0\nc: dd 0\nd: dd 0\nfmt: db \"%d\", 10, 0\nfmtlec: db \"%d\", 0\nsection .text\nglobal _start\n\n_start:\n\n";
char *footer = "mov eax, 1 ; sys_exit\nmov ebx, 0 ; Exit avec le code de retour 0 (pas d'erreur)\nint 80h";

char *add = "; addition\npop eax\npop ebx\nadd eax, ebx\npush eax\n\n";
char *mul = "; multiplication\npop eax\npop ebx\nimul eax, ebx\npush eax\n\n";
char *affec = "; affectation\npop eax\nmov";
char *take = "; récupération en mémoire\nmov eax, ";
char *aff1 = "; afficher\nmov eax, ";
char *aff2 = "\npush eax\npush dword fmt\ncall printf\n\n";
char *lire1 = "; lire\npush ";
char *lire2 = "\npush dword fmtlec\ncall scanf\n\n";
char *cmp = "pop ebx\npop eax\ncmp eax, ebx\n\n";

void print_assembly(const char *instr);
void declare_variable(const char *name);
void print_assembly_with_value(const char *instr, int value);
void generate_print_code(const char *varname);
%}

%union {
    int ival;
    char* sval;
}

%token <ival> INT
%token <sval> ID
%token PRINT
%token ASSIGN
%token SEMI
%token PLUS
%token TIMES

%type <ival> E T F
%type <sval> I S

%%
S: S SEMI I
 | I
 ;

I: ID ASSIGN E { 
        set_var_value($1, $3); 
        printf("Assignment: %s = %d\n", $1, $3); 
        fprintf(outfile, "%s [%d], eax\n\n", affec, $3);
    }
 | PRINT ID { 
        printf("Print: %s\n", $2); 
        fprintf(outfile, "%s [%s] %s", aff1, $2, aff2);
    }
 ;

E: E PLUS T { 
        $$ = $1 + $3; 
        printf("Reduction: E -> E + T \t\t%d + %d = %d\n", $1, $3, $$); 
        fprintf(outfile, "%s", add);
    }
 | T { 
        $$ = $1; 
        printf("Reduction: E -> T \t\t%d\n", $1); 
    }
 ;

T: T TIMES F { 
        $$ = $1 * $3; 
        printf("Reduction: T -> T * F \t\t%d * %d = %d\n", $1, $3, $$); 
        fprintf(outfile, "%s", mul);
    }
 | F { 
        $$ = $1; 
        printf("Reduction: T -> F \t\t%d\n", $1); 
    }
 ;

F: INT { 
        $$ = $1; 
        printf("Reduction: F -> int \t\t%d\n", $1); 
        fprintf(outfile, "push %d\n", $1);
    }
 | ID { 
        $$ = get_var_value($1); 
        printf("Reduction: F -> id \t\t%s = %d\n", $1, $$); 
        fprintf(outfile, "%s [%d]\npush eax\n", take, $$);
    }
 ;
%%

int main() {
    outfile = fopen("exo22.asm", "w");
    if (outfile == NULL) {
        fprintf(stderr, "Erreur: Impossible d'ouvrir le fichier exo22.asm\n");
        return 1;
    }


    fprintf(outfile, "%s", header);
    yyparse();
    fprintf(outfile, "%s", footer);
    
    fclose(outfile);
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int find_var_index(const char* name) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(vars[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int get_var_value(const char* name) {
    int index = find_var_index(name);
    if (index == -1) {
        fprintf(stderr, "Undefined variable: %s\n", name);
        exit(1);
    }
    return vars[index].value;
}

void set_var_value(const char* name, int value) {
    int index = find_var_index(name);
    if (index == -1) {
        vars[var_count].name = strdup(name);
        vars[var_count].value = value;
        var_count++;
    } else {
        vars[index].value = value;
    }
}

void print_assembly(const char *instr) {
    printf("%s\n", instr);
    fprintf(outfile, "%s\n", instr);
}

void print_assembly_with_value(const char *instr, int value) {
    printf("%s %d\n", instr, value);
    fprintf(outfile, "%s %d\n", instr, value);
}

void declare_variable(const char *name) {
    char buffer[50];
    sprintf(buffer, "%s dd 0", name);
    fprintf(outfile, "section .data\n%s\nsection .text\n", buffer);
}

void generate_print_code(const char *varname) {
    char buffer[100];
    sprintf(buffer, "mov eax, [%s] \npush eax\npush dword fmt\n", varname);
    print_assembly(buffer);
    print_assembly("call print_eax");
}
