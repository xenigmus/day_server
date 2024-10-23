
#include<stdio.h> 
#include<conio.h> 
#include<malloc.h> 
#include<stdlib.h> 
struct stack 
{ 
int data; 
struct stack *next; 
}; 
struct stack *top=NULL; 
struct stack *push(int value) 
{ 
struct stack *new_node; 
new_node=(struct stack *)malloc(sizeof(struct stack)); 
new_node -> data=value; 
if(top==NULL){ 
new_node -> next = value; 
top=new_node; 
} 
else{ 
new_node->next=top; 
top=new_node; 
} 
} 
int pop() 
{ 
struct stack *ptr; 
if(top==NULL) 
printf("\n Stack underflow"); 
ptr=top; 
top=top->next; 
free(ptr);	 
} 
int peek() 
{ 
    if(top==NULL) 
    return-1; 
else 
return top->data;	 
} 
void display() 
{ 
struct stack *ptr; 
ptr=top; 
if(top==NULL) 
printf("\n stack empty"); 
else{ 
while(ptr!=NULL){ 
printf("\n%d",ptr->data); 
ptr=ptr->next;	 
} 
} 
} 
int main() 
{ 
int ch,val; 
printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n"); 
while(ch<=5){ 
printf("\nEnter the choice"); 
scanf("%d",&ch); 
switch(ch) 
{ 
case 1: printf("Enter the value to be entered in stack"); 
        scanf("%d",&val); 
        push(val); 
        break; 
case 2: val=pop(); 
        if(val!=-1) 
        printf("\nThe value deleted from the stack is:%d",val); 
        break; 
case 3: val=peek(); 
        if(val!=-1) 
        printf("\nThe value at top of stack is:%d",val); 
        break; 
case 4: display(); 
        break; 
case 5: return 0; 
} 
} 
return 0;	 
} 