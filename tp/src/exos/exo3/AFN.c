#include <stdio.h>
#include <stdlib.h>

// Définir des constantes pour les limites des états et des symboles
#define MAX_STATES 100
#define MAX_SYMBOLS 26

// Structure représentant une transition dans l'AFN
typedef struct {
    int from;      // État de départ
    char symbol;   // Symbole de transition
    int to;        // État de destination
} Transition;

// Structure représentant un AFN
typedef struct {
    int num_states;            // Nombre total d'états
    int num_transitions;       // Nombre total de transitions
    int initial_state;         // État initial
    int final_states[MAX_STATES]; // Tableau des états finaux
    int num_final_states;      // Nombre d'états finaux
    Transition transitions[MAX_STATES * MAX_SYMBOLS]; // Tableau des transitions
} NFA;

// Fonction pour ajouter une transition à l'AFN
void add_transition(NFA *nfa, int from, char symbol, int to) {
    Transition t = {from, symbol, to}; // Créer une nouvelle transition
    nfa->transitions[nfa->num_transitions++] = t; // Ajouter la transition à l'AFN
}

// Fonction pour ajouter un état final à l'AFN
void add_final_state(NFA *nfa, int state) {
    nfa->final_states[nfa->num_final_states++] = state; // Ajouter l'état final
}

// Fonction pour vérifier si un état est un état final
int is_final_state(NFA *nfa, int state) {
    for (int i = 0; i < nfa->num_final_states; i++) {
        if (nfa->final_states[i] == state) {
            return 1; // Retourner 1 si l'état est final
        }
    }
    return 0; // Retourner 0 si l'état n'est pas final
}

// Fonction pour exécuter l'AFN sur une chaîne d'entrée
int execute_nfa(NFA *nfa, const char *input) {
    int current_states[MAX_STATES]; // Tableau des états courants
    int next_states[MAX_STATES];    // Tableau des prochains états
    int num_current_states = 1;     // Nombre d'états courants
    int num_next_states;            // Nombre de prochains états
    current_states[0] = nfa->initial_state; // Initialiser avec l'état initial

    // Parcourir chaque symbole de la chaîne d'entrée
    for (int i = 0; input[i] != '\0'; i++) {
        char symbol = input[i]; // Lire le symbole courant
        num_next_states = 0;    // Réinitialiser le nombre de prochains états

        // Pour chaque état courant
        for (int j = 0; j < num_current_states; j++) {
            int current_state = current_states[j]; // Lire l'état courant

            // Parcourir toutes les transitions
            for (int k = 0; k < nfa->num_transitions; k++) {
                Transition t = nfa->transitions[k]; // Lire la transition courante
                // Si la transition part de l'état courant et utilise le symbole courant
                if (t.from == current_state && t.symbol == symbol) {
                    next_states[num_next_states++] = t.to; // Ajouter l'état de destination aux prochains états
                }
            }
        }

        // Mettre à jour les états courants pour la prochaine itération
        for (int j = 0; j < num_next_states; j++) {
            current_states[j] = next_states[j];
        }
        num_current_states = num_next_states;

        // Si aucun état n'est atteint, la chaîne est rejetée
        if (num_current_states == 0) {
            return 0;
        }
    }

    // Vérifier si l'un des états courants est un état final
    for (int i = 0; i < num_current_states; i++) {
        if (is_final_state(nfa, current_states[i])) {
            return 1; // Accepter la chaîne si un état final est atteint
        }
    }
    return 0; // Rejeter la chaîne si aucun état final n'est atteint
}

// int main() {
//     NFA nfa = {0}; // Initialiser un AFN vide
//     nfa.num_states = 4; // Définir le nombre d'états
//     nfa.initial_state = 0; // Définir l'état initial
//     add_final_state(&nfa, 3); // Ajouter l'état final

//     // Ajouter les transitions
//     add_transition(&nfa, 0, 'm', 1);
//     add_transition(&nfa, 1, 'u', 2);
//     add_transition(&nfa, 2, 'r', 3);

//     const char *input = "mur"; // Définir la chaîne d'entrée
//     // Exécuter l'AFN sur la chaîne d'entrée et afficher le résultat
//     if (execute_nfa(&nfa, input)) {
//         printf("The input '%s' is accepted by the NFA.\n", input);
//     } else {
//         printf("The input '%s' is rejected by the NFA.\n", input);
//     }

//     return 0; // Terminer le programme
// }
