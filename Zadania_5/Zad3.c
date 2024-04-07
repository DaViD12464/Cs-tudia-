#include <stdio.h>
#include <stdlib.h>

//Structure representing list element
struct Node {
    int data;
    struct Node* next;
};

// Func to add element to the end of list
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// Func to delete last element of list
void remove_last(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("Lista jest pusta, brak elementów do usunięcia.\n");
        return;
    }
    if ((*head_ref)->next == NULL) {
        free(*head_ref);
        *head_ref = NULL;
        return;
    }
    struct Node* second_last = *head_ref;
    while (second_last->next->next != NULL) {
        second_last = second_last->next;
    }
    free(second_last->next);
    second_last->next = NULL;
}

void display(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}


int main() {
    struct Node* head = NULL;

    append(&head, 1);
    append(&head, 2);
    append(&head, 3);

    printf("List before deleting last element: ");
    display(head);

    remove_last(&head);
    printf("List after deleting last element: ");
    display(head);

    return 0;
}