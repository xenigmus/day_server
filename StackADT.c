#include<stdio.h> 
#include<conio.h> 
#define MAX 20 

int st[MAX],top=-1; 
void push(int st[],int val) 
{ 
if(top==MAX-1) 
printf("\n Stack Overflow"); 
else{ 
top++; 
st[top]=val; 
}
} 
int pop(int st[]) 
{ 
int val; 
if(top==-1) 
printf("\n Stack Underflow"); 
else{ 
val=st[top]; 
top--; 
} 
} 
int peek(int st[]) 
{ 
    if(top==-1) 
printf("\n Stack is empty"); 
else 
return st[top];	 
} 
void display(int st[]) 
{ 
int i; 
if(top==-1) 
printf("\n Stack Empty"); 
else{ 
for(i=top;i>=0;i--) 
printf("%d \t",st[i]); 
} 
} 
int main() 
{ 
int ch,val; 
printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n"); 
while(ch<=5){ 
printf("\nEnter choice :"); 
scanf("%d",&ch); 
switch(ch) 
{ 
case 1: printf("Enter value to append in stack :"); 
        scanf("%d",&val); 
        push(st,val); 
        break; 
case 2: val=pop(st); 
        if(val!=-1) 
        printf("\nDeleted Value :%d",val); 
        break; 
case 3: val=peek(st); 
        if(val!=-1) 
        printf("\nTop value of stack : %d",val); 
        break; 
case 4: display(st); 
        break; 
case 5: return 0; 
} 
} 
return 0;	 
} 
