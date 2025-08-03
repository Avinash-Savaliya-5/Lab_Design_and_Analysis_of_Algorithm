#include <stdio.h>
#define v 7

void main() {
    int graph[v][v] = {
        {0, 1, 0, 4, 0, 0, 0},
        {1, 0, 2, 6, 4, 0, 0},
        {0, 2, 0, 0, 5, 6, 0},
        {4, 6, 0, 0, 3, 0, 4},
        {0, 4, 5, 3, 0, 8, 7},
        {0, 0, 6, 0, 8, 0, 3},
        {0, 0, 0, 4, 7, 3, 0}
    };


    int edges = 0;
    int min_cost = 0;
    int visited[v] = {0};
    visited[0] = 1;

    printf("Edge \tCost\n");

    while (edges < v - 1) {
        int min = 100000;
        int x = 0, y = 0;

        for (int i = 0; i < v; i++) {
            if (visited[i]==1) {
                for (int j = 0; j < v; j++) {
                    if (!visited[j] && graph[i][j]) {
                        if (graph[i][j] < min) {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        printf("%d - %d\t%d\n", x, y, graph[x][y]);
        visited[y] = 1;
        min_cost += graph[x][y];
        edges++;
    }

    printf("Total edges : %d\n", edges);
    printf("Total cost : %d\n", min_cost);
}
