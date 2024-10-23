
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