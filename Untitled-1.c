#include <stdio.h>

void main() {
    int v = 5;

    int graph[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int edges = 0, min_cost = 0;
    int visited[5] = {0};
    visited[0] = 1;

    printf("Edges\tCost\n");
    while(edges < v - 1) {
        int x = 0, y = 0, min = 9999;
        for(int i = 0; i < v; i++) {
            if(visited[i]) {
                for(int j = 0; j < v; j++) {
                    if(!visited[j] && graph[i][j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        printf("%d - %d\t%d\n", x, y, min);
        min_cost += min;
        visited[y] = 1;
        edges++;
    }

    printf("Total edges = %d\n", edges);
    printf("Minimum cost = %d\n", min_cost);
}