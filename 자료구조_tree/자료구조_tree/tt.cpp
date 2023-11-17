#include<stdio.h>
#include<stdlib.h>

#define N 10
#define TRUE 1
#define FALSE 0

typedef int element;

typedef struct
{
	int adjMat[N][N];
	int n;
}GraphType;


void initGraph(GraphType* G)
{
	G->n = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			G->adjMat[i][j] = FALSE;
}

void makeVertex(GraphType* G)
{
	G->n++;

}

void insertEdge(GraphType* G, int u, int v)
{
	G->adjMat[u][v] = G->adjMat[v][u] = TRUE;
}

void print(GraphType* G)
{
	for(int i=0; i<N;)
}

void rDFS(GraphType* G, int s)
{
	visited[s] = TRUE;
	printf("[%d] ", s);

	for (int t = 1; t <= G->n; t++)
		if (G->adjMat[s][t] == 1 && visited[t] == FALSE)
			rDFS(G, t);
}

int main()
{
	GraphType G;
	initGraph(&G);

	int n; scanf("%d", &n);

	for (int i = 0; i < n; i++)
		makeVertex(&G);

	insertEdge(&G, 1, 2); insertEdge(&G, 1, 3); insertEdge(&G, 1, 5);
	insertEdge(&G, 2, 3); insertEdge(&G, 3, 4); insertEdge(&G, 3, 5);
	insertEdge(&G, 4, 5); print(&G); printf("\n");

	rDFS(&G, 4);
}