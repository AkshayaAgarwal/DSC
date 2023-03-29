#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int adj[MAX_VERTICES][MAX_VERTICES]; // adjacency matrix
int visited[MAX_VERTICES]; // array to keep track of visited vertices
int queue[MAX_VERTICES]; // array to implement BFS queue
int stack[MAX_VERTICES]; // array to implement DFS stack
int rear = -1, front = -1; // variables to keep track of the BFS queue
int top = -1; // variable to keep track of the DFS stack

// function to add an edge between two vertices
void addEdge(int u, int v, int n) {
    if (u < 0 || u >= n || v < 0 || v >= n) {
        printf("Invalid vertices\n");
        return;
    }
    adj[u][v] = 1;
    adj[v][u] = 1;
}

// function to perform BFS on the graph
void bfs(int start, int n) {
    if (start < 0 || start >= n) {
        printf("Invalid starting vertex\n");
        return;
    }
    int i;
    visited[start] = 1;
    queue[++rear] = start;
    while (front != rear) {
        int current = queue[++front];
        printf("%d ", current);
        for (i = 0; i < n; i++) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

// function to perform DFS on the graph
void dfs(int start, int n) {
    if (start < 0 || start >= n) {
        printf("Invalid starting vertex\n");
        return;
    }
    int i;
    visited[start] = 1;
    stack[++top] = start;
    printf("%d ", start);
    while (top != -1) {
        int current = stack[top];
        int found = 0;
        for (i = 0; i < n; i++) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                stack[++top] = i;
                printf("%d ", i);
                found = 1;
                break;
            }
        }
        if (found == 0) {
            top--;
        }
    }
}

int main() {
    int i, j, n, option, u, v, start;
    printf("\nBuilding an adjacency matrix to print BFS and DFS\n\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    if (n < 1 || n > MAX_VERTICES) {
        printf("Invalid number of vertices\n");
        return 1;
    }
    while (1) {
        printf("\nMenu\n");
        printf("1. Add an edge\n");
        printf("2. BFS traversal\n");
        printf("3. DFS traversal\n");
        printf("4. Exit\n");
        printf("Enter your option (1-4): ");
        if (scanf("%d", &option) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }
        switch (option) {
            case 1:
                printf("Enter the vertices (u v): ");
                if (scanf("%d %d", &u, &v) != 2) {
                    printf("Invalid input. Please enter two numbers.\n");
                    while (getchar() != '\n');
                    continue;
                }
                if (u < 0 || u >= n || v < 0 || v >= n) {
                    printf("Invalid vertex. Please enter two numbers between 0 and %d.\n", n-1);
                    continue;
                }
                addEdge(u, v, n);
                break;
            case 2:
                printf("Enter the starting vertex: ");
                if (scanf("%d", &start) != 1) {
                    printf("Invalid input. Please enter a number.\n");
                    while (getchar() != '\n');
                    continue;
                }
                if (start < 0 || start >= n) {
                    printf("Invalid vertex. Please enter a number between 0 and %d.\n", n-1);
                    continue;
                }
                for (i = 0; i < n; i++) {
                    visited[i] = 0;
                }
                bfs(start, n);
                break;
            case 3:
                printf("Enter the starting vertex: ");
                if (scanf("%d", &start) != 1) {
                    printf("Invalid input. Please enter a number.\n");
                    while (getchar() != '\n');
                    continue;
                }
                if (start < 0 || start >= n) {
                    printf("Invalid vertex. Please enter a number between 0 and %d.\n", n-1);
                    continue;
                }
                for (i = 0; i < n; i++) {
                    visited[i] = 0;
                }
                dfs(start, n);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option. Please enter a number between 1 and 4.\n");
        }
   }
   return 0;
}
