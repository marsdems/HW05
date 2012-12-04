/**********************************************************
* Mike Marsden
* HW05 - Traveling Salesperson Problem 
* GraphAlgs.cpp
**********************************************************/
#include "GraphAlgs.h"
#include "MatrixGraph.h"
#include "ListGraph.h"

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G) {


}

// Method referenced from class lecture notes (11/20)
void tour(NodeID* arr, int n, int startingPoint) {
	if ((n-startingPoint)==1) {

	} else {
		for (int i=startingPoint; i < n; i++) {
			swap(arr,startingPoint,i);
			tour(arr,n,startingPoint+1);
			swap(arr,startingPoint,i);
		}
	}
}

void swap(NodeID* arr, int n1, int n2) {
	NodeID temp = arr[n1];
	arr[n1] = arr[n2];
	arr[n2] = temp;
}