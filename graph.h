#pragma once
#ifndef GRAPH_H
#define GRAPH_H

struct Node
{
	int dest;
	int weight;
	struct Node* next;
};

struct List
{
	struct Node *head;
	struct Node *tail;
};

struct Graph
{
	int V;
	struct List* A;
};

struct Node* NewNode(int dest, int weight);
struct Graph* createGraph(int V);
void addEdge(struct Graph* graph, int src, int dest, int weight);
void printGraph(struct Graph* graph, int v);
#endif