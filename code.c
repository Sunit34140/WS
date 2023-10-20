#include <stdio.h>
#include <stdlib.h>

// Structure d'un élément de liste
typedef struct ListNode {
    int data;                // Donnée de l'élément
    struct ListNode* next;   // Pointeur vers l'élément suivant
} ListNode;

// Structure de la liste
typedef struct LinkedList {
    ListNode* head; // Pointeur vers le premier élément de la liste
} LinkedList;

// Fonction pour initialiser une nouvelle liste
LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if (list == NULL) {
        perror("Erreur d'allocation de mémoire pour la liste");
        exit(EXIT_FAILURE);
    }

    list->head = NULL; // La liste est vide pour l'instant

    return list;
}

// Fonction pour insérer un nouvel élément en début de liste
void insertElement(LinkedList* list, int newData) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        perror("Erreur d'allocation de mémoire pour le nouvel élément");
        exit(EXIT_FAILURE);
    }

    newNode->data = newData;
    newNode->next = list->head;
    list->head = newNode;
}

// Fonction pour supprimer le premier élément de la liste
void removeElement(LinkedList* list) {
    if (list->head != NULL) {
        ListNode* elementToRemove = list->head;
        list->head = list->head->next;
        free(elementToRemove);
    } else {
        printf("La liste est vide. Impossible de supprimer un élément.\n");
    }
}

// Fonction pour afficher les éléments de la liste
void displayList(LinkedList* list) {
    if (list == NULL) {
        perror("La liste est NULL");
        exit(EXIT_FAILURE);
    }

    ListNode* current = list->head;

    printf("Liste : ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Fonction pour libérer la mémoire de la liste
void freeLinkedList(LinkedList* list) {
    while (list->head != NULL) {
        removeElement(list);
    }
    free(list);
}

int main() {
    LinkedList* myList = createLinkedList();

    insertElement(myList, 4);
    insertElement(myList, 8);
    insertElement(myList, 15);
    removeElement(myList);

    displayList(myList);

    freeLinkedList(myList); // Libérer la mémoire de la liste

    return 0;
}
