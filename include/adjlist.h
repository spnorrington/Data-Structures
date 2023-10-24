// Purpose: This is an adjacency list graph implementation that inherits from the graph.hpp file
//
// Note: Adjacency lists work better with small or sparse graphs 

#pragma once
#include <vector>
#include <list>
#include "graph.hpp"

template <class N> // template type parameter with N indicating the                   different data types can be worked with for nodes

class AdjListGraph : public Graph<N> 

	// edges uses std::list to represent the edges of the graph. It will store pairs of integers representing edge connections
{            
private:
	using Edges = std::list<std::pair<int, int>>; 
	std::vector<N> nodeVector;
	std::vector<Edges> edgesVector;
public:
	// Default constructor, creates empty graph
	AdjListGraph() : Graph<N>() { };


	// Copy Constructor | Get the vertex map from the Graph we're copying
	AdjListGraph(const AdjListGraph& other) : Graph<N>(other.nodeVector, other.edgesVector) 
	{
		nodeVector = other.nodeVector;  // Copy nodeVector
		edgesVector = other.edgesVector;  // Copy edgesVector
	}

	// Overloaded assignment operator
	AdjListGraph& operator= (const AdjListGraph& source) 
	{
		if (this != &source) 
		{
			// Copy the contents of source into this graph
			nodeVector = source.nodeVector;
			edgesVector = source.edgesVector;
		}
		return *this;
	}

	// Add the nodes in the list to graph
	AdjListGraph(std::vector<N> newNodes, std::vector<pair<N, N>> newEdges) :
		Graph<N>(newNodes, newEdges) { }
	// Clean up behind ourselves
	~AdjListGraph() { }
	virtual bool adjacent(N x, N y) {  }
	virtual std::vector<N> neighbors(N x) {  }
	virtual void addNode(N node) { }
	virtual void addEdge(N x, N y) { }
	virtual void deleteEdge(N x, N y) { }
};
