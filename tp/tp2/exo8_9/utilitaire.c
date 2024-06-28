#include <stdio.h>     // Inclusion de la bibliothèque standard d'entrée/sortie
#include <stdlib.h>    // Inclusion de la bibliothèque standard pour la gestion de la mémoire
#include "utilitaire.h" // Inclusion du fichier d'en-tête utilitaire.h

// Fonction pour créer une pile vide
Stack *create_stack() {
    Stack *stack = (Stack *)malloc(sizeof(Stack)); // Allouer de la mémoire pour une nouvelle pile
    if (stack == NULL) { // Vérifier si l'allocation a échoué
        fprintf(stderr, "Erreur d'allocation de mémoire pour la pile\n");
        exit(EXIT_FAILURE); // Sortie du programme en cas d'erreur d'allocation
    }
    stack->top = NULL; // Initialiser le sommet de la pile à NULL
    return stack; // Retourner le pointeur vers la pile nouvellement créée
}

// Fonction pour vérifier si la pile est vide
int stack_is_empty(Stack *stack) {
    return (stack->top == NULL); // Retourne 1 (vrai) si la pile est vide, sinon 0 (faux)
}

// Fonction pour ajouter un élément au sommet de la pile
void stack_push(Stack *stack, char data) {
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode)); // Allouer de la mémoire pour un nouveau nœud de pile
    if (newNode == NULL) { // Vérifier si l'allocation a échoué
        fprintf(stderr, "Erreur d'allocation de mémoire pour un nouveau nœud de pile\n");
        exit(EXIT_FAILURE); // Sortie du programme en cas d'erreur d'allocation
    }
    newNode->data = data; // Assigner la valeur au nouveau nœud
    newNode->next = stack->top; // Le nouveau nœud pointe vers l'ancien sommet de la pile
    stack->top = newNode; // Mettre à jour le sommet de la pile pour qu'il pointe vers le nouveau nœud
}

// Fonction pour retirer et récupérer l'élément du sommet de la pile
char stack_pop(Stack *stack) {
    if (stack_is_empty(stack)) { // Vérifier si la pile est vide
        fprintf(stderr, "Erreur: la pile est vide\n");
        exit(EXIT_FAILURE); // Sortie du programme en cas de tentative de dépilement sur une pile vide
    }
    StackNode *temp = stack->top; // Stocker l'adresse du sommet de la pile
    char data = temp->data; // Récupérer la valeur du sommet de la pile
    stack->top = stack->top->next; // Mettre à jour le sommet de la pile pour qu'il pointe vers le nœud suivant
    free(temp); // Libérer la mémoire du nœud dépilé
    return data; // Retourner la valeur dépilée
}

// Fonction pour récupérer l'élément du sommet de la pile sans le retirer
char stack_top(Stack *stack) {
    if (stack_is_empty(stack)) { // Vérifier si la pile est vide
        fprintf(stderr, "Erreur: la pile est vide\n");
        exit(EXIT_FAILURE); // Sortie du programme en cas de tentative d'accès sur une pile vide
    }
    return stack->top->data; // Retourner la valeur du sommet de la pile
}

// Fonction pour libérer la mémoire utilisée par la pile
void free_stack(Stack *stack) {
    while (!stack_is_empty(stack)) { // Tant que la pile n'est pas vide
        stack_pop(stack); // Dépiler le sommet de la pile
    }
    free(stack); // Libérer la mémoire de la structure de la pile
}

// Fonction pour créer une file vide
Queue *create_queue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue)); // Allouer de la mémoire pour une nouvelle file
    if (queue == NULL) { // Vérifier si l'allocation a échoué
        fprintf(stderr, "Erreur d'allocation de mémoire pour la file\n");
        exit(EXIT_FAILURE); // Sortie du programme en cas d'erreur d'allocation
    }
    queue->front = queue->rear = NULL; // Initialiser le début et la fin de la file à NULL
    return queue; // Retourner le pointeur vers la file nouvellement créée
}

// Fonction pour vérifier si la file est vide
int queue_is_empty(Queue *queue) {
    return (queue->front == NULL); // Retourne 1 (vrai) si la file est vide, sinon 0 (faux)
}

// Fonction pour ajouter un élément à l'arrière de la file
void enqueue(Queue *queue, char data) {
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode)); // Allouer de la mémoire pour un nouveau nœud de file
    if (newNode == NULL) { // Vérifier si l'allocation a échoué
        fprintf(stderr, "Erreur d'allocation de mémoire pour un nouveau nœud de file\n");
        exit(EXIT_FAILURE); // Sortie du programme en cas d'erreur d'allocation
    }
    newNode->data = data; // Assigner la valeur au nouveau nœud
    newNode->next = NULL; // Le nouveau nœud pointe vers NULL car il sera à l'arrière de la file
    if (queue->rear == NULL) { // Si la file est vide
        queue->front = queue->rear = newNode; // Mettre à jour le début et la fin de la file pour qu'ils pointent vers le nouveau nœud
    } else {
        queue->rear->next = newNode; // Ajouter le nouveau nœud à la fin de la file
        queue->rear = newNode; // Mettre à jour la fin de la file pour qu'elle pointe vers le nouveau nœud
    }
}

// Fonction pour retirer et récupérer l'élément à l'avant de la file
char dequeue(Queue *queue) {
    if (queue_is_empty(queue)) { // Vérifier si la file est vide
        fprintf(stderr, "Erreur: la file est vide\n");
        exit(EXIT_FAILURE); // Sortie du programme en cas de tentative de dépilement sur une file vide
    }
    QueueNode *temp = queue->front; // Stocker l'adresse du début de la file
    char data = temp->data; // Récupérer la valeur à l'avant de la file
    queue->front = queue->front->next; // Mettre à jour le début de la file pour qu'il pointe vers le nœud suivant
    if (queue->front == NULL) { // Si la file devient vide après le dépilement
        queue->rear = NULL; // Mettre à jour la fin de la file pour qu'elle soit aussi NULL
    }
    free(temp); // Libérer la mémoire du nœud dépilé
    return data; // Retourner la valeur dépilée
}

// Fonction pour libérer la mémoire utilisée par la file
void free_queue(Queue *queue) {
    while (!queue_is_empty(queue)) { // Tant que la file n'est pas vide
        dequeue(queue); // Dépiler le début de la file
    }
    free(queue); // Libérer la mémoire de la structure de la file
}

// Fonction pour convertir une file en chaîne de caractères
char* queue_to_string(Queue *queue) {
    if (queue == NULL || queue_is_empty(queue)) { // Vérifier si la file est NULL ou vide
        return NULL; // Retourner NULL dans ce cas
    }

    char *result = malloc(sizeof(char) * 1024); // Allouer une chaîne suffisamment grande
    if (result == NULL) { // Vérifier si l'allocation a échoué
        fprintf(stderr, "Erreur d'allocation de mémoire\n");
        exit(1); // Sortie du programme en cas d'erreur d'allocation
    }

    QueueNode *current = queue->front; // Initialiser le pointeur courant au début de la file
    int index = 0; // Initialiser l'index de la chaîne de caractères
    while (current != NULL) { // Parcourir tous les nœuds de la file
        result[index++] = current->data; // Ajouter la valeur du nœud courant à la chaîne
        current = current->next; // Passer au nœud suivant
    }
    result[index] = '\0'; // Ajouter le caractère de fin de chaîne

    return result; // Retourner la chaîne de caractères
}
