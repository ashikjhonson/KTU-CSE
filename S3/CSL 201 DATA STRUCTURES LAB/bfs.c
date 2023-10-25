#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
}*new, *curr, *graph[20] = {NULL};

void addEdge(struct node* graph[], int u, int v)
{
    new = malloc(sizeof(struct node));
    new->data = v;
    new->next = graph[u];
    graph[u] = new;
}

void bfs(struct node* graph[], int start, int visited[])
{
    visited[start] = 1;
    printf("%d ", start);

    int queue[20], front =0, rear =0;
    queue[rear++] = start;

    while(front<rear)
    {
        int u = queue[front++];
        curr = graph[u];
        while(curr)
        {
            int v = curr->data;
            if(!visited[v])
            {
                visited[v] = 1;
                printf("%d ",v);
                queue[rear++] = v;
            }
            curr = curr->next;
        }
    }
}

void main()
{
    int n, e;
    scanf("%d%d",&n,&e);

    for(int i=0; i<e; i++)
    {
        int u, v;
        scanf("%d%d",&u,&v);
        addEdge(graph, u, v);
        addEdge(graph, v, u);
    }

    int visited[20] = {0};
    bfs(graph, 0, visited);
}