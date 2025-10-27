#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX], visited[MAX];

void dfs(int node, int n) {
    visited[node] = 1;
    printf("%d ", node);
    
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i, n);
        }
    }
}

int main() {
    int n = 5;  // Number of nodes
    int edges = 4;  // Number of edges

    // Initialize graph
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    // Graph edges (undirected)
    graph[0][1] = graph[1][0] = 1;
    graph[0][2] = graph[2][0] = 1;
    graph[1][3] = graph[3][1] = 1;
    graph[2][4] = graph[4][2] = 1;

    printf("DFS traversal: ");
    dfs(0, n);  // Starting from node 0
    printf("\n");

    return 0;
}
