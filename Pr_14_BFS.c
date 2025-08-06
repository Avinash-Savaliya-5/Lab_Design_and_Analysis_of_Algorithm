#include<stdio.h>
#include <stdbool.h>

#define V 8

int queue[V - 1] = {0};
int front = -1, rear = -1;

void enqueue(int x) {
    rear = (rear + 1) % (V - 1);
    queue[rear] = x;
    if(front == -1) {
        front++;
    }
}

int dequeue() {
    int x = queue[front];
    if(front == rear) {
        front = -1;
        rear = -1;
    }
    else {
        front = (front + 1) % (V - 1);
    }
    return x;
}

bool isEmpty() {
    return front == -1 ? true : false;
}

void bfsHelper(int adjacencyMatrix[V][V], int visited[], int key) {
    visited[key] = 1;
    enqueue(key);
    while(!isEmpty()) {
        int x = dequeue();
        printf("%d ", x);
        
        for(int i=0; i<V; i++) {
            if(visited[i] == 0 && adjacencyMatrix[x][i] != 0) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

void bfs(int adjacencyMatrix[V][V]) {
    int visited[V] = {0};
    bfsHelper(adjacencyMatrix, visited, 0);
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

    bfs(adjacencyMatrix);
}