#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Function to perform Breadth First Search (BFS)
void BFS(int vertex, int adjMatrix[MAX_VERTICES][MAX_VERTICES], int visited[MAX_VERTICES], int n) {
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;

    printf("\nBFS Traversal: ");
    printf("%c ", vertex + 'A');
    visited[vertex] = 1;
    queue[++rear] = vertex;

    while (front != rear) {
        vertex = queue[++front];
        for (int i = 0; i < n; i++) {
            if (adjMatrix[vertex][i] == 1 && !visited[i]) {
                printf("%c ", i + 'A');
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

// Function to perform Depth First Search (DFS)
void DFS(int vertex, int adjMatrix[MAX_VERTICES][MAX_VERTICES], int visited[MAX_VERTICES], int n) {
    printf("%c ", vertex + 'A');
    visited[vertex] = 1;

    for (int i = 0; i < n; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(i, adjMatrix, visited, n);
        }
    }
}

int main() {
    int n, e;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_VERTICES) {
        printf("Invalid number of vertices. Exiting...\n");
        return 1;
    }

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    int adjMatrix[MAX_VERTICES][MAX_VERTICES] = {0};

    printf("Enter the edge (format: Vertex1 Vertex2):\n");
    for (int i = 0; i < e; i++) {
        char v1, v2;
        scanf(" %c %c", &v1, &v2);
        adjMatrix[v1 - 'A'][v2 - 'A'] = 1;
        adjMatrix[v2 - 'A'][v1 - 'A'] = 1;  // Assuming an undirected graph
    }

    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    int visited[MAX_VERTICES] = {0};

    // BFS Traversal
    BFS(0, adjMatrix, visited, n);
    
    // Reset visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // DFS Traversal
    printf("\nDFS Traversal: ");
    DFS(0, adjMatrix, visited, n);
    printf("\n");
    return 0;
}

