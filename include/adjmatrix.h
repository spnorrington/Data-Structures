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


	// Get the vertex map from the Graph we're copying
	AdjMatrixGraph(const AdjMatrixGraph& other) : Graph<N>() 
	{
		numNodes = other.numNodes;
		nodeVector = other.nodeVector;
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


	// Add the nodes in the list to graph
	AdjMatrixGraph(std::vector<N> newNodes, std::vector<pair<N, N>> newEdges) :
		Graph<N>(newNodes, newEdges) 
	{
		numNodes = newNodes.size();
		for (int i = 0; i < numNodes; ++i) 
		{
			for (int j = 0; j < numNodes; ++j) 
			{
				adjMatrix[i][j] = 0;
			}
		}
		for (const auto& edge : newEdges) 
		{
			int indexX = findNodeIndex(edge.first);
			int indexY = findNodeIndex(edge.second);
			if (indexX != -1 && indexY != -1) 
			{
				adjMatrix[indexX][indexY] = 1;
				adjMatrix[indexY][indexX] = 1;
			}
		}

	}

	// Clean up behind ourselves
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


	virtual std::vector<N> neighbors(N x) 
	{
		int indexX = findNodeIndex(x);
		std::vector<N> neighborNodes;
		if (indexX != -1) {
			for (int i = 0; i < numNodes; ++i)
			{
				if (adjMatrix[indexX][i] == 1) 
				{
					neighborNodes.push_back(nodeVector[i]);
				}
			}
		}
		return neighborNodes;
	}
	virtual void addNode(N node) 
	{
		if (numNodes < MaxSize) 
		{
			nodeVector.push_back(node);
			numNodes++;
		}
	}
	virtual void addEdge(N x, N y) 
	{
		int indexX = findNodeIndex(x);
		int indexY = findNodeIndex(y);
		if (indexX != -1 && indexY != -1) 
		{
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
			adjMatrix[indexX][indexY] = 0;
			adjMatrix[indexY][indexX] = 0;
		}
	}
};
