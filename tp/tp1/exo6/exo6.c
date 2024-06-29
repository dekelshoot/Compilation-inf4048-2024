#include <stdio.h>    // Inclusion de la bibliothèque standard d'entrée/sortie
#include <stdlib.h>   // Inclusion de la bibliothèque standard pour les fonctions utilitaires
#include <string.h>   // Inclusion de la bibliothèque de manipulation des chaînes de caractères
#include "../exo3/AFN.c" // Inclure le fichier AFN.c


// Fonction principale
int main(int argc, char *argv[]) {
    if (argc != 3) { // Vérifier le nombre d'arguments
        fprintf(stderr, "Commande incorrecte!!!\n veillez suivre cet exemple: %s <regex> <input_string>\n", argv[0]); // Afficher l'usage correct
        return 1;
    }

    const char *regex = argv[1]; // Lire la regex
    const char *input = argv[2]; // Lire la chaîne d'entrée

    NFA nfa = regex_to_nfa(regex); // Convertir la regex en AFN

    if (execute_nfa(&nfa, input)) { // Exécuter l'AFN sur la chaîne d'entrée
        printf("La chaine '%s' est acceptée par l'expression '%s'.\n", input, regex); // Correspondance trouvée
    } else {
        printf("La chaine '%s' réfusée par l'expression '%s'.\n", input, regex); // Correspondance non trouvée
    }

    return 0;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            