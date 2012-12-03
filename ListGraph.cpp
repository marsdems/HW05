/**********************************************************
* Mike Marsden
* HW05 - Traveling Sales Person 
* ListGraph.cpp
**********************************************************/
#include "ListGraph.h"

//Constructor
ListGraph::ListGraph(int numNodes) {

}

//Destructor
ListGraph::~ListGraph() { }

void ListGraph::addEdge(NodeID u, Node v, EdgeWeight weight) {

}

EdgeWeight ListGraph::weight(NodeID u, NodeID v) const {

}

std::list<NWPair> ListGraph::getAdj(NodeID u) const {

}

unsigned ListGraph::degree(NodeID u) const {

}

unsigned ListGraph::size() const {
	return edgeList.size();
}

unsigned ListGraph::numEdges() const {
	return num_edges;
}
