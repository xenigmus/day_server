#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

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

void sortList() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *i, *j;
    int tempData;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                tempData = i->data;
                i->data = j->data;
                j->data = tempData;
            }
        }
    }
    printf("List sorted successfully\n");
}

int main() {
    int choice, data;
    clrscr();

    while (1) {
        printf("\nSingly Linked List Operations:\n");
        printf("1. Create a node\n");
        printf("2. Display the list\n");
        printf("3. Sort the list\n");
        printf("4. Exit\n");
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
                sortList();
                displayList();
                break;
            case 4:
                getch();
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
