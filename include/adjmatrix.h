// Purpose: Implementation of an Adjacency Matrix Graph


#pragma once

template <class N>
class AdjMatrixGraph : public Graph<N> 
{
private:
	const static int MaxSize = 100;
	std::vector<N> nodeVector;
	std::byte adjMatrix[maxSize][maxSize];
	unsigned int numNodes = 0;
public:
	// Default constructor, create empty
	AdjMatrixGraph() : Graph<N>() { };
	// Get the vertex map from the Graph we're copying
	AdjMatrixGraph(const AdjMatrixGraph& other) : Graph<N>() { }
	// Don't forget to overload the assignment operator
	AdjMatrixGraph& operator= (const AdjMatrixGraph& source) {}
	// Add the nodes in the list to graph
	AdjMatrixGraph(std::vector<N> newNodes, std::vector<pair<N, N>> newEdges) :
		Graph<N>(newNodes, newEdges) { }
	// Clean up behind ourselves
	~AdjMatrixGraph() { }
	virtual bool adjacent(N x, N y) {  }
	virtual std::vector<N> neighbors(N x) {  }
	virtual void addNode(N node) { }
	virtual void addEdge(N x, N y) { }
	virtual void deleteEdge(N x, N y) { }
};
