#include<iostream>
#include<iomanip>
#include<cstdlib>
#include"graph.h"

using namespace std;


struct Node* NewNode(int dest, int weight) {
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->dest = dest;
	newNode->weight = weight;
	newNode->next = NULL;
	return newNode;
}

struct Graph* createGraph(int V) {
	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
	graph->V = V;
	graph->A = (struct List*) malloc(V * sizeof(struct List));

	for (int i = 0; i <= V; ++i) {
		graph->A[i].head = NULL;
		graph->A[i].tail = NULL;
	}

	return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int weight) {
	struct Node* newN = NewNode(dest, weight);
	if (graph->A[src].head == nullptr) {
		graph->A[src].head = newN;
	}
	else {
		Node* temp = graph->A[src].head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newN;
	}
}

void printGraph(struct Graph* graph, int v) {
	for (int i = 1; i <= v; i++) {
		cout << i << " : ";
		Node* iterator = graph->A[i].head;
		while (iterator != NULL) {
			cout << "(" << iterator->dest << ", " << iterator->weight << ")";
			if (iterator->next != NULL) {
				cout << "; ";
			}
			iterator = iterator->next;
		}
		cout << endl;
	}
}