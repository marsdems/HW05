/**********************************************************
* Mike Marsden
* HW05 - Traveling Salesperson Problem 
* ListGraph.cpp
**********************************************************/
#include "ListGraph.h"

//Constructor
ListGraph::ListGraph(int numNodes) {
	num_edges = 0;
	edgeList = std::vector<EList>();
	edgeList.resize(numNodes);
}

//Destructor
ListGraph::~ListGraph() { }

void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight)
{
	// Referenced Brandon Sonodabe's method to get the proper 
	// format of the push_back lines. 
	edgeList[u].push_back(std::make_pair(v, weight));
	edgeList[v].push_back(std::make_pair(u, weight));
	num_edges++;
}

EdgeWeight ListGraph::weight(NodeID u, NodeID v) const {
	//Referenced from class lecture notes
	EList::const_iterator it;
	for (it = edgeList[u].begin(); it != edgeList[u].end(); it++) {
		NWPair edge = *it;
		if (edge.first == v) {
			return edge.second;
		}
	}
	return 0.0;
}

std::list<NWPair> ListGraph::getAdj(NodeID u) const {
	return edgeList.at(u);
}

unsigned ListGraph::degree(NodeID u) const {
	unsigned degree;
	// To ensure that u is within EdgeList
	if (u < edgeList.size()) {
		degree = edgeList.at(u).size();
	}
	return degree;
}

unsigned ListGraph::size() const {
	return edgeList.size();
}

unsigned ListGraph::numEdges() const {
	return num_edges;
}
