#include <stdio.h>    // Inclusion de la bibliothèque standard d'entrée/sortie
#include <stdlib.h>   // Inclusion de la bibliothèque standard pour les fonctions utilitaires
#include <string.h>   // Inclusion de la bibliothèque de manipulation des chaînes de caractères
#include "../exo3/AFN.c" // Inclure le fichier AFN.c

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


int main(int argc, char *argv[]) {
    // Vérifier le nombre d'arguments
    if (argc != 2) {
        fprintf(stderr, "Commande incorrecte!!!\n veillez suivre cet exemple: %s <expression>\n", argv[0]); // Afficher l'utilisation correcte
        return 1; // Retourner une erreur
    }

    // Créer les AFN pour les opérateurs et les entiers
    NFA nfa_operators = create_nfa_from_alphabet("+*");
    NFA nfa_integers = create_nfa_from_alphabet("0123456789");

    char *expression = argv[1]; // Lire l'expression fournie en argument
    int length = strlen(expression); // Longueur de l'expression
    char buffer[3]; // Tampon pour stocker les sous-chaînes
    char result[1024] = ""; // Chaîne pour stocker le résultat final
    int i = 0; // Index pour parcourir l'expression

    // Parcourir l'expression
    while (i < length) {
        // Vérifier les entiers de deux caractères
        if (i + 1 < length) {
            strncpy(buffer, &expression[i], 2); // Copier deux caractères
            buffer[2] = '\0'; // Ajouter le caractère de fin de chaîne
            if (execute_nfa(&nfa_integers, buffer)) { // Exécuter l'AFN pour les entiers
                strcat(result, afficher(buffer, "int")); // Ajouter le lexème au résultat
                i += 2; // Avancer de deux positions
                continue; // Passer à l'itération suivante
            }
        }

        // Vérifier les opérateurs
        strncpy(buffer, &expression[i], 1); // Copier un caractère
        buffer[1] = '\0'; // Ajouter le caractère de fin de chaîne
        if (execute_nfa(&nfa_operators, buffer)) { // Exécuter l'AFN pour les opérateurs
            strcat(result, afficher(buffer, "operateur")); // Ajouter le lexème au résultat
            i++; // Avancer d'une position
            continue; // Passer à l'itération suivante
        }

        // Si aucune règle n'a été trouvée, afficher une erreur de syntaxe
        fprintf(stderr, "Parse error at position %d\n", i);
        return 1; // Retourner une erreur
    }

    // Afficher les lexèmes reconnus
    printf("Lexemes: %s\n", result);
    return 0; // Retourner succès
}