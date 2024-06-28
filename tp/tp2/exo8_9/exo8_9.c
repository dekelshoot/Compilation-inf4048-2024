#include <stdio.h> // Inclusion de la bibliothèque standard d'entrée/sortie
#include <stdlib.h> // Inclusion de la bibliothèque standard pour la gestion de la mémoire
#include "utilitaire.h" // Inclusion du fichier d'en-tête utilitaire.h
#include "../../tp1/exo3/AFN.c" // Inclusion du fichier source AFN.c pour les fonctions liées aux AFN

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

// Fonction pour analyser une expression et extraire les lexèmes
int analyser(char* expression) {
    NFA nfa_operators = create_nfa_from_alphabet("+*"); // Créer l'AFN pour les opérateurs
    NFA nfa_integers = create_nfa_from_alphabet("0123456789"); // Créer l'AFN pour les entiers

    int length = strlen(expression); // Longueur de l'expression
    char buffer[1024]; // Tampon pour stocker les sous-chaînes
    char result[1024] = ""; // Chaîne pour stocker le résultat final
    int i = 0; // Index pour parcourir l'expression

    // Parcourir l'expression
    while (i < length) {
        int j = 0;
        while (i + j < length) { // Vérifier les entiers de longueur variable
            buffer[j] = expression[i + j];
            buffer[j + 1] = '\0';
            if (!execute_nfa(&nfa_integers, buffer)) { // Si ce n'est pas un entier, arrêter la boucle
                buffer[j] = '\0';
                break;
            }
            j++;
        }

        if (j > 0) { // Si un entier est trouvé
            strcat(result, afficher(buffer, "int")); // Ajouter l'entier formaté au résultat
            i += j; // Avancer l'index de la longueur de l'entier
            continue;
        }

        strncpy(buffer, &expression[i], 1); // Vérifier les opérateurs
        buffer[1] = '\0';
        if (execute_nfa(&nfa_operators, buffer)) { // Si c'est un opérateur
            strcat(result, afficher(buffer, "operateur")); // Ajouter l'opérateur formaté au résultat
            i++; // Avancer l'index d'une position
            continue;
        }

        fprintf(stderr, "Parse error at position %d\n", i); // Si aucune règle n'est trouvée, afficher une erreur
        return 1; // Retourner une erreur
    }

    printf("Lexemes: %s\n", result); // Afficher les lexèmes reconnus
    return 0; // Retourner succès
}

// Fonction pour vérifier un lexème en utilisant les AFN
int check(const char *input, int type) {
    NFA nfa_operators = create_nfa_from_alphabet("+*"); // Créer l'AFN pour les opérateurs
    NFA nfa_integers = create_nfa_from_alphabet("0123456789"); // Créer l'AFN pour les entiers

    if (type == 1) {
        return execute_nfa(&nfa_integers, input); // Vérifier si l'input est un entier
    }
    if (type == 2) {
        return execute_nfa(&nfa_operators, input); // Vérifier si l'input est un opérateur
    }
}

// Fonction pour convertir une expression infixée en postfixée
void infix_to_postfix(const char *expression, char *output) {
    Stack *stack = create_stack(); // Créer une pile
    Queue *queue = create_queue(); // Créer une file
    char buffer[3]; // Tampon pour stocker les sous-chaînes

    int i = 0;
    while (expression[i] != '\0') {
        buffer[0] = expression[i];
        buffer[1] = '\0';
        if (check(buffer, 1)) { // Si c'est un entier
            enqueue(queue, expression[i]);
        } else if (check(buffer, 2)) { // Si c'est un opérateur
            while (!stack_is_empty(stack) && stack_top(stack) != '(') {
                enqueue(queue, stack_pop(stack));
            }
            stack_push(stack, expression[i]);
        } else if (expression[i] == '(') { // Si c'est une parenthèse ouvrante
            stack_push(stack, expression[i]);
        } else if (expression[i] == ')') { // Si c'est une parenthèse fermante
            while (!stack_is_empty(stack) && stack_top(stack) != '(') {
                enqueue(queue, stack_pop(stack));
            }
            stack_pop(stack); // Dépiler '('
        }
        i++;
    }

    while (!stack_is_empty(stack)) { // Dépiler les opérateurs restants
        enqueue(queue, stack_pop(stack));
    }

    i = 0; // Copier le contenu de la file en tant que chaîne de sortie
    while (!queue_is_empty(queue)) {
        output[i++] = dequeue(queue);
    }
    output[i] = '\0';

    free_stack(stack); // Libérer la mémoire de la pile
    free_queue(queue); // Libérer la mémoire de la file
}

// Fonction pour obtenir la priorité des opérateurs
int get_priority(char op) {
    if (op == '+' || op == '-') {
        return 1; // Priorité pour addition et soustraction
    } else if (op == '*' || op == '/') {
        return 2; // Priorité pour multiplication et division
    }
    return 0; // Priorité par défaut
}

// Fonction pour convertir une expression infixée en postfixée (Shunting-yard)
char* infix_to_postfix2(const char *expression) {
    Stack *stack = create_stack(); // Créer une pile
    Queue *queue = create_queue(); // Créer une file
    char buffer[3]; // Tampon pour stocker les sous-chaînes

    int i = 0;
    while (expression[i] != '\0') {
        buffer[0] = expression[i];
        buffer[1] = '\0';
        if (check(buffer, 1)) { // Si c'est un entier
            enqueue(queue, expression[i]);
        } else if (check(buffer, 2)) { // Si c'est un opérateur
            while (!stack_is_empty(stack) && get_priority(stack_top(stack)) >= get_priority(expression[i])) {
                enqueue(queue, stack_pop(stack));
            }
            stack_push(stack, expression[i]);
        } else if (expression[i] == '(') { // Si c'est une parenthèse ouvrante
            stack_push(stack, expression[i]);
        } else if (expression[i] == ')') { // Si c'est une parenthèse fermante
            while (!stack_is_empty(stack) && stack_top(stack) != '(') {
                enqueue(queue, stack_pop(stack));
            }
            stack_pop(stack); // Dépiler '('
        }
        i++;
    }

    while (!stack_is_empty(stack)) { // Dépiler les opérateurs restants
        enqueue(queue, stack_pop(stack));
    }

    char *postfix = queue_to_string(queue); // Convertir la file en chaîne de caractères
    free_stack(stack); // Libérer la mémoire de la pile
    free_queue(queue); // Libérer la mémoire de la file
    return postfix; // Retourner la chaîne postfixée
}

// Fonction pour évaluer une expression postfixée sans priorité des opérateurs
int evaluate_postfix(const char *expression) {
    Stack *stack = create_stack(); // Créer une pile
    char buffer[3]; // Tampon pour stocker les sous-chaînes
    int i = 0;
    while (expression[i] != '\0') {
        buffer[0] = expression[i];
        buffer[1] = '\0';
        if (check(buffer, 1)) { // Si c'est un entier
            stack_push(stack, expression[i] - '0'); // Convertir le caractère en nombre entier
        } else if (expression[i] == '+') { // Si c'est une addition
            int operand2 = stack_pop(stack); // Récupérer le deuxième opérande
            int operand1 = stack_pop(stack); // Récupérer le premier opérande
            stack_push(stack, operand1 + operand2); // Pousser le résultat sur la pile
        } else if (expression[i] == '*') { // Si c'est une multiplication
            int operand2 = stack_pop(stack); // Récupérer le deuxième opérande
            int operand1 = stack_pop(stack); // Récupérer le premier opérande
            stack_push(stack, operand1 * operand2); // Pousser le résultat sur la pile
        }
        i++;
    }

    int result = stack_pop(stack); // Récupérer le résultat final
    free_stack(stack); // Libérer la mémoire de la pile
    return result; // Retourner le résultat
}

// Fonction principale
int main(int argc, char *argv[]) {
    if (argc != 2) { // Vérifier si l'argument de l'expression est fourni
        fprintf(stderr, "Usage: %s <expression>\n", argv[0]); // Afficher un message d'utilisation
        return EXIT_FAILURE; // Retourner une erreur
    }

    char postfix[100]; // Chaîne pour stocker l'expression postfixée sans priorité
    printf("Expression: %s\n", argv[1]); // Afficher l'expression fournie
    analyser(argv[1]); // Analyser l'expression
    infix_to_postfix(argv[1], postfix); // Convertir l'expression en postfixée sans priorité
    printf("Postfixe sans priorité: %s\n", postfix); // Afficher l'expression postfixée sans priorité
    char *postfix2 = infix_to_postfix2(argv[1]); // Convertir l'expression en postfixée avec priorité
    printf("Postfixé avec priorité: %s\n", postfix2); // Afficher l'expression postfixée avec priorité

    int result_without_priority = evaluate_postfix(postfix); // Évaluer l'expression postfixée sans priorité
    printf("Évaluation sans priorité : %d\n", result_without_priority); // Afficher le résultat sans priorité

    int result_with_priority = evaluate_postfix(postfix2); // Évaluer l'expression postfixée avec priorité
    printf("Évaluation avec priorité : %d\n", result_with_priority); // Afficher le résultat avec priorité

    return EXIT_SUCCESS; // Retourner succès
}
