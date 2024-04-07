#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

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

void remove_first_occurrence(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref, *prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d is not included in the list.\n", key);
        return;
    }

    prev->next = temp->next;
    free(temp);
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
    append(&head, 2);
    append(&head, 5);

    printf("Give Value of element that you want to delete: ");
    scanf("%d", &n);

    printf("List before deleting element of %d value: ",n);
    display(head);

    remove_first_occurrence(&head, n);

    printf("List after deleting element of %d value: ",n);
    display(head);

    return 0;
}