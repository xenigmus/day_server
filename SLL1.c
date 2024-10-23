#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void createList(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    head = newNode;
    printf("List created with node %d\n", data);
}

void displayList() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void addAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("Node %d added at the beginning\n", data);
}

void addAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Node %d added at the end\n", data);
}

void addBeforeNode(int beforeData, int data) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head->data == beforeData) {
        newNode->next = head;
        head = newNode;
        printf("Node %d added before %d\n", data, beforeData);
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != beforeData) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Node %d not found in the list\n", beforeData);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Node %d added before %d\n", data, beforeData);
    }
}

void addAfterNode(int afterData, int data) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != afterData) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node %d not found in the list\n", afterData);
    } else {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Node %d added after %d\n", data, afterData);
    }
}

int main() {
    int choice, data, nodeData;
    clrscr();

    while (1) {
        printf("\nSingly Linked List Operations:\n");
        printf("1. Create a list\n");
        printf("2. Display the list\n");
        printf("3. Add a node at the beginning\n");
        printf("4. Add a node at the end\n");
        printf("5. Add a node before a given node\n");
        printf("6. Add a node after a given node\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value for the first node: ");
                scanf("%d", &data);
                createList(data);
                break;
            case 2:
                displayList();
                break;
            case 3:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &data);
                addAtBeginning(data);
                break;
            case 4:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &data);
                addAtEnd(data);
                break;
            case 5:
                printf("Enter the value before which you want to insert: ");
                scanf("%d", &nodeData);
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                addBeforeNode(nodeData, data);
                break;
            case 6:
                printf("Enter the value after which you want to insert: ");
                scanf("%d", &nodeData);
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                addAfterNode(nodeData, data);
                break;
            case 7:
                getch();
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
