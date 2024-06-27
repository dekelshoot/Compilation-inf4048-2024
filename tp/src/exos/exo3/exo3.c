#include <stdio.h>    // Inclusion de la bibliothèque standard d'entrée/sortie
#include <stdlib.h>   // Inclusion de la bibliothèque standard pour les fonctions utilitaires
#include <string.h>   // Inclusion de la bibliothèque de manipulation des chaînes de caractères

int main(int argc, char *argv[]) {
    // Vérifie si le nombre d'arguments est correct
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename> <word>\n", argv[0]); // Affiche un message d'erreur
        return 1; // Retourne une erreur
    }

    FILE *file = fopen(argv[1], "r"); // Ouvre le fichier en mode lecture
    if (!file) { // Vérifie si le fichier a été ouvert correctement
        perror("Error opening file"); // Affiche un message d'erreur
        return 1; // Retourne une erreur
    }

    char *word = argv[2]; // Mot à rechercher, passé en argument
    int word_len = strlen(word); // Longueur du mot à rechercher
    int count = 0; // Compteur d'occurrences
    char buffer[1024]; // Tampon pour lire les lignes du fichier

    // Lit le fichier ligne par ligne
    while (fgets(buffer, sizeof(buffer), file)) {
        int state = 0; // État initial de l'automate
        // Parcourt chaque caractère de la ligne
        for (int i = 0; buffer[i] != '\0'; i++) {
            if (buffer[i] == word[state]) { // Si le caractère correspond à l'état courant
                state++; // Passe à l'état suivant
                if (state == word_len) { // Si l'état final est atteint
                    count++; // Incrémente le compteur
                    state = 0; // Réinitialise l'état
                }
            } else {
                state = 0; // Réinitialise l'état si le caractère ne correspond pas
            }
        }
    }

    fclose(file); // Ferme le fichier
    // Affiche le résultat
    printf("The word '%s' occurs %d times in the file.\n", word, count);
    return 0; // Retourne 0 pour indiquer que tout s'est bien passé
}
