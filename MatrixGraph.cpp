/**********************************************************
* Mike Marsden
* HW05 - Traveling Sales Person 
* MatrixGraph.cpp
**********************************************************/
#include "MatrixGraph.h"

//Constructor
MatrixGraph::MatrixGraph(unsigned num_nodes) {

	num_edges = 0;
	M.resize(num_nodes);

	for (int i = 0; i < M.size(); i++) {
		M[i].resize(num_nodes);
	}
}

//Destructor
MatrixGraph::~MatrixGraph() {}

//Setter Methods
void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight) {

	// By going u,v and v,u, it makes it undirected.
	M[u][v] = weight;
	M[v][u] = weight;
	num_edges++;
}

//Accessors
EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const {
	EdgeWeight eW = M[u][v];
	return eW;
}

std::list<NWPair> MatrixGraph::getAdj(NodeID u) const {
	std::list<NWPair> adjs = std::list<NWPair>();
	for (int i = 0; i < M.size(); i++) {
		// If this condition is met, there is a weight
		// therefore an adjacent point.
		if (M[u][i] != 0) {
			adjs.push_back(NWPair(i, M[u][i]));
		}
	}

	return adjs;
}

unsigned MatrixGraph::degree(NodeID u) const {
	unsigned degree = 0;
	for (int i = 0; i < M.size(); i++) {
		// Will increment if a weight is found
		if (M[u][i] != 0) {
			degree++;
		}
	}		
	return degree;
} 

unsigned MatrixGraph::size() const {
	return M.size();
}

unsigned MatrixGraph::numEdges() const {
	return num_edges;
}