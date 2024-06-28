#ifndef UTILITAIRE_H
#define UTILITAIRE_H

// Définition de la structure d'un nœud de pile
typedef struct StackNode {
    char data;              // Donnée du nœud
    struct StackNode *next; // Pointeur vers le prochain nœud
} StackNode;

// Structure de la pile
typedef struct {
    StackNode *top; // Pointeur vers le sommet de la pile
} Stack;

// Définition de la structure d'un nœud de file
typedef struct QueueNode {
    char data;                // Donnée du nœud
    struct QueueNode *next;   // Pointeur vers le prochain nœud
} QueueNode;

// Structure de la file
typedef struct {
    QueueNode *front; // Pointeur vers l'avant de la file
    QueueNode *rear;  // Pointeur vers l'arrière de la file
} Queue;

// Prototypes des fonctions pour la pile
Stack *create_stack();
int stack_is_empty(Stack *stack);
void stack_push(Stack *stack, char data);
char stack_pop(Stack *stack);
char stack_top(Stack *stack);
void free_stack(Stack *stack);

// Prototypes des fonctions pour la file
Queue *create_queue();
int queue_is_empty(Queue *queue);
void enqueue(Queue *queue, char data);
char dequeue(Queue *queue);
void free_queue(Queue *queue);
char* queue_to_string(Queue *queue); // Déclaration de queue_to_string()

#endif /* UTILITAIRE_H */
