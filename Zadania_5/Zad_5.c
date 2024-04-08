#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node * next;
}Node_t;

Node_t* createNode(int value){
    Node_t* new_node = (Node_t*) malloc(sizeof (Node_t));
    // Check for errors in memory allocation
    if(new_node == NULL){
        // If null return info about error
        exit(1);
    }
    new_node->val = value;
    new_node->next = NULL;
    return new_node;
}

void addFirst(Node_t ** head, int value){
    Node_t* new_node = createNode(value);
    // Set pointer to the next node to previous head
    new_node->next = *head;
    // Set our node as new head
    *head = new_node;
}

void removeValue(Node_t ** head, int value){
    if(*head == NULL){
        printf("You cannot delete because List is empty\n");
        return;
    }
    // I create to Nodes to point for current and previous element
    Node_t* previous = NULL;
    Node_t* current = *head;
    // We iterate through list until we find our value or we go out of range
    while(current != NULL && current->val != value){
        previous = current;
        current = current->next;
    }
    if(current == NULL){
        printf("Value not found\n");
        return;
    }
    // We check if our value is on first position
    // If yes our remove is a little different because we don't have previous element yet
    if (previous == NULL){
        *head = current->next;
    } else{
        previous->next = current->next;
    }
    free(current);
}

void printList(Node_t* head){
    Node_t* temp = head;
    while (temp != NULL){
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node_t* head = NULL;
    addFirst(&head, 2);
    addFirst(&head, 4);
    addFirst(&head, 2);
    removeValue(&head, 2);

    printList(head);
    return 0;
}
