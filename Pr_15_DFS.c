#include<stdio.h>

#define V 8

void dfsHelper(int adjacencyMatrix[V][V], int visited[], int key) {
    visited[key] = 1;
    printf("%d ", key);
    for(int i=0; i<V; i++) {
        if(visited[i] == 0 && adjacencyMatrix[key][i] != 0) {
            dfsHelper(adjacencyMatrix, visited, i);
        }
    }
}

void dfs(int adjacencyMatrix[V][V]) {
    int visited[V] = {0};
    dfsHelper(adjacencyMatrix, visited, 0);
}

void main() {
    int adjacencyMatrix[V][V] = {
        {0, 1, 1, 1, 1, 0, 0, 0},
        {1, 0, 0, 0, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 0, 1, 0},
        {1, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 1, 1, 0, 0, 1},
        {0, 0, 0, 0, 0, 1, 1, 0}
    };

    dfs(adjacencyMatrix);
}