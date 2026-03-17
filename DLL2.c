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
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to delete a node from the beginning
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL)
        (*head)->prev = NULL;
    free(temp);
    printf("Node deleted from the beginning.\n");
}

// Function to delete a node from the end
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        *head = NULL;
    free(temp);
    printf("Node deleted from the end.\n");
}

// Function to delete a given node
void deleteNode(struct Node** head, int target) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    struct Node* temp = *head;
    while (temp != NULL && temp->data != target)
        temp = temp->next;
    if (temp == NULL) {
        printf("Node with data %d not found.\n", target);
        return;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        *head = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
    printf("Node with data %d deleted.\n", target);
}

// Function to delete a node after a given node
void deleteAfterNode(struct Node* head, int target) {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL && temp->data != target)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL) {
        printf("No node to delete after %d.\n", target);
        return;
    }
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    if (nodeToDelete->next != NULL)
        nodeToDelete->next->prev = temp;
    free(nodeToDelete);
    printf("Node after %d deleted.\n", target);
}

// Function to delete the entire list
void deleteEntireList(struct Node** head) {
    struct Node* temp = *head;
    while (temp != NULL) {
        struct Node* next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
    printf("Entire list deleted.\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice, data, target;

    while (1) {
        printf("\n1. Delete Node from Beginning\n2. Delete Node from End\n3. Delete Given Node\n4. Delete Node After\n5. Delete Entire List\n6. Display List\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                deleteFromBeginning(&head);
                break;
            case 2:
                deleteFromEnd(&head);
                break;
            case 3:
                printf("Enter data of node to delete: ");
                scanf("%d", &target);
                deleteNode(&head, target);
                break;
            case 4:
                printf("Enter data of node after which to delete: ");
                scanf("%d", &target);
                deleteAfterNode(head, target);
                break;
            case 5:
                deleteEntireList(&head);
                break;
            case 6:
                displayList(head);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
