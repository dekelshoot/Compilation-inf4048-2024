#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure pour stocker les tokens
typedef struct {
    char type; // 'i' pour int, 'o' pour opérateur
    char value[10];
} Token;

// Fonction pour afficher les lexèmes sous forme formatée
char* afficher(char *valeur, char *type) {
    char *result = malloc(100 * sizeof(char)); // Allouer de la mémoire pour la chaîne de retour
    if (result == NULL) { // Vérifier si l'allocation a réussi
        fprintf(stderr, "Erreur d'allocation de mémoire\n"); // Afficher une erreur si l'allocation échoue
        exit(1); // Quitter le programme
    }

    // Formater la chaîne en fonction du type
    if (strcmp(type, "int") == 0) {
        sprintf(result, "<int:%s>", valeur); // Formater pour les entiers
    } else if (strcmp(type, "operateur") == 0) {
        sprintf(result, "<operateur:%s>", valeur); // Formater pour les opérateurs
    } else {
        free(result); // Libérer la mémoire si le type n'est pas reconnu
        return NULL; // Retourner NULL
    }

    return result; // Retourner la chaîne formatée
}

// Fonction pour analyser l'expression et stocker les tokens
int tokenize(char *expression, Token tokens[]) {
    int length = strlen(expression);
    int token_count = 0;
    int i = 0;

    while (i < length) {
        if (isdigit(expression[i])) {
            int j = i;
            while (j < length && isdigit(expression[j])) {
                j++;
            }
            strncpy(tokens[token_count].value, &expression[i], j - i);
            tokens[token_count].value[j - i] = '\0';
            tokens[token_count].type = 'i';
            token_count++;
            i = j;
        } else if (expression[i] == '+' || expression[i] == '*') {
            tokens[token_count].value[0] = expression[i];
            tokens[token_count].value[1] = '\0';
            tokens[token_count].type = 'o';
            token_count++;
            i++;
        } else {
            fprintf(stderr, "Caractère invalide à la position %d\n", i);
            exit(1);
        }
    }

    return token_count;
}

// Fonction pour évaluer l'expression sans priorité
int evaluate_without_priority(Token tokens[], int token_count) {
    int result = atoi(tokens[0].value);
    for (int i = 1; i < token_count; i += 2) {
        char operator = tokens[i].value[0];
        int operand = atoi(tokens[i + 1].value);
        if (operator == '+') {
            result += operand;
        } else if (operator == '*') {
            result *= operand;
        }
    }
    return result;
}

// Fonction pour évaluer l'expression avec priorité en utilisant l'algorithme de Shunting-yard
int evaluate_with_priority(Token tokens[], int token_count) {
    Token output[100];
    Token stack[100];
    int output_count = 0;
    int stack_count = 0;

    for (int i = 0; i < token_count; i++) {
        if (tokens[i].type == 'i') {
            output[output_count++] = tokens[i];
        } else if (tokens[i].type == 'o') {
            while (stack_count > 0 && stack[stack_count - 1].type == 'o' &&
                   ((tokens[i].value[0] == '+' && (stack[stack_count - 1].value[0] == '+' || stack[stack_count - 1].value[0] == '*')) ||
                    (tokens[i].value[0] == '*' && stack[stack_count - 1].value[0] == '*'))) {
                output[output_count++] = stack[--stack_count];
            }
            stack[stack_count++] = tokens[i];
        }
    }

    while (stack_count > 0) {
        output[output_count++] = stack[--stack_count];
    }

    // Évaluer l'expression postfixée
    int eval_stack[100];
    int eval_stack_count = 0;

    for (int i = 0; i < output_count; i++) {
        if (output[i].type == 'i') {
            eval_stack[eval_stack_count++] = atoi(output[i].value);
        } else if (output[i].type == 'o') {
            int b = eval_stack[--eval_stack_count];
            int a = eval_stack[--eval_stack_count];
            if (output[i].value[0] == '+') {
                eval_stack[eval_stack_count++] = a + b;
            } else if (output[i].value[0] == '*') {
                eval_stack[eval_stack_count++] = a * b;
            }
        }
    }

    return eval_stack[0];
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Commande incorrecte!!!\n Veuillez suivre cet exemple: %s <expression>\n", argv[0]);
        return 1;
    }

    char *expression = argv[1];
    Token tokens[100];
    int token_count = tokenize(expression, tokens);

    printf("Tokens:\n");
    for (int i = 0; i < token_count; i++) {
        if (tokens[i].type == 'i') {
            printf("%s ", afficher(tokens[i].value, "int"));
        } else if (tokens[i].type == 'o') {
            printf("%s ", afficher(tokens[i].value, "operateur"));
        }
    }
    printf("\n");

    int result_without_priority = evaluate_without_priority(tokens, token_count);
    int result_with_priority = evaluate_with_priority(tokens, token_count);

    printf("Évaluation sans priorité : %d\n", result_without_priority);
    printf("Évaluation avec priorité : %d\n", result_with_priority);

    return 0;
}
