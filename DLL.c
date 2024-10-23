#include <stdio.h>
#include <stdlib.h>

// Define the structure of a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to display the list
void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to add a node at the beginning
void addAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

// Function to add a node at the end
void addAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to add a node before a given node
void addBeforeNode(struct Node** head, int target, int data) {
    if (*head == NULL) return;
    struct Node* temp = *head;
    while (temp != NULL && temp->data != target)
        temp = temp->next;
    if (temp == NULL) {
        printf("Target node not found.\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp;
    newNode->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = newNode;
    else
        *head = newNode;
    temp->prev = newNode;
}

// Function to add a node after a given node
void addAfterNode(struct Node* head, int target, int data) {
    if (head == NULL) return;
    struct Node* temp = head;
    while (temp != NULL && temp->data != target)
        temp = temp->next;
    if (temp == NULL) {
        printf("Target node not found.\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->prev = temp;
    newNode->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice, data, target;

    while (1) {
        printf("\n1. Create List\n2. Display List\n3. Add Node at Beginning\n4. Add Node at End\n5. Add Node Before\n6. Add Node After\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to create list: ");
                scanf("%d", &data);
                addAtEnd(&head, data);
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                printf("Enter data to add at beginning: ");
                scanf("%d", &data);
                addAtBeginning(&head, data);
                break;
            case 4:
                printf("Enter data to add at end: ");
                scanf("%d", &data);
                addAtEnd(&head, data);
                break;
            case 5:
                printf("Enter target node data before which to insert: ");
                scanf("%d", &target);
                printf("Enter data to add before %d: ", target);
                scanf("%d", &data);
                addBeforeNode(&head, target, data);
                break;
            case 6:
                printf("Enter target node data after which to insert: ");
                scanf("%d", &target);
                printf("Enter data to add after %d: ", target);
                scanf("%d", &data);
                addAfterNode(head, target, data);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
