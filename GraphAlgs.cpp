/**********************************************************
* Mike Marsden
* HW05 - Traveling Salesperson Problem 
* GraphAlgs.cpp
**********************************************************/
#include "GraphAlgs.h"
#include "MatrixGraph.h"
#include "ListGraph.h"

NodeID* bestTour;
NodeID* search;
Graph* graph;
int gSize;

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G) {
	graph = G;
	gSize = G->size();
	bestTour = new NodeID[gSize];
	search = new NodeID[gSize];

	// Citation: Referenced Steven Angles's code to determine
	// how to loop through bestTour and search properly
	// as shown below
	for (int i=0; i < gSize; i++) {
		bestTour[i] = i;
		search[i] = i;
	}
	tour(search, gSize, 0);

	std::vector<NodeID> bestCase (gSize);
	for (int i=0; i < gSize; i++) {
		bestCase[i] = bestTour[i];

	std::pair<std::vector<NodeID>, EdgeWeight > pair (bestCase,getTourLength(bestTour,gSize));
	return pair;
	}
}

// Method referenced from class lecture notes (11/20)
void tour(NodeID* arr, int n, int startingPoint) {
	if ((n-startingPoint)==1) {
		//check is arr is better than best Tour
		if(getTourLength(arr,gSize) < getTourLength(bestTour,gSize))
			bestTour = arr;
	} else {
		for (int i=startingPoint; i < n; i++) {
			swap(arr,startingPoint,i);
			tour(arr,n,startingPoint+1);
			swap(arr,startingPoint,i);
		}
	}
}

EdgeWeight getTourLength(NodeID* tour, int len) {
	EdgeWeight tourLength = 0.0;

	//Loop through to add length of each "line" between points
	for (int i = 0; i < len-1; i++) {
		tourLength += graph->weight(tour[i],tour[i+1]);
	}
	//Grab value from last to first and add on to total.
	tourLength += graph->weight(tour[len-1], tour[0]);
	return tourLength;
}

void swap(NodeID* arr, int n1, int n2) {
	NodeID temp = arr[n1];
	arr[n1] = arr[n2];
	arr[n2] = temp;
}