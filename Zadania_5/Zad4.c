#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Func to add element at the end of list
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

// Func to delete exact element from list by index
void remove_by_index(struct Node** head_ref, int index) {
    if (*head_ref == NULL) {
        printf("Lista jest pusta, brak elementów do usunięcia.\n");
        return;
    }
    struct Node* temp = *head_ref;
    // if 1st element gets deleted
    if (index == 0) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    // find element to delete
    for (int i = 0; temp != NULL && i < index - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Given index is out of list.\n");
        return;
    }
    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
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
    int n;

    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);
    append(&head, 6);

    printf("Give index of element that you want to delete: ");
    scanf("%d", &n);
    //Display list before deleting the element
    printf("List before deleting element of %d index: ",n);
    display(head);

    // deleting element of index N
    remove_by_index(&head, n);
    printf("List after deleting element of %d index: ",n);
    display(head);

    return 0;
}