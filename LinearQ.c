//Implement Linear Queue ADT using array.
#include <stdio.h> 
#include <conio.h> 
#define MAX 5  
int queue[MAX];   
int front = -1, rear = -1; 
void insert(void); 
int delete_element(void); 
void display(void); 
int main() { 
    int option, val; 
    do { 
        printf("\n\n ***** MAIN MENU *****"); 
        printf("\n 1. Insert an element"); 
        printf("\n 2. Delete an element"); 
        printf("\n 3. Display the queue"); 
        printf("\n 4. EXIT"); 
        printf("\n Enter your option : "); 
        scanf("%d", &option); 
        switch(option) { 
            case 1: 
                insert(); 
                break; 
            case 2: 
                val = delete_element(); 
                if (val != -1) 
                    printf("\n The number deleted is : %d", val); 
                break; 
            case 3: 
                display(); 
                break; 
            case 4: 
                printf("\n Exiting..."); 
                break; 
            default: 
                printf("\n Invalid option, please try again."); 
                break; 
        } 
    } while(option != 4); 
    return 0; 
} 
void insert() { 
    int num; 
    printf("\n Enter the number to be inserted in the queue : "); 
    scanf("%d", &num); 
    if(rear == MAX-1) { 
        printf("\n OVERFLOW"); 
    } else if(front == -1 && rear == -1) { 
        front = rear = 0; 
        queue[rear] = num; 
    } else { 
        rear++; 
        queue[rear] = num; 
    } 
} 
int delete_element() { 
    int val; 
    if(front == -1 || front > rear) { 
        printf("\n UNDERFLOW"); 
        return -1; 
    } else { 
        val = queue[front]; 
        front++; 
        if(front > rear) { 
            front = rear = -1; 
        } 
        return val; 
    } 
} 
void display() { 
    int i; 
    printf("\n"); 
    if(front == -1 || front > rear) { 
        printf("\nUNDERFLOW"); 
    } else { 
        for(i = front; i <= rear; i++) { 
            printf("\t %d", queue[i]); 
        } 
        printf("\n"); 
    } 
}