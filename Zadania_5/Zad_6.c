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

void addAtIndex(Node_t ** head, unsigned int index, int value){
    Node_t *newNode = createNode(value);
    if(index == 0){
        newNode->next = *head;
        *head = newNode;
        return;
    }
    // I create to Nodes to point for current and previous element
    Node_t* previous = NULL;
    Node_t* current = *head;
    int count = 0;
    // We iterate through list until we find our index or we go out of range
    while (current != NULL && count != index){
        previous = current;
        current = current->next;
        count++;
    }
    // If we go out of range that means our index doesn't exist
    if(current == NULL){
        printf("Index is out of List\n");
        return;
    }
    // If not then we add our newNode in place of current
    previous->next = newNode;
    newNode->next = current;
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
    addFirst(&head,3);

    printList(head);
    addAtIndex(&head, 1, 5);
    printList(head);
    return 0;
}
