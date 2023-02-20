#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000

typedef struct node {
    int data;
    struct node* next;
} Node;

void addEdge(Node* graph[], int u, int v) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = v;
    new_node->next = graph[u];
    graph[u] = new_node;
}

void bfs(Node* graph[], int start, int visited[]) {
    visited[start] = 1;
    printf("%d ", start);
    // Create a queue for BFS
    int queue[MAX_NODES];
    int front = 0, rear = 0;
    queue[rear++] = start;

    while (front < rear) {
        int u = queue[front++];
        // Traverse all adjacent vertices of u
        Node* curr = graph[u];
        while (curr != NULL) {
            int v = curr->data;
            if (!visited[v]) {
                visited[v] = 1;
                printf("%d ", v);
                queue[rear++] = v;
            }
            curr = curr->next;
        }
    }
}

int main() {
    Node* graph[MAX_NODES] = {NULL};
    int num_nodes, num_edges;
    scanf("%d %d", &num_nodes, &num_edges);
    for (int i = 0; i < num_edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
        addEdge(graph, v, u);
    }

    int visited[MAX_NODES] = {0};
    bfs(graph, 0, visited);

    return 0;
}
