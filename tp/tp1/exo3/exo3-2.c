#include <stdio.h>    // Inclusion de la bibliothèque standard d'entrée/sortie
#include <stdlib.h>   // Inclusion de la bibliothèque standard pour les fonctions utilitaires
#include <string.h>   // Inclusion de la bibliothèque de manipulation des chaînes de caractères
#include "AFN.c" // Inclure le fichier AFN.c

int main(int argc, char *argv[]) {
    // Vérifie si le nombre d'arguments est correct
    if (argc != 3) {
        fprintf(stderr, "Commande incorrecte!!!\n veillez suivre cet exemple: %s <filename> <word>\n", argv[0]); // Affiche un message d'erreur
        return 1; // Retourne une erreur
    }

    FILE *file = fopen(argv[1], "r"); // Ouvre le fichier en mode lecture
    if (!file) { // Vérifie si le fichier a été ouvert correctement
        perror("Erreur lors de l'ouverture du fichier"); // Affiche un message d'erreur
        return 1; // Retourne une erreur
    }

    NFA nfa = {0}; // Initialiser un AFN vide
    nfa.num_states = 4; // Définir le nombre d'états
    nfa.initial_state = 0; // Définir l'état initial
    add_final_state(&nfa, 3); // Ajouter l'état final

    // Ajouter les transitions
    add_transition(&nfa, 0, 'm', 1);
    add_transition(&nfa, 1, 'u', 2);
    add_transition(&nfa, 2, 'r', 3);

    char *word = argv[2]; // Mot à rechercher, passé en argument
    int word_len = strlen(word); // Longueur du mot à rechercher
    int count = 0; // Compteur d'occurrences
    char buffer[1024]; // Tampon pour lire les lignes du fichier

    // Lit le fichier ligne par ligne
    while (fgets(buffer, sizeof(buffer), file)) {
        char *pos = buffer; // Pointeur sur la ligne courante
        // Parcourir chaque caractère de la ligne jusqu'à la fin de la ligne
        for (char *ptr = pos; *ptr != '\0'; ptr++) {
            // Vérifier si le mot entier est présent à cette position
            char sous_chaine[word_len];  // Déclaration de la chaîne pour stocker la sous-chaîne
            strncpy(sous_chaine, ptr, word_len);  // Copie de la sous-chaîne
            sous_chaine[word_len] = '\0';  // s'ssurer la terminaison de la chaîne

            if(execute_nfa(&nfa, sous_chaine)){
                count++; // Incrémente le compteur
                pos += word_len; // Avance le pointeur après la chaîne trouvée
            }

        }
    }

    fclose(file); // Ferme le fichier
    // Affiche le résultat
    printf("Le mot '%s' est compté %d fois dans le fichier '%s'.\n", word, count,argv[1]);
    return 0; // Retourne 0 pour indiquer que tout s'est bien passé
}
