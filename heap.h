#pragma once
#ifndef HEAP_H
#define HEAP_H


struct Element
{
	int  v;
	int dist;
};


struct MinHeap
{
	int size;
	int capacity;
	int *position;
	struct Element **array;
};

struct Element* newElement(int v, int dist);
struct MinHeap* createMinHeap(int capacity);
void swapMinHeapNode(struct Element** a, struct Element** b);
void minHeapify(struct MinHeap* minHeap, int idx);
int isEmpty(struct MinHeap* minHeap);
struct Element* extractMin(struct MinHeap* minHeap);
void decreaseKey(struct MinHeap* minHeap, int v, int dist);
bool isInMinHeap(struct MinHeap *minHeap, int v);
void printArr(int dist[], int n);
void dijkstra(struct Graph* graph, int src, int dest, int flag);

#endif
