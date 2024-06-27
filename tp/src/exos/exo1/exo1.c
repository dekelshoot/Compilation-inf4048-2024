#include <stdio.h>    // Inclusion de la bibliothèque standard d'entrée/sortie
#include <stdlib.h>   // Inclusion de la bibliothèque standard pour les fonctions utilitaires
#include <string.h>   // Inclusion de la bibliothèque de manipulation des chaînes de caractères

int main(int argc, char *argv[]) {
    // Vérifie si le nombre d'arguments est correct
    if (argc != 2) {
        fprintf(stderr, "Commande incorrecte!!!\n veillez suivre cet exemple: %s <filename>\n", argv[0]); // Affiche un message d'erreur
        return 1; // Retourne une erreur
    }

    FILE *file = fopen(argv[1], "r"); // Ouvre le fichier en mode lecture
    if (!file) { // Vérifie si le fichier a été ouvert correctement
        perror("Erreur lors de l'ouverture du fichier"); // Affiche un message d'erreur
        return 1; // Retourne une erreur
    }

    char word[] = "mur"; // Chaîne de caractères à rechercher
    int word_len = strlen(word); // Longueur de la chaîne de caractères
    int count = 0; // Compteur d'occurrences
    char buffer[1024]; // Tampon pour lire les lignes du fichier

    // Lit le fichier ligne par ligne
    while (fgets(buffer, sizeof(buffer), file)) {
        char *pos = buffer; // Pointeur sur la ligne courante
        // Recherche la chaîne dans la ligne courante
        while ((pos = strstr(pos, word)) != NULL) {
            count++; // Incrémente le compteur
            pos += word_len; // Avance le pointeur après la chaîne trouvée
        }
    }

    fclose(file); // Ferme le fichier
    // Affiche le résultat
    printf("Le mot '%s' est compté %d fois dans le fichier '%s'.\n", word, count,argv[1]);
    return 0; // Retourne 0 pour indiquer que tout s'est bien passé
}
