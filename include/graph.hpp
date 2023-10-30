// The purpose of this code is to design an abstract base class for a graph
// An adjacency list graph class will inherit from this base class


// Any class that inherits from this Graph class can be used as reference to this class

#pragma once

#include <vector>
#include <list>



template <class N>
class Graph 
{
public:
	// Default constructor, create empty
	Graph() {};
	Graph(std::vector<N> nodes, std::vector<std::pair<N, N>> edges) {};
	virtual ~Graph() {};

	virtual bool adjacent(N x, N y) = 0;
	virtual std::vector<N> neighbors(N x) = 0;
	virtual void addNode(N x) = 0;
	virtual void addEdge(N x, N y) = 0;
	virtual void deleteEdge(N x, N y) = 0;
};
