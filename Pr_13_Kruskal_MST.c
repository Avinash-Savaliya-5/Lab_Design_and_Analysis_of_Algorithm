#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int source;
    int destination;
    int weight;
};

int cmp(const void *a, const void *b) {
    struct Edge *edge1 = (struct Edge *)a;
    struct Edge *edge2 = (struct Edge *)b;
    return edge1->weight - edge2->weight;
}

int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

void unionSet(int parent[], int u, int v) {
    parent[u] = v;
}

int findMinCost(int V, int E, struct Edge edges[]) {
    int parent[V];
    struct Edge mst[V - 1];
    int edge = 0;
    int minCost = 0;

    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    qsort(edges, E, sizeof(struct Edge), cmp);

    for (int i = 0; i < E; i++) {
        int u = edges[i].source;
        int v = edges[i].destination;
        int cost = edges[i].weight;

        int ucomp = find(parent, u);
        int vcomp = find(parent, v);

        if (ucomp != vcomp) {
            printf("%d - %d = %d\n", u, v, cost);
            mst[edge++] = edges[i];
            minCost += cost;
            unionSet(parent, ucomp, vcomp);

            if (edge == V - 1) break;
        }
    }

    return minCost;
}

int main() {
    int V = 7;
    int E = 12;

    struct Edge edges[] = {
        {0, 1, 1},
        {1, 2, 2},
        {2, 5, 6},
        {5, 6, 3},
        {3, 6, 4},
        {0, 3, 4},
        {3, 4, 3},
        {4, 5, 8},
        {1, 3, 6},
        {1, 4, 4},
        {2, 4, 5},
        {4, 6, 7}
    };

    int minCost = findMinCost(V, E, edges);
    printf("Minimum cost = %d\n", minCost);

    return 0;
}