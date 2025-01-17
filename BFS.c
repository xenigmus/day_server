#include <stdio.h> 
#include <stdlib.h> 
#define MAX 5 
void breadth_first_search(int adj[][MAX], int visited[], int start) { 
 int queue[MAX], rear = -1, front = -1, i; 
 queue[++rear] = start;  
 visited[start] = 1; 
 while (rear != front) { 
 start = queue[++front]; 
 printf("%c\t", start + 65); 
for (i = 0; i < MAX; i++) { 
 if (adj[start][i] == 1 && visited[i] == 0) { 
 queue[++rear] = i;  
 visited[i] = 1;  
 } 
 } 
 } 
} 
int main() { 
 int visited[MAX] = {0}; 
 int adj[MAX][MAX], i, j; 
 printf(“\nEnter the adjacency matrix (%d x %d):\n”, MAX, MAX); 
 for (i = 0; i < MAX; i++) { 
 for (j = 0; j < MAX; j++) { 
 scanf("%d",&adj[i][j]);  
 } 
 } 
 breadth_first_search(adj, visited, 0); 
 return 0; 
} 