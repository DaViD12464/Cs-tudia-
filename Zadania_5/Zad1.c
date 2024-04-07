#include <stdio.h>
#include <stdlib.h>

//Structure representing list element
struct Node {
    int data;
    struct Node*    next;
};

void add_first(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof (struct Node));
    new_node  -> data = new_data;
    new_node -> next = (*head_ref); // New element pointing at current beginning of list
    (*head_ref) = new_node; // Setting new element as beginning of list
}

void display(struct Node* node){
    while (node!=NULL)
    {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node* head = NULL;

    add_first(&head,3);
    add_first(&head,2);
    add_first(&head,1);

    display(head);
    return 0;
}
