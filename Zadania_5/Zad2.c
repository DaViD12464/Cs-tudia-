#include <stdio.h>
#include <stdlib.h>

//Structure representing list element
struct Node {
    int data;
    struct Node* next;
};

// Func to delete element from list
int pop(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("Lista jest pusta, brak elementów do usunięcia.\n");
        return -1;
    }

    // Check value of 1st element
    int popped_data = (*head_ref)->data;
    struct Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    // Freeing memory from deleted element
    free(temp);
    // Return value of deleted element
    return popped_data;
}

void display(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    // list init
    struct Node* head = NULL;

    // Adding elements to list
    for (int i = 5; i > 0; --i) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = i;
        new_node->next = head;
        head = new_node;
    }

    // Display list before deleting
    printf("List before deleting first element: ");
    display(head);

    int popped_data = pop(&head);
    if (popped_data != -1) {
        printf("Deleted first element with value: %d\n", popped_data);
    }

    // Display list after deleting
    printf("List after deleting first element: ");
    display(head);

    return 0;
}