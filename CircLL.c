#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* last = NULL;

void createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (last == NULL) {
        last = newNode;
        last->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}

void displayList() {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = last->next;
    printf("List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("HEAD\n");
}

void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (last == NULL) {
        last = newNode;
        last->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }
}

void insertAtEnd(int data) {
    createNode(data);
}

void insertAfterNode(int data, int after) {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = last->next;
    do {
        if (temp->data == after) {
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = data;
            newNode->next = temp->next;
            temp->next = newNode;
            if (temp == last) {
                last = newNode;
            }
            return;
        }
        temp = temp->next;
    } while (temp != last->next);
    printf("Node with value %d not found\n", after);
}

void deleteFromBeginning() {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = last->next;
    if (last->next == last) {
        last = NULL;
    } else {
        last->next = temp->next;
    }
    printf("Node %d deleted from the beginning\n", temp->data);
    free(temp);
}

void deleteFromEnd() {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = last->next;
    if (last->next == last) {
        printf("Node %d deleted from the end\n", last->data);
        free(last);
        last = NULL;
        return;
    }
    while (temp->next != last) {
        temp = temp->next;
    }
    printf("Node %d deleted from the end\n", last->data);
    free(last);
    temp->next = last->next;
    last = temp;
}

void deleteGivenNode(int value) {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = last->next, *prev;
    if (temp == last && temp->data == value) {
        printf("Node %d deleted\n", last->data);
        free(last);
        last = NULL;
        return;
    }
    do {
        if (temp->data == value) {
            if (temp == last->next) {
                deleteFromBeginning();
                return;
            } else if (temp == last) {
                deleteFromEnd();
                return;
            } else {
                prev->next = temp->next;
                printf("Node %d deleted\n", temp->data);
                free(temp);
                return;
            }
        }
        prev = temp;
        temp = temp->next;
    } while (temp != last->next);
    printf("Node with value %d not found\n", value);
}

int main() {
    int choice, data, after;
    clrscr();

    while (1) {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Create a node\n");
        printf("2. Display the list\n");
        printf("3. Insert at the beginning\n");
        printf("4. Insert at the end\n");
        printf("5. Insert after a given node\n");
        printf("6. Delete from the beginning\n");
        printf("7. Delete from the end\n");
        printf("8. Delete a given node\n");
        printf("9. Exit\n");
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
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 4:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 5:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                printf("Enter the value after which to insert: ");
                scanf("%d", &after);
                insertAfterNode(data, after);
                break;
            case 6:
                deleteFromBeginning();
                break;
            case 7:
                deleteFromEnd();
                break;
            case 8:
                printf("Enter the value of the node to delete: ");
                scanf("%d", &data);
                deleteGivenNode(data);
                break;
            case 9:
                getch();
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
