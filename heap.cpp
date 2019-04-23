#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<stdlib.h>
#include"heap.h"
#include"graph.h"

using namespace std;

struct Element* newElement(int v, int dist) {
	struct Element* minHeapNode = (struct Element*) malloc(sizeof(struct Element));
	minHeapNode->v = v;
	minHeapNode->dist = dist;
	return minHeapNode;
}

struct MinHeap* createMinHeap(int capacity) {
	struct MinHeap* minHeap = (struct MinHeap*) malloc(sizeof(struct MinHeap));
	minHeap->position = (int *)malloc(capacity * sizeof(int));
	minHeap->size = 0;
	minHeap->capacity = capacity;
	minHeap->array = (struct Element**) malloc(capacity * sizeof(struct Element*));
	return minHeap;
}

void swapMinHeapNode(struct Element** a, struct Element** b) {
	struct Element* temp = *a;
	*a = *b;
	*b = temp;
}

void minHeapify(struct MinHeap* minHeap, int idx) {
	int smallest, left, right;
	smallest = idx;
	left = 2 * idx + 1;
	right = 2 * idx + 2;

	if (left < minHeap->size && minHeap->array[left]->dist < minHeap->array[smallest]->dist) {
		smallest = left;
	}

	if (right < minHeap->size && minHeap->array[right]->dist < minHeap->array[smallest]->dist) {
		smallest = right;
	}

	if (smallest != idx) {
		Element *smallestNode = minHeap->array[smallest];
		Element *idxNode = minHeap->array[idx];

		minHeap->position[smallestNode->v] = idx;
		minHeap->position[idxNode->v] = smallest;


		swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);

		minHeapify(minHeap, smallest);
	}
}

int isEmpty(struct MinHeap* minHeap) {
	return minHeap->size == 0;
}

struct Element* extractMin(struct MinHeap* minHeap) {
	if (isEmpty(minHeap)) {
		return NULL;
	}

	struct Element* root = minHeap->array[0];

	struct Element* lastNode = minHeap->array[minHeap->size /*- 1*/];
	minHeap->array[0] = lastNode;


	minHeap->position[root->v] = minHeap->size /*- 1*/;
	minHeap->position[lastNode->v] = 0;

	--minHeap->size;
	minHeapify(minHeap, 0);

	return root;
}


void decreaseKey(struct MinHeap* minHeap, int v, int dist) {

	int i = minHeap->position[v];


	minHeap->array[i]->dist = dist;


	while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist) {
		minHeap->position[minHeap->array[i]->v] = (i - 1) / 2;
		minHeap->position[minHeap->array[(i - 1) / 2]->v] = i;
		swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);

		i = (i - 1) / 2;
	}
}


bool isInMinHeap(struct MinHeap *minHeap, int v) {
	if (minHeap->position[v] <= minHeap->size) {
		return true;
	}
	return false;
}


void printArr(int dist[], int n) {
	printf("Vertex   Distance from Source\n");
	for (int i = 1; i <= n; ++i) {
		printf("%d \t\t %d\n", i, dist[i]);
	}
}


void dijkstra(struct Graph* graph, int src, int dest, int flag) {
	int V = graph->V;
	int *dist = new int[V];
	int *path = new int[V];
	int *parent = new int[V];
	int count = 1;
	int counted = 0;

	struct MinHeap* minHeap = createMinHeap(V);

	for (int v = 0; v <= V; v++) {
		dist[v] = 99999;
		minHeap->array[v] = newElement(v, dist[v]);
		minHeap->position[v] = v;
	}

	minHeap->array[src] = newElement(src, dist[src]);
	minHeap->position[src] = src;
	dist[src] = 0;
	decreaseKey(minHeap, src, dist[src]);

	minHeap->size = V;

	while (!isEmpty(minHeap)) {

		struct Element* element = extractMin(minHeap);
		int u = element->v;
//		cout << "element : " << u << endl;
		path[count] = u;
		if (u == dest) {
			counted = count;
		}
		count++;

		struct Node* iter = graph->A[u].head;
		while (iter != NULL)
		{
			int v = iter->dest;


			if (isInMinHeap(minHeap, v) && dist[u] != 99999 && iter->weight + dist[u] <= dist[v]) {
				dist[v] = dist[u] + iter->weight;
				parent[v] = u;
				decreaseKey(minHeap, v, dist[v]);
			}
			iter = iter->next;
		}
	}

//	printArr(dist, V);
	if (src > V || src < 0) {
		cout << "Error:  One or more of the nodes is invalid." << endl;
	}
	else if (dest > V || dest < 0) {
		cout << "Error:  One or more of the nodes is invalid." << endl;
	}

	if (flag == 0 && dist[dest] != 99999) {
		cout << "LENGTH: " << dist[dest] << endl;
	}
	else if (flag == 1 && dist[dest] != 99999) {
		cout << "PATH: ";
		//for (int i = 1; i <= counted; i++) {
		//	cout << parent[i] << ", ";
		//}

		for (int i = 1; i <= counted; i++) {
			cout << path[i] << ", ";
		}
		cout << endl;
	}
	else {
		cout << "Error:  Invalid flag value." << endl;
	}
	if (dist[dest] == 99999) {
		printf("Sorry, node %d is not reachable from node %d.", dest, src);
		cout << endl;
	}
}
