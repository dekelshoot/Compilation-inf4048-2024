%{
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h>
#define INTEGER 256

int yylval;
%}

/* entier*/
entier [0-9]

/*operateur*/
operateur  \+|\*

%%
{entier} { yylval=atoi(yytext);return INTEGER;}
{operateur} {return *yytext;}
.;
[\n];
[\$] {return *yytext;}

%%


/* Définition de la structure d'un nœud de pile */
typedef struct StackNode {
    char data;              /* Donnée du nœud */
    struct StackNode *next; /* Pointeur vers le prochain nœud */
} StackNode;

/* Structure de la pile */
typedef struct {
    StackNode *top; /* Pointeur vers le sommet de la pile */
} Stack;

/* Fonction pour créer une pile vide */
Stack *create_stack() {
    Stack *stack = (Stack *)malloc(sizeof(Stack)); /* Allouer de la mémoire pour une nouvelle pile */
    if (stack == NULL) { /* Vérifier si l'allocation a échoué */
        fprintf(stderr, "Erreur d'allocation de mémoire pour la pile\n");
        exit(EXIT_FAILURE); /* Sortie du programme en cas d'erreur d'allocation */
    }
    stack->top = NULL; /* Initialiser le sommet de la pile à NULL */
    return stack; /* Retourner le pointeur vers la pile nouvellement créée */
}

/* Fonction pour vérifier si la pile est vide */
int stack_is_empty(Stack *stack) {
    return (stack->top == NULL); /* Retourne 1 (vrai) si la pile est vide, sinon 0 (faux) */
}

/* Fonction pour ajouter un élément au sommet de la pile */
void stack_push(Stack *stack, char data) {
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode)); /* Allouer de la mémoire pour un nouveau nœud de pile */
    if (newNode == NULL) { /* Vérifier si l'allocation a échoué */
        fprintf(stderr, "Erreur d'allocation de mémoire pour un nouveau nœud de pile\n");
        exit(EXIT_FAILURE); /* Sortie du programme en cas d'erreur d'allocation */
    }
    newNode->data = data; /* Assigner la valeur au nouveau nœud */
    newNode->next = stack->top; /* Le nouveau nœud pointe vers l'ancien sommet de la pile */
    stack->top = newNode; /* Mettre à jour le sommet de la pile pour qu'il pointe vers le nouveau nœud */
}

/* Fonction pour retirer et récupérer l'élément du sommet de la pile */
char stack_pop(Stack *stack) {
    if (stack_is_empty(stack)) { /* Vérifier si la pile est vide */
        fprintf(stderr, "Erreur: la pile est vide\n");
        exit(EXIT_FAILURE); /* Sortie du programme en cas de tentative de dépilement sur une pile vide */
    }
    StackNode *temp = stack->top; /* Stocker l'adresse du sommet de la pile */
    char data = temp->data; /* Récupérer la valeur du sommet de la pile */
    stack->top = stack->top->next; /* Mettre à jour le sommet de la pile pour qu'il pointe vers le nœud suivant */
    free(temp); /* Libérer la mémoire du nœud dépilé */
    return data; /* Retourner la valeur dépilée */
}

/* Fonction pour récupérer l'élément du sommet de la pile sans le retirer */
char stack_top(Stack *stack) {
    if (stack_is_empty(stack)) { /* Vérifier si la pile est vide */
        fprintf(stderr, "Erreur: la pile est vide\n");
        exit(EXIT_FAILURE); /* Sortie du programme en cas de tentative d'accès sur une pile vide */
    }
    return stack->top->data; /* Retourner la valeur du sommet de la pile */
}

/* Fonction pour libérer la mémoire utilisée par la pile */
void free_stack(Stack *stack) {
    while (!stack_is_empty(stack)) { /* Tant que la pile n'est pas vide */
        stack_pop(stack); /* Dépiler le sommet de la pile */
    }
    free(stack); /* Libérer la mémoire de la structure de la pile */
}

/* Table d'actions: retourne un positif pour shift, un négatif pour reduce, 0 pour erreur, -1 pour acceptation */
int getAction(int state, char input) {
    switch (state) { /* Vérifie l'état actuel */
        case 0:
            if (input == 'i') return 2; /* S2 pour 'int' (i) */
            break;
        case 1:
            if (input == '+') return 3; /* S3 pour '+' */
            if (input == '*') return 4; /* S4 pour '*' */
            if (input == '$') return -1; /* Acceptation */
            break;
        case 2:
            if (input == '+' || input == '*' || input == '$') return -4; /* R3: E -> int */
            break;
        case 3:
            if (input == 'i') return 2; /* S2 pour 'int' (i) */
            break;
        case 4:
            if (input == 'i') return 2; /* S2 pour 'int' (i) */
            break;
        case 5:
            if (input == '+' || input == '*' || input == '$') return -2; /* R1: E -> E + E */
            break;
        case 6:
            if (input == '+' || input == '*' || input == '$') return -3; /* R2: E -> E * E */
            break;
    }
    return 0; /* Erreur */
}

/* Table goto: retourne le nouvel état pour un non-terminal donné */
int getGoto(int state, char nonterminal) {
    switch (state) {
        case 0:
            if (nonterminal == 'E') return 1;
            break;
        case 3:
            if (nonterminal == 'E') return 5;
            break;
        case 4:
            if (nonterminal == 'E') return 6;
            break;
    }
    return -1; /* Erreur */
}

/* Fonction pour analyser une chaîne d'entrée */
void parse(const char* input) {
    Stack *stack = create_stack(); /* Créer une pile */
    stack_push(stack, 0); /* Pousser l'état initial dans la pile */

    int i = 0; /* Initialisation de l'indice de l'entrée */
    while (1) {
        int state = stack_top(stack); /* Récupère l'état au sommet de la pile */
        char symbol = input[i];         /* Récupère le symbole courant de l'entrée */

        int action = getAction(state, symbol); /* Récupère l'action à effectuer pour l'état et le symbole courant */
        if (action == -1) { /* Acceptation */
            printf("Entrée acceptée\n");
            return; /* Fin de l'analyse */
        }
        if (action > 0) { /* Shift */
            printf("Shift: %c\n", symbol); /* Affiche l'opération de décalage */
            stack_push(stack, symbol); stack_push(stack, action);   /* Empile le nouvel état et le symbole */
            i++;                           /* Passe au symbole suivant de l'entrée */
        } else if (action < 0) { /* Reduce */
            int rule = -action; /* La règle de réduction est l'opposé de l'action */
            printf("Reduce: ");
            switch (rule) { 
                case 2: /* E -> E + E */
                    printf("E -> E + E\n");
                    stack_pop(stack); stack_pop(stack); stack_pop(stack); 
                    stack_pop(stack); stack_pop(stack); stack_pop(stack); 
                    int temp = getGoto(stack_top(stack), 'E');
                    stack_push(stack,'E'); /* empiler le non-terminal E et l'état */
                    stack_push(stack,temp); 
                    break;
                case 3: /* E -> E * E */
                    printf("E -> E * E\n");
                    stack_pop(stack); stack_pop(stack); stack_pop(stack); 
                    stack_pop(stack); stack_pop(stack); stack_pop(stack); 
                    int temp1 = getGoto(stack_top(stack), 'E');
                    stack_push(stack,'E'); /* empiler le non-terminal E et l'état */
                    stack_push(stack,temp1); 
                    break;
                case 4: /* E -> int */
                    printf("E -> int\n");
                    stack_pop(stack); stack_pop(stack); 
                    int temp2 = getGoto(stack_top(stack), 'E');
                    stack_push(stack,'E'); /* empiler le non-terminal E et l'état */
                    stack_push(stack,temp2); 
                    break;
            }
        } else { /* Erreur */
            printf("Syntax error\n");
            return; /* Fin de l'analyse en cas d'erreur */
        }
    }
}

// Fonction pour remplacer les nombres par 'i' dans une chaîne de caractères
char* remplacer_nombres_par_i(const char* input) {
    if (input == NULL) return NULL; // Vérification si l'entrée est NULL

    int len = strlen(input); // Calcul de la longueur de la chaîne d'entrée
    // Allocation de mémoire pour la nouvelle chaîne de sortie avec un caractère de plus pour le '\0'
    char* output = (char*)malloc((len + 1) * sizeof(char));
    if (output == NULL) { // Vérification de l'allocation de mémoire
        fprintf(stderr, "Erreur d'allocation de mémoire\n");
        exit(EXIT_FAILURE); // Sortie du programme en cas d'échec d'allocation
    }

    int j = -1; // Indice pour la chaîne de sortie (output)
    for (int i = 0; i < len; ++i) {
        if (isdigit(input[i])) { // Vérifie si le caractère est un chiffre
            output[j++] = 'i'; // Remplace le nombre par la lettre 'i'
            while (isdigit(input[i])) // Ignore le nombre complet dans l'entrée
                ++i;
            --i; // Décrémente i pour compenser l'incrémentation de la boucle for
        } else {
            output[j++] = input[i]; // Copie le caractère d'entrée dans la sortie
        }
    }
    output[j] = '\0'; // Termine la chaîne de sortie avec '\0' pour la rendre valide

    return output; // Retourne la chaîne de sortie nouvellement créée
}



int main(int argc, char **argv)
{
	int code;
    char input[100];


	
	while((code = yylex())){
	  if(code == 256){
        sprintf(input + strlen(input), "%d", yylval); // Convertit yylval en une chaîne de caractères
	    printf("%d\t",yylval);
	    
	  } 
	  else
	  {
        sprintf(input + strlen(input), "%c", code); // Convertit yylval en une chaîne de caractères
	    printf("%c\t",code);
	  }
	    
	}
	
    strcat(input, "$");
    char* input2 = remplacer_nombres_par_i(input);
    parse(input2);
	return 0;
}