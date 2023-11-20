
// -------Instructions --------
// The purpose of this program is to build a social graph for a group of 20 people including both you and Kevin Bacon.
//  
// Required functions: 
// given a reference to that social graph, tells you whether or not you are connected to Kevin Bacon. 
// Function returns true if you are, and uses a reference parameter to return a list that shows the path between you and kevin Bacon if it exists or an empty list if it doesn't.
// ------------------------------

// Traversal Graph: application of depth-first search
// Use stack to keep track of unvisited nodes


#include "adjlist.h"
#include <vector>
#include <stack>
#include <string>


struct PathNode 
{
	std::string node;
	PathNode* parent; // Points to the previous node in the path
};

// Function to perform depth-first search and find a path to Kevin Bacon
bool findPathToKevinBacon(const AdjListGraph<std::string>& socialGraph, const std::string& startNode, std::vector<std::string>& path)
{
	// Create a stack to keep track of nodes to visit
	std::stack<std::string> nodeStack;

	// Initialize the path with a nullptr parent for the starting node
	PathNode* startPathNode = new PathNode{ startNode, nullptr };

	// Push the start node's path onto the stack
	nodeStack.push(startPathNode);

	// Start the loop to process nodes in a depth-first manner
	while (!nodeStack.empty())
	{
		PathNode* currentPathNode = nodeStack.top();
		nodeStack.pop();

		std::string currentNode = currentPathNode->node;

		if (currentNode == "Kevin Bacon") 
		{
			// Path found, reconstruct it from PathNode objects
			while (currentPathNode != nullptr) 
			{
				path.insert(path.begin(), currentPathNode->node);
				currentPathNode = currentPathNode->parent;
			}
			return true; // Path to Kevin Bacon exists
		}

		for (const std::string& neighbor : socialGraph.neighbors(currentNode))
		{
			// Create a new PathNode with the neighbor as the current node and the currentPathNode as its parent
			PathNode* neighborPathNode = new PathNode
			{ neighbor, currentPathNode };
			nodeStack.push(neighborPathNode);
		}
	}

	// No path to Kevin Bacon found
	return false;
}

int main()
{
	// add social graph and add people and connections to it.

	std::vector<std::string> pathToKevinBacon;
	if (findPathToKevinBacon(socialGraph, "Sophia", pathToKevinBacon)) 
	{
		// add code to print the path to Kevin Bacon
	}
	else 
	{
		//  not connected to Kevin Bacon.
	}

	return 0;
}
