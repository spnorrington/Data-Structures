// Purpose: Implementation of an Adjacency Matrix Graph


#pragma once

#include <vector>
#include "graph.hpp"

template <class N>
class AdjMatrixGraph : public Graph<N> 
{
private:
	const static int MaxSize = 100;
	std::vector<N> nodeVector;
	std::byte adjMatrix[maxSize][maxSize];
	unsigned int numNodes = 0;

public:
	// Default constructor
	AdjMatrixGraph() : Graph<N>() { };


	// Copy Constructor
	AdjMatrixGraph(const AdjMatrixGraph& other) : Graph<N>() 
	{
		numNodes = other.numNodes;
		nodeVector = other.nodeVector;

		//Copies the adjacency matrix from the source object
		for (int i = 0; i < numNodes; i++)
		{
			for (int j = 0; j < numNodes; j++)
			{
				adjMatrix[i][j] = other.adjMatrix[i][j];
			}
		}
	}
	// overloaded assignment operator
	AdjMatrixGraph& operator= (const AdjMatrixGraph& source) 
	{
		if (this != &source) 
		{
			numNodes = source.numNodes;
			nodeVector = source.nodeVector;

			//Copies the adjacency matrix from the source object
			for (int i = 0; i < numNodes; ++i) 
			{
				for (int j = 0; j < numNodes; ++j) 
				{
					adjMatrix[i][j] = source.adjMatrix[i][j];
				}
			}
		}
		return *this;
	}


	// Constructor that Adds nodes/edges
	AdjMatrixGraph(std::vector<N> newNodes, std::vector<pair<N, N>> newEdges) :
		Graph<N>(newNodes, newEdges) 
	{
		numNodes = newNodes.size();

		//Initialize the adjacency matrix with 0
		for (int i = 0; i < numNodes; ++i) 
		{
			for (int j = 0; j < numNodes; ++j) 
			{
				adjMatrix[i][j] = 0;
			}
		}

		// Update the adjacency matrix with the new edges
		for (const auto& edge : newEdges) 
		{
			int indexX = findNodeIndex(edge.first);
			int indexY = findNodeIndex(edge.second);
			if (indexX != -1 && indexY != -1) 
			{
				// Set the adjacency matrix entries to 1 for edges
				adjMatrix[indexX][indexY] = 1;
				adjMatrix[indexY][indexX] = 1;
			}
		}

	}

	// Destructor to Clean up
	~AdjMatrixGraph() { }
	virtual bool adjacent(N x, N y) 
	{
		int indexX = findNodeIndex(x);
		int indexY = findNodeIndex(y);
		if (indexX != -1 && indexY != -1) 
		{
			return adjMatrix[indexX][indexY] == 1;
		}
		return false;
	}

	// Get list of neighbors for a node
	virtual std::vector<N> neighbors(N x) 
	{
		int indexX = findNodeIndex(x);
		std::vector<N> neighborNodes;
		if (indexX != -1) {
			for (int i = 0; i < numNodes; ++i)
			{
				if (adjMatrix[indexX][i] == 1) 
				{
					// Add neighboring nodes to the list
					neighborNodes.push_back(nodeVector[i]);
				}
			}
		}
		return neighborNodes;
	}

	// Add a node to the graph
	virtual void addNode(N node) 
	{
		if (numNodes < MaxSize) 
		{
			nodeVector.push_back(node);
			numNodes++;
		}
	}

	// add an edge between two nodes to the graph 
	virtual void addEdge(N x, N y) 
	{
		int indexX = findNodeIndex(x);
		int indexY = findNodeIndex(y);
		if (indexX != -1 && indexY != -1) 
		{
			// Set the adjacency matrix entries to 1 for edges
			adjMatrix[indexX][indexY] = 1;
			adjMatrix[indexY][indexX] = 1;
		}
	}
	virtual void deleteEdge(N x, N y) 
	{
		int indexX = findNodeIndex(x);
		int indexY = findNodeIndex(y);
		if (indexX != -1 && indexY != -1) 
		{
			// set matrix entries to 0 for deleted edges
			adjMatrix[indexX][indexY] = 0;
			adjMatrix[indexY][indexX] = 0;
		}
	}
};
