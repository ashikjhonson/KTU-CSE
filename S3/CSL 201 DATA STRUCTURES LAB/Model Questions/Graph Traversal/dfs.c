#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
}*graph[20] = {NULL}, *new, *curr;

void addEdge(struct node* graph[], int u, int v)
{
    new = malloc(sizeof(struct node));
    new->data = v;
    new->next = graph[u];
    graph[u] = new;
}

void dfs(struct node* graph[], int v, int visited[])
{
    visited[v] = 1;
    printf("%d ",v);

    curr = graph[v];
    while(curr)
    {
        int u = curr->data;
        if(!visited[u])
            dfs(graph, u, visited);
        
        if(curr)
            curr = curr->next;
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
    dfs(graph, 0, visited);
}
