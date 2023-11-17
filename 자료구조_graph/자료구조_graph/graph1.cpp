#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#define TRUE 1
#define FALSE 0

typedef char element;

typedef struct AdjacentVertex
{
	element aName;
	struct AdjacentVertex* next;
}AdjacentVertex;

typedef struct Vertex //Á¤Á¡
{
	element vName;
	AdjacentVertex* aHead;
	struct Vertex* next;
}Vertex;


typedef struct
{
	Vertex* vHead;
}GraphType;

void init(GraphType* G)
{
	G->vHead = NULL;
}

AdjacentVertex* makeAdjacentVertex(Vertex* v, element aName) {
	AdjacentVertex* a = (AdjacentVertex*)malloc(sizeof(AdjacentVertex));
	a->aName = aName;
	a->next = NULL;

	if (v->aHead == NULL)
		v->aHead = a;
	else
	{
		AdjacentVertex* p = v->aHead;
		while (p->next != NULL)
			p = p->next;
		p->next = a;
	}

}

Vertex* findVertex(GraphType* G, element vName)
{
	Vertex* p = G->vHead;

	while (p->vName != vName)
		p = p->next;

	return p;
}

void makeVertex(GraphType* G, element vName)
{
	Vertex* v = (Vertex*)malloc(sizeof(Vertex));
	v->vName = vName;
	v->next = NULL;
	Vertex* p = G->vHead;
	v->aHead = NULL;

	if (p == NULL)
		G->vHead = v;
	else {
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = v;
	}
}

void print(GraphType* G)
{
	Vertex* p = G->vHead;

	for (p; p != NULL; p = p->next) {
		printf("[%c] :", p->vName);
		AdjacentVertex* a = p->aHead;
		while (a != NULL)
		{
			printf("%c ", a->aName);
			a = a->next;
		}
	}
}

void insertEdge(GraphType* G, element v1, element v2)
{
	Vertex* v = findVertex(G, v1);
	makeAdjacentVertex(v, v2);

	Vertex* v3 = findVertex(G, v2);
	makeAdjacentVertex(v3, v1);
}

int main()
{
	GraphType G;
	init(&G);

	makeVertex(&G, 'a'); makeVertex(&G, 'b');
	makeVertex(&G, 'c'); makeVertex(&G, 'd');
	makeVertex(&G, 'e'); makeVertex(&G, 'f');
	makeVertex(&G, 'g'); 


	insertEdge(&G, 'a', 'b'); insertEdge(&G, 'a', 'f');
	insertEdge(&G, 'b', 'c'); insertEdge(&G, 'b', 'g');
	insertEdge(&G, 'c', 'd'); 
	insertEdge(&G, 'd', 'e'); insertEdge(&G, 'd', 'g');
	insertEdge(&G, 'e', 'f'); insertEdge(&G, 'e', 'g');

	print(&G);

	return 0;
}