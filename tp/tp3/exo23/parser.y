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

void print_assembly(const char *instr);
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
%token EQ
%token NE
%token LT
%token GT
%token LPAREN
%token RPAREN
%token IF
%token THEN
%token FI
%token WHILE
%token DO
%token ENDWHILE

%type <ival> E T F C
%type <sval> I S B

%%

S: S SEMI I
 | I
 ;

I: ID ASSIGN E { 
        set_var_value($1, $3); 
        printf("Assignment: %s = %d\n", $1, $3); 
    }
 | PRINT E { 
        printf("Print: %d\n", $2); 
    }
 | IF LPAREN E C RPAREN THEN S FI { 
        if ($3) {
            printf("If: %d\n", $2);
        }
    }
 | B { 
        $1;
    }
 ;

E: E PLUS T { 
        $$ = $1 + $3; 
        printf("Reduction: E -> E + T \t\t%d + %d = %d\n", $1, $3, $$); 
    }
 | T { 
        $$ = $1; 
        printf("Reduction: E -> T \t\t%d\n", $1); 
    }
 ;

T: T TIMES F { 
        $$ = $1 * $3; 
        printf("Reduction: T -> T * F \t\t%d * %d = %d\n", $1, $3, $$); 
    }
 | F { 
        $$ = $1; 
        printf("Reduction: T -> F \t\t%d\n", $1); 
    }
 ;

F: INT { 
        $$ = $1; 
        printf("Reduction: F -> int \t\t%d\n", $1); 
    }
 | ID { 
        $$ = get_var_value($1); 
        printf("Reduction: F -> id \t\t%s = %d\n", $1, $$); 
    }
 ;

C: EQ { 
        $$ = $1; 
    }
 | NE { 
        $$ = $1; 
    }
 | LT { 
        $$ = $1; 
    }
 | GT { 
        $$ = $1; 
    }
 ;

B: WHILE LPAREN E RPAREN DO S ENDWHILE { 
        while ($3) {
            printf("While: %d\n", $3);
            $7;
        }
    }
 ;

%%

int main() {
    outfile = fopen("output.asm", "w");
    if (outfile == NULL) {
        fprintf(stderr, "Erreur: Impossible d'ouvrir le fichier output.asm\n");
        return 1;
    }

    yyparse();

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
