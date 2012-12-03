/**********************************************************
* Mike Marsden
* HW05 - Traveling Sales Person 
* MatrixGraph.cpp
**********************************************************/
#include "MatrixGraph.h"

//Constructor
MatrixGraph::MatrixGraph(unsigned num_nodes) {

	num_edges = 0;
}

//Destructor
MatrixGraph::~MatrixGraph() {}

//Setter Methods
void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight) {

}

//Accessors
EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const {
	EdgeWeight eW = M[u][v];
	return eW;
}

unsigned MatrixGraph::degree(NodeID u) const {

}

unsigned MatrixGraph::size() const {
	M.size();
}

unsigned MatrixGraph::numEdges() const {
	return num_edges;
}