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
	AdjListGraph& operator=(const AdjListGraph& source) 
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

	~AdjListGraph() { }

	virtual bool adjacent(N x, N y) 
	{
		//Adjacency Check
		return false;
	}

	virtual std::vector<N> neighbors(N x) 
	{
		//Neighbor retrieval
		std::vector<N> neighbors;
		return neighbors;
	}
	virtual void addNode(N node) 
	{
		nodeVector.push_back(node); // Add the new node to the nodeVector
		edgesVector.push_back(Edges()); // Create an empty list of edges for the new node
	}

	virtual void addEdge(N x, N y) //** Outside resource used for this function, see below
	{
		if (std::find(nodeVector.begin(), nodeVector.end(), x) != nodeVector.end() &&
			std::find(nodeVector.begin(), nodeVector.end(), y) != nodeVector.end()) 
		{
			edgesVector[std::distance(nodeVector.begin(), std::find(nodeVector.begin(), nodeVector.end(), x))].push_back(std::make_pair(x, y));
			edgesVector[std::distance(nodeVector.begin(), std::find(nodeVector.begin(), nodeVector.end(), y))].push_back(std::make_pair(y, x));
		}
	}
	virtual void deleteEdge(N x, N y) //** Outside resource used for this function, see below
	{
		if (std::find(nodeVector.begin(), nodeVector.end(), x) != nodeVector.end() &&
			std::find(nodeVector.begin(), nodeVector.end(), y) != nodeVector.end()) 
		{
			edgesVector[std::distance(nodeVector.begin(), std::find(nodeVector.begin(), nodeVector.end(), x))].remove(std::make_pair(x, y));
			edgesVector[std::distance(nodeVector.begin(), std::find(nodeVector.begin(), nodeVector.end(), y))].remove(std::make_pair(y, x));
		}
	}
};




// Sources //

// https://stackoverflow.com/questions/65959282/working-of-findvector-begin-vector-end-ai-vector-end
// https://www.geeksforgeeks.org/vectorbegin-vectorend-c-stl/