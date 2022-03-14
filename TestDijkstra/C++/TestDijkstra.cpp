//TestDijkstra.cpp
//14/03/2022

#include<iostream>
#include<vector>
#include<list>
#include<map>

using namespace std;

// Node definition:
//    Description: Node structure to store information about nodes/edges.
//       number: Number of the node.
//       weight: Edge weigth of the node.
//       edges: List of neighbors nodes with number, weight and edges caracteristics.
typedef struct structNode Node;
struct structNode{
    int number;
	int weight;
	list<Node> edges;
};

// Class Graph declaration:
//     Description: Class that´s represent a graph
//     Methods:
//         Graph(): Default constructor.
//         Graph(numVertices, initialValue): Constructor with number of vertices and value initialization.
//  	   V(): Returns the number of vertices in the graph.
//         E(): Returns the number of edges in the graph.
//         adjacent(x, y): Tests whether there is an edge from node x to node y.
//         neighbors(x): Lists all nodes y such that there is an edge from x to y.
//         get_node_value(x): Returns the value associated with the node x.
//         set_node_value(x, name): Sets the value associated with the node x to a.
//         get_edge_value(x, y): Returns the value associated to the edge (x,y).
//         set_edge_value (x, y, value): Sets the value associated to the edge (x,y) to value.
//         vertices(): Lists all vertices.
//         show(): Print graph. 
class Graph{
	public:
	    Graph();
		Graph(int numVertices, int initialValue);
	    int V();
		int E();
		bool adjacent (char x, char y);
		list<char> neighbors(char x);
        char get_node_value(int x);
        void set_node_value(char x, char name);
        int get_edge_value(char x, char y);
        void set_edge_value(char x, char y, int value);
        list<char> vertices();
        void show();
		
	private:
	    int numV;			        // Number of nodes of the Graph
        int numE;			        // Number of edges of the Graph
        vector<char> nodeNames;	    // Map node numbers into node names
        map<char, int> nodeNumbers;	// Map node names into node numbers
        list<Node> adjList;		    // Adjacency list representing the Graph
};


int main(){
    
	Node testNodeDefinition;
 
    return 0;  
}

