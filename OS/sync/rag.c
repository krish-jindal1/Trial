#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node
{
    int val;
    struct node *next;
};

struct Graph
{
    int n;
    struct node **adjList;
};

struct node *newNode(int v)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->val = v;
    temp->next = NULL;
    return temp;
}

struct Graph *createGraph(int V)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->n = V;

    graph->adjList = (struct node **)malloc(V * sizeof(struct node *));
    for (int i = 0; i < V; i++)
    {
        graph->adjList[i] = NULL;
    }
    return graph;
}

void addEdge(struct Graph *graph, int src, int dest)
{
    struct node *check = NULL;
    struct node *temp = newNode(dest);

    if (graph->adjList[src] == NULL)
    {
        temp->next = graph->adjList[src];
        graph->adjList[src] = temp;
    }
    else
    {
        check = graph->adjList[src];
        while (check->next != NULL)
        {
            if (check->val == dest)
                return;
            check = check->next;
        }
        check->next = temp;
    }
}

bool ans = 0;

bool dfs(struct Graph *graph, int i, bool vis[], bool cur_vis[])
{
    // printf("%d\n", i);
    vis[i] = 1;
    cur_vis[i] = 1;
    struct node *temp = graph->adjList[i];
    while (temp)
    {
        // printf("----%d\n", i);
        if (cur_vis[temp->val])
            return true;
        if (vis[temp->val])
        {
            temp = temp->next;
            continue;
        }
        if (dfs(graph, temp->val, vis, cur_vis))
            return true;
        temp = temp->next;
    }
    cur_vis[i] = 0;
    return false;
}

int main()
{
    int n = 7;

    // processes : p1,p2,p3 resources : r1,r2,r3,r4
    // equivalent node number :
    // p1 - 0 , p2 - 1 , p3 - 2 , r1 - 3 , r2 - 4 , r3 - 5 , r4 - 6

    char *equival[7] = {"p1", "p2", "p3", "r1", "r2", "r3", "r4"};

    int edges = 6;

    struct Graph *graph = createGraph(n);

    // edges : p1->r1 p2->r3 p3->r2 r1->p2 r2->p2 r3->p3

    addEdge(graph, 0, 3);
    addEdge(graph, 1, 5);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 1);
    addEdge(graph, 4, 1);
    addEdge(graph, 5, 2);

    for (int i = 0; i < n; i++)
    {
        struct node *temp = graph->adjList[i];
        printf("%s : ", equival[i]);
        while (temp)
        {
            printf("%s ", equival[temp->val]);
            temp = temp->next;
        }
        printf("\n");
    }

    bool vis[n + 1], curvis[n + 1];
    memset(vis, false, sizeof(vis));
    memset(curvis, false, sizeof(curvis));

    bool isCycle = false;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i] && dfs(graph, i, vis, curvis))
            isCycle = true;
        if (isCycle)
            break;
    }

    if (isCycle)
        printf("Cycle is there !!\n");
    else
        printf("Cycle is not present !!\n");

    return 0;
}