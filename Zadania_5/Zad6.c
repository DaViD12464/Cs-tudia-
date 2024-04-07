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

    printf("Give Value of element that you want to input: ");
    scanf("%d", &n);

    printf("List before adding element of %d value: ",n);
    display(head);

    append(&head, n);

    printf("List after adding element of %d value: ",n);
    display(head);

    return 0;
}