#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

// Fonction pour créer un AFN qui reconnaît tous les mots d'un alphabet donné de toutes tailles
NFA create_nfa_from_alphabet(const char *alphabet) {
    NFA nfa = {0}; // Initialiser un AFN vide
    nfa.num_states = 2; // Deux états: initial et final
    nfa.initial_state = 0; // Définir l'état initial
    add_final_state(&nfa, 1); // Ajouter l'état final

    // Ajouter les transitions pour chaque symbole de l'alphabet
    for (int i = 0; alphabet[i] != '\0'; i++) {
        add_transition(&nfa, 0, alphabet[i], 1); // Transition de l'état initial à l'état final
        add_transition(&nfa, 1, alphabet[i], 1); // Transition bouclant sur l'état final
    }

    return nfa; // Retourner l'AFN créé
}

// Fonction pour créer un AFN qui reconnaît tous les mots d'un alphabet donné de taille 1
NFA create_nfa_from_alphabet_taille_1(const char *alphabet) {
    NFA nfa = {0}; // Initialiser un AFN vide
    nfa.num_states = 2; // Deux états: initial et final
    nfa.initial_state = 0; // Définir l'état initial
    add_final_state(&nfa, 1); // Ajouter l'état final

    // Ajouter les transitions pour chaque symbole de l'alphabet
    for (int i = 0; alphabet[i] != '\0'; i++) {
        add_transition(&nfa, 0, alphabet[i], 1); // Transition de l'état initial à l'état final
    }

    return nfa; // Retourner l'AFN créé
}

// Fonction pour créer un AFN qui reconnaît la regex ^if.*n$
NFA create_nfa_for_if_n() {
    NFA nfa = {0}; 
    nfa.num_states = 4; 
    nfa.initial_state = 0; 
    add_final_state(&nfa, 3); 

    add_transition(&nfa, 0, 'i', 1);
    add_transition(&nfa, 1, 'f', 2);
    add_transition(&nfa, 2, 'n', 3);
    
    // Ajout des transitions pour le caractère '*' (n'importe quel caractère après 'if')
    for (char c = 'a'; c <= 'z'; c++) {
        add_transition(&nfa, 2, c, 2);
        add_transition(&nfa, 2, c, 3);
    }

    return nfa; 
}

// Fonction pour créer un AFN qui reconnaît la regex [abc]*
NFA create_nfa_for_abc_star() {
    NFA nfa = {0}; 
    nfa.num_states = 2; 
    nfa.initial_state = 0; 
    add_final_state(&nfa, 1); 

    add_transition(&nfa, 0, 'a', 1);
    add_transition(&nfa, 0, 'b', 1);
    add_transition(&nfa, 0, 'c', 1);

    add_transition(&nfa, 1, 'a', 1);
    add_transition(&nfa, 1, 'b', 1);
    add_transition(&nfa, 1, 'c', 1);

    return nfa; 
}


// Fonction pour initialiser un AFN vide
NFA init_nfa() {
    NFA nfa = {0}; // Initialiser tous les champs de l'AFN à 0
    nfa.num_states = 0;
    nfa.num_transitions = 0;
    nfa.initial_state = -1;
    nfa.num_final_states = 0;
    return nfa; // Retourner l'AFN initialisé
}

// Fonction pour créer un AFN pour un seul symbole
NFA create_nfa_for_symbol(char symbol) {
    NFA nfa = init_nfa(); // Initialiser un AFN vide
    nfa.num_states = 2; // Deux états: initial et final
    nfa.initial_state = 0; // Définir l'état initial
    add_final_state(&nfa, 1); // Ajouter l'état final
    add_transition(&nfa, 0, symbol, 1); // Ajouter une transition pour le symbole
    return nfa; // Retourner l'AFN
}

// Fonction pour concaténer deux AFNs
NFA concatenate_nfa(NFA nfa1, NFA nfa2) {
    NFA nfa = init_nfa(); // Initialiser un nouvel AFN
    nfa.num_states = nfa1.num_states + nfa2.num_states; // Nombre d'états total
    nfa.initial_state = nfa1.initial_state; // L'état initial est celui du premier AFN

    // Ajouter les transitions du premier AFN
    for (int i = 0; i < nfa1.num_transitions; i++) {
        add_transition(&nfa, nfa1.transitions[i].from, nfa1.transitions[i].symbol, nfa1.transitions[i].to);
    }

    // Ajouter les transitions du deuxième AFN
    for (int i = 0; i < nfa2.num_transitions; i++) {
        add_transition(&nfa, nfa2.transitions[i].from + nfa1.num_states, nfa2.transitions[i].symbol, nfa2.transitions[i].to + nfa1.num_states);
    }

    // Ajouter les transitions epsilon entre les états finaux du premier AFN et l'état initial du deuxième AFN
    for (int i = 0; i < nfa1.num_final_states; i++) {
        add_transition(&nfa, nfa1.final_states[i], '\0', nfa2.initial_state + nfa1.num_states);
    }

    // Ajouter les états finaux du deuxième AFN
    for (int i = 0; i < nfa2.num_final_states; i++) {
        add_final_state(&nfa, nfa2.final_states[i] + nfa1.num_states);
    }

    return nfa; // Retourner l'AFN résultant
}

// Fonction pour créer un AFN pour une étoile de Kleene
NFA kleene_star_nfa(NFA nfa) {
    NFA star_nfa = init_nfa(); // Initialiser un nouvel AFN
    star_nfa.num_states = nfa.num_states + 2; // Ajouter deux nouveaux états (initial et final)
    star_nfa.initial_state = 0; // Définir le nouvel état initial
    add_final_state(&star_nfa, star_nfa.num_states - 1); // Ajouter le nouvel état final

    // Ajouter les transitions epsilon depuis le nouvel état initial vers l'ancien état initial et le nouvel état final
    add_transition(&star_nfa, star_nfa.initial_state, '\0', nfa.initial_state + 1);
    add_transition(&star_nfa, star_nfa.initial_state, '\0', star_nfa.num_states - 1);

    // Ajouter les transitions de l'ancien AFN, en les décalant
    for (int i = 0; i < nfa.num_transitions; i++) {
        add_transition(&star_nfa, nfa.transitions[i].from + 1, nfa.transitions[i].symbol, nfa.transitions[i].to + 1);
    }

    // Ajouter les transitions epsilon depuis les anciens états finaux vers l'ancien état initial et le nouvel état final
    for (int i = 0; i < nfa.num_final_states; i++) {
        add_transition(&star_nfa, nfa.final_states[i] + 1, '\0', nfa.initial_state + 1);
        add_transition(&star_nfa, nfa.final_states[i] + 1, '\0', star_nfa.num_states - 1);
    }

    return star_nfa; // Retourner l'AFN résultant
}

// Fonction pour créer un AFN pour une union
NFA union_nfa(NFA nfa1, NFA nfa2) {
    NFA nfa = init_nfa(); // Initialiser un nouvel AFN
    nfa.num_states = nfa1.num_states + nfa2.num_states + 2; // Ajouter deux nouveaux états (initial et final)
    nfa.initial_state = 0; // Définir le nouvel état initial
    add_final_state(&nfa, nfa.num_states - 1); // Ajouter le nouvel état final

    // Ajouter les transitions epsilon depuis le nouvel état initial vers les anciens états initiaux
    add_transition(&nfa, nfa.initial_state, '\0', nfa1.initial_state + 1);
    add_transition(&nfa, nfa.initial_state, '\0', nfa2.initial_state + nfa1.num_states + 1);

    // Ajouter les transitions du premier AFN, en les décalant
    for (int i = 0; i < nfa1.num_transitions; i++) {
        add_transition(&nfa, nfa1.transitions[i].from + 1, nfa1.transitions[i].symbol, nfa1.transitions[i].to + 1);
    }

    // Ajouter les transitions du deuxième AFN, en les décalant
    for (int i = 0; i < nfa2.num_transitions; i++) {
        add_transition(&nfa, nfa2.transitions[i].from + nfa1.num_states + 1, nfa2.transitions[i].symbol, nfa2.transitions[i].to + nfa1.num_states + 1);
    }

    // Ajouter les transitions epsilon depuis les anciens états finaux vers le nouvel état final
    for (int i = 0; i < nfa1.num_final_states; i++) {
        add_transition(&nfa, nfa1.final_states[i] + 1, '\0', nfa.num_states - 1);
    }
    for (int i = 0; i < nfa2.num_final_states; i++) {
        add_transition(&nfa, nfa2.final_states[i] + nfa1.num_states + 1, '\0', nfa.num_states - 1);
    }

    return nfa; // Retourner l'AFN résultant
}

// Fonction pour convertir une regex en AFN
NFA regex_to_nfa(const char *regex) {
    NFA nfa_stack[100]; // Pile pour les AFNs
    int stack_top = -1; // Indice du sommet de la pile

    // Parcourir chaque caractère de la regex
    for (int i = 0; i < strlen(regex); i++) {
        if (regex[i] >= 'a' && regex[i] <= 'z') { // Si c'est un symbole
            NFA nfa = create_nfa_for_symbol(regex[i]); // Créer un AFN pour le symbole
            nfa_stack[++stack_top] = nfa; // Pousser l'AFN sur la pile
        } else if (regex[i] == '*') { // Si c'est une étoile de Kleene
            NFA nfa = nfa_stack[stack_top--]; // Dépiler un AFN
            NFA star_nfa = kleene_star_nfa(nfa); // Appliquer l'étoile de Kleene
            nfa_stack[++stack_top] = star_nfa; // Pousser l'AFN résultant sur la pile
        } else if (regex[i] == '.') { // Si c'est une concaténation
            NFA nfa2 = nfa_stack[stack_top--]; // Dépiler deux AFNs
            NFA nfa1 = nfa_stack[stack_top--];
            NFA concat_nfa = concatenate_nfa(nfa1, nfa2); // Concaténer les deux AFNs
            nfa_stack[++stack_top] = concat_nfa; // Pousser l'AFN résultant sur la pile
        } else if (regex[i] == '|') { // Si c'est une union
            NFA nfa2 = nfa_stack[stack_top--]; // Dépiler deux AFNs
            NFA nfa1 = nfa_stack[stack_top--];
            NFA union_nfa_ = union_nfa(nfa1, nfa2); // Réaliser l'union des deux AFNs
            nfa_stack[++stack_top] = union_nfa_; // Pousser l'AFN résultant sur la pile
        } else {
            fprintf(stderr, "Unsupported regex symbol: %c\n", regex[i]); // Erreur pour les symboles non supportés
            exit(1);
        }
    }

    if (stack_top != 0) { // Vérifier si la pile contient exactement un élément
        fprintf(stderr, "Invalid regex\n");
        exit(1);
    }

    return nfa_stack[0]; // Retourner l'AFN résultant
}
