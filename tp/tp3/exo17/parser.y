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
    }
 | PRINT E { 
        printf("Print: %d\n", $2); 
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
%%

int main() {
    yyparse();
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
