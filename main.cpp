// Project2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//=============================================================================
#include<fstream>
#include<iostream>
#include "util.h"
#include "heap.h"
#include "graph.h"
#include "main.h"
using namespace std;

int main() {
	char c;
	int i, v, f;
	int nodes, edges;
	//	int *dist = new int[edges];

	struct Graph* graph = NULL;
	struct HEAP* a = NULL;
	//	Element *arr = new Element[50];
	string fileLine;
	//*heap.initialize(10);


	while (1) {
		c = nextcommand(&i, &v, &f);
		//		cin >> c;
		switch (c) {
		case 'e':
		case 'E': {
			printf("The program is going to be terminated.");
			return 0;
		}
				  break;

		case 'c':
		case 'C': {
			if (graph != NULL) {
				dijkstra(graph, i, v, f);

			}
			else {
				cout << "Error:  There is no graph to run Dijkstra's algorithm on." << endl;
			}
		}
				  break;

		case 'i':
		case 'I': {
			ifstream myFile("Ginput.txt");
			if (myFile.is_open()) {
				myFile >> nodes;
				myFile >> edges;
				graph = createGraph(nodes);
				for (int i = 1; i <= edges; i++) {
					int x, y, z;
					myFile >> x;
					myFile >> y;
					myFile >> z;
					if (x == 0 && y == 0 && z == 0) {
						cout << "Error:  The number of edges is less than as specified in the beginning of the file.";
						break;
					}
					addEdge(graph, x, y, z);
					x = 0;
					y = 0;
					z = 0;
				}
			}
			else {
				cout << "There was a problem opening file Ginput.txt for reading." << endl;
			}
			myFile.close();
		}
				  break;

		case 'w':
		case 'W': {
			if (graph != NULL) {
				cout << nodes << " " << edges << endl;
				printGraph(graph, nodes);
			}
			else {
				cout << "Error:  There is no graph to print." << endl;
			}
		}
				  break;

		default: break;
		}
	}
	return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
