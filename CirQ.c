//Circular Queue ADT using array.
#include <stdio.h> 
#define MAX 100 
int queue[MAX]; 
int front = -1, rear = -1; 
void enqueue() { 
    int value; 
    printf("Enter value: "); 
    scanf("%d", &value); 
    if ((front == 0 && rear == MAX - 1) || (rear == (front - 1 + MAX) % MAX)) { 
        printf("OVERFLOW\n"); 
    } else { 
        if (front == -1) { 
            front = rear = 0; 
        } else if (rear == MAX - 1) {  
            rear = 0; 
        } else { 
            rear++; 
        } 
        queue[rear] = value; 
    } 
} 
void dequeue() { 
    int value; 
    if (front == -1) { 
        printf("UNDERFLOW\n"); 
    } else { 
        value = queue[front]; 
        printf("Value dequeued: %d\n", value); 
        if (front == rear) { 
            front = rear = -1; 
        } else if (front == MAX - 1) { 
            front = 0; 
        } else { 
            front++; 
        } 
    } 
} 
void display() { 
    int i; 
    if (front == -1) { 
        printf("UNDERFLOW\n"); 
    } else { 
        if (front <= rear) { 
            for (i = front; i <= rear; i++) 
                printf("\t %d", queue[i]); 
        } else { 
            for (i = front; i < MAX; i++) 
                printf("\t %d", queue[i]); 
            for (i = 0; i <= rear; i++) 
                printf("\t %d", queue[i]); 
        } 
        printf("\n"); 
    } 
} 
int main() { 
    int choice; 
    printf("1.ENQUEUE 2.DEQUEUE 3.DISPLAY\n"); 
    while (1) { 
        printf("Enter choice (1-3): "); 
        scanf("%d", &choice); 
        switch (choice) { 
            case 1: 
                enqueue(); 
                break; 
            case 2: 
                dequeue(); 
                break; 
            case 3: 
                display(); 
                break; 
            default: 
                printf("Invalid choice. Select between (1-3)\n"); 
                break; 
        } 
    } 
    return 0; 
} 