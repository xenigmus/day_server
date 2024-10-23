//post
#include <stdio.h> 
#include <ctype.h> 
#define MAX 100 
float st[MAX]; 
int top = -1; 
void push (float st[], float val); 
float pop(float st[]); 
float evaluatePostFix (char exp[]); 
int main() { 
float val; 
char exp[100]; 
printf ("Enter Postfix expression: "); 
scanf ("%s", exp); 
val = evaluatePostFix(exp); 
printf ("Ans: %.2f", val); 
return 0; 
} 
float evaluatePostFix (char exp[]) { 
int i=0; 
float op1, op2, value; 
while (exp[i] !='\0') { 
if(isdigit(exp[i])) 
{ 
exp[i] = (float)(exp[i]-'0'); 
push(st, exp[i]);   } 
else  { 
op2 = pop(st); 
op1 = pop(st); 
switch (exp[i]) 
{ 
case '+' : value = op1 + op2; 
break; 
case '-' : value = op1 - op2; 
break; 
case '/' : value = op1 / op2; 
break; 
case '*' : value = op1 * op2; 
break; 
case '%' : value = (int)op1 % (int)op2; 
break;  } 
push(st, value);  } 
i++; 
}  return pop((st)); 
} 
void push (float st[], float val)  { 
if (top == MAX -1) { 
printf ("\n Stack overflow"); 
} 
else  { 
top++; 
st[top] = val; 
}  } 
float pop(float st[]) 
{ 
float val = - 1; 
if (top == -1) 
printf("Stack Overflow"); 
else 
{ 
val = st[top--]; 
return val; 
}  
} 