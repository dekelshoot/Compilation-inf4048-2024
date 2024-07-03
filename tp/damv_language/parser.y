%{
#include <stdio.h>
#include "simple.h"

#define nbMax 100

#define MAX_DO_WHILE 100  // Taille maximale de la pile des boucles do...while

int compteurSi = 0, compteurTest = 0, compteurWhile = 0, compteurFor = 0 ,topDoWhile = 0;
extern FILE *yyout;

// Stack to handle nested for loop labels
int forLabelStack[nbMax];
int top = -1;

int doWhileLabels[MAX_DO_WHILE];  // Tableau pour stocker les étiquettes de boucle do...while


char *header = "extern printf,scanf \nsection .data\n; declaration des variables en memoire\na:  dd  0\nb:  dd  0\nc:  dd  0\nd:  dd  0\nfmt:db \"%d\", 10, 0 \nfmtlec:db \"%d\",0\nsection .text\nglobal _start\n\n_start:\n\n";
char *trailer = "mov eax,1 ; sys_exit \nmov ebx,0; Exit with return code of 0 (no error)\nint 80h";
char *add = " ; addition\npop eax\npop ebx\nadd eax,ebx\npush eax\n\n";
char *mul = " ;multiplication\npop eax\npop ebx\nmul ebx\npush eax\n\n";
char *affec = " ;affectation\npop eax\nmov";
char *take = " ;recuperation en memoire\nmov eax,";
char *affec1 = ";affectation\n";
char *afficher1 = ";afficher\nmov eax,";
char *afficher2 = "\npush eax\npush dword fmt\ncall printf\n\n";
char *lire1 = ";lire\npush ";
char *lire2 = "\npush dword fmtlec\ncall scanf\n\n";
char *cmp = "pop ebx\npop eax\ncmp eax, ebx\n\n";
char *cmpEgal;
char *testGene;
char *cmpDifferent;
char *cmpSuperieur;
char *cmpInferieur;
char *tmp1, *tmp2;
int sinonVu = 0;

int yylex();
int yyerror(char *str);

void pushDoWhile(int label) {
    if (topDoWhile < MAX_DO_WHILE) {
        doWhileLabels[topDoWhile++] = label;
    } else {
        fprintf(stderr, "Erreur : Dépassement de capacité de la pile des boucles do...while.\n");
        
    }
}

int popDoWhile() {
    if (topDoWhile > 0) {
        return doWhileLabels[--topDoWhile];
    } else {
        fprintf(stderr, "Erreur : Tentative de dépiler depuis une pile des boucles do...while vide.\n");
    }
}

void push(int label) {
    if (top < nbMax - 1) {
        forLabelStack[++top] = label;
    }
}

int pop() {
    if (top >= 0) {
        return forLabelStack[top--];
    }
    return -1; // Stack is empty
}

%}

%token INTEGER
%token ABAH
%token VARIABLE
%token NGE
%token NDO
%token NDEYA
%token AMANNGE
%token LAN
%token NTIETE
%token AMAN
%token BO
%token ASU
%token YA
%token ITIE
%token AMANASU
%token AKOK_LO
%token MUL
%token ANOAN
%token SEMI
%token DZAM_DEUH
%token ASSEULEN
%token ABOITE
%token ABUI
%token LPAREN
%token RPAREN

%%
Program:
    program_body { printf("Aucune erreur de syntaxe détectée \n"); }

program_body:
    stat
    | stat program_body

stat:
    bloc
    | blocSi
    | blocWhile
    | blocFor
	| blocDoWhile

bloc:
    instr SEMI
    | instr SEMI bloc

instr:
    VARIABLE ANOAN E { fprintf(yyout, "%s [%c], eax\n\n", affec, $1); }
    | ABAH VARIABLE { fprintf(yyout, "%s [%c] %s", afficher1, $2, afficher2); }
    | LAN VARIABLE { fprintf(yyout, "%s %c %s", lire1, $2, lire2); }
    | VARIABLE ANOAN cond { fprintf(yyout, "%s [%c], eax\n\n", affec, $1); }

blocFor:
    ASU VARIABLE ANOAN E YA E ITIE E BO 
    {
        compteurFor++;
		fprintf(yyout, ";*************** Boucle for***** ****\n");
		fprintf(yyout, "mov dword [%c], %d\n", $2, $4); // initialisation
        fprintf(yyout, "debutFor%d:\n", compteurFor); // étiquette début
        fprintf(yyout, "mov eax, [%c]\ncmp eax, %d\njg finFor%d\n", $2, $6, compteurFor); // condition
        fprintf(yyout, "; code du bloc\n");
        push(compteurFor);
    }
	blocIntFor AMANASU
    {
        int forLabel = pop();
        fprintf(yyout, "add dword [%c], %d\njmp debutFor%d\nfinFor%d:\n", $2, $8, forLabel, forLabel); // incrémentation et fin
    }

blocIntFor:
    bloc
    | blocSi
    | blocWhile
	| blocFor 
	| blocFor bloc
    | blocSi blocIntFor
    | bloc blocIntFor

blocDoWhile:
	BO
    {
        compteurWhile++;
        fprintf(yyout, ";********Lieu de l'étiquete\n");
        fprintf(yyout, "debutWhile%d:\n", compteurWhile);
    }
    blocIntDoWhile NTIETE exp_bool ENDWHILE


blocIntDoWhile:
    bloc
    | blocSi
    | blocFor
    | blocWhile
    | blocDoWhile

	
blocWhile:
    NTIETE etiquetWhile exp_bool LOOP blocIntWhile ENDWHILE { fprintf(yyout, ";*************** ***** ****Réduction du bloc while\n"); }

blocIntWhile:
    bloc
    | blocSi
    | blocSi blocIntWhile
    | bloc blocIntWhile

etiquetWhile:
    {
        compteurWhile++;
        fprintf(yyout, ";********Lieu de l'étiquete\n");
        fprintf(yyout, "debutWhile%d:\n", compteurWhile);
    }

LOOP:
    BO { fprintf(yyout, ";*************** ***** ****Réduction du do\n"); }

exp_bool:
    cond
    {
        fprintf(yyout, ";*************** ***** ****Réduction de la condition\n");
        fprintf(yyout, "pop eax\ncmp eax,1\njne finWhile%d\n", compteurWhile);
    }

ENDWHILE:
    AMAN
    {
        fprintf(yyout, ";*************** ***** ****Réduction du done\n");
        fprintf(yyout, "jmp debutWhile%d\nfinWhile%d:\n", compteurWhile, compteurWhile);
    }

blocSi:
    NGE cond alo bloc finSi
    | NGE cond alo bloc sino bloc finSi { fprintf(yyout, ";Condition detectée 2\n"); }

finSi:
    AMANNGE
    {
        if (sinonVu)
        {
            fprintf(yyout, "suite%d:\n", compteurSi);
            fprintf(yyout, ";Réduction du fsis%d\n", compteurSi);
            sinonVu = 0;
        }
        else
        {
            fprintf(yyout, "sinon%d:\n", compteurSi);
            fprintf(yyout, ";Réduction du fsi%d\n", compteurSi);
        }
    }

alo:
    NDO
    {
        compteurSi++;
        fprintf(yyout, ";Réduction du alors%d\n", compteurSi);
        fprintf(yyout, "pop eax\ncmp eax,1\njne sinon%d\n", compteurSi);
    }

sino:
    NDEYA
    {
        fprintf(yyout, "jmp suite%d\nsinon%d:\n", compteurSi, compteurSi);
        fprintf(yyout, ";Réduction du sinon%d\n", compteurSi);
        sinonVu = 1;
    }

cond:
    LPAREN F DZAM_DEUH F RPAREN
    {
        compteurTest++;
        cmpEgal = ";Teste d'égalité\n";
        fprintf(yyout, "%s%sjne test%d\npush 1\njmp fintest%d \ntest%d:\npush 0\nfintest%d:\n\n\n", cmpEgal, cmp, compteurTest, compteurTest, compteurTest, compteurTest);
    }
    | LPAREN F ASSEULEN F RPAREN
    {
        compteurTest++;
        cmpDifferent = ";Teste de différence\n";
        fprintf(yyout, "%s%sjne test%d\npush 0\njmp fintest%d \ntest%d:\npush 1\nfintest%d:\n\n\n", cmpDifferent, cmp, compteurTest, compteurTest, compteurTest, compteurTest);
    }
    | LPAREN F ABOITE F RPAREN
    {
        compteurTest++;
        cmpInferieur = ";Teste d'infériorité\n";
        fprintf(yyout, "%s%sjge test%d\npush 1\njmp fintest%d \ntest%d:\npush 0\nfintest%d:\n\n\n", cmpInferieur, cmp, compteurTest, compteurTest, compteurTest, compteurTest);
    }
    | LPAREN F ABUI F RPAREN
    {
        compteurTest++;
        cmpSuperieur = ";Teste de superiorité\n";
        fprintf(yyout, "%s%sjg test%d\npush 0\njmp fintest%d \ntest%d:\npush 1\nfintest%d:\n\n\n", cmpSuperieur, cmp, compteurTest, compteurTest, compteurTest, compteurTest);
    }

E:
    T
    | E AKOK_LO T { fprintf(yyout, "%s ", add); }

T:
    F
    | T MUL F { fprintf(yyout, "%s ", mul); }

F:
    INTEGER { fprintf(yyout, "push %d\n", $1); }
    | VARIABLE { fprintf(yyout, "%s [%c] \npush eax\n", take, $1); }

%%

int main(void)
{
    yyout = fopen("davm.asm", "w");
    fprintf(yyout, "%s", header);
    yyparse();
    fprintf(yyout, "%s", trailer);
    fclose(yyout);
    return 0;
}

int yyerror(char *str)
{
    printf("error parsing %s\n", str);
    return 0;
}
