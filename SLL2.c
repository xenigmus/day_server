#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

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

void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    printf("Node %d deleted from the beginning\n", temp->data);
    free(temp);
}

void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    if (head->next == NULL) {
        printf("Node %d deleted from the end\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    printf("Node %d deleted from the end\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

void deleteGivenNode(int data) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->data == data) {
        struct Node* temp = head;
        head = head->next;
        printf("Node %d deleted from the list\n", temp->data);
        free(temp);
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != data) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Node %d not found in the list\n", data);
    } else {
        struct Node* delNode = temp->next;
        temp->next = delNode->next;
        printf("Node %d deleted from the list\n", delNode->data);
        free(delNode);
    }
}

void deleteAfterNode(int data) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("No node exists after node %d\n", data);
    } else {
        struct Node* delNode = temp->next;
        temp->next = delNode->next;
        printf("Node %d deleted after node %d\n", delNode->data, data);
        free(delNode);
    }
}

void deleteEntireList() {
    struct Node* temp = head;
    while (temp != NULL) {
        struct Node* next = temp->next;
        printf("Deleting node %d\n", temp->data);
        free(temp);
        temp = next;
    }
    head = NULL;
    printf("Entire list deleted\n");
}

void createNode(int data) {
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
}

int main() {
    int choice, data;
    clrscr();

    while (1) {
        printf("\nSingly Linked List Operations:\n");
        printf("1. Create a node\n");
        printf("2. Display the list\n");
        printf("3. Delete a node from the beginning\n");
        printf("4. Delete a node from the end\n");
        printf("5. Delete a given node\n");
        printf("6. Delete a node after a given node\n");
        printf("7. Delete the entire list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                createNode(data);
                break;
            case 2:
                displayList();
                break;
            case 3:
                deleteFromBeginning();
                break;
            case 4:
                deleteFromEnd();
                break;
            case 5:
                printf("Enter the value to delete: ");
                scanf("%d", &data);
                deleteGivenNode(data);
                break;
            case 6:
                printf("Enter the value after which to delete: ");
                scanf("%d", &data);
                deleteAfterNode(data);
                break;
            case 7:
                deleteEntireList();
                break;
            case 8:
                getch();
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
