//TestDijkstra.cpp
//14/03/2022

#include<iostream>
#include<vector>
#include<list>
#include<map>

using namespace std;

const int INF = 999999;

// Overload operator << 
// Description: To print list<char> variables
ostream &operator<<(ostream &output, list<char> L)
{
   list<char>::iterator i;
   for(i=L.begin(); i != L.end(); ++i)
     output << *i << " ";
   return output;
}

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
//         Graph(numVertices): Constructor with number of vertices initialization.
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
		Graph(int numVertices);
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

// Default constructor of Graph Class:
// Description: Create an empty graph
Graph::Graph()
{
    numV = 0;
    numE = 0;
    adjList.clear();
}

// Constructor of Graph Class:
// Description: Initialize number of nodes. Create adjacency list with all nodes and empty edge list
Graph::Graph(int numVertices)
{
    numV = numVertices;
    numE = 0;
    nodeNames.resize(numV);
	char index;
	
    for (int x=0; x < numV; ++x){
		if (x<26)
            index = static_cast<char>('A' + x);
        else
            index = static_cast<char>('a' + x-26);
        nodeNames[x] = index;
        nodeNumbers[index] = x;
    }
	
	// Create adjacency list with all nodes and empty edge list
    adjList.clear();
    for(int i=0; i < numV; ++i){
        Node newNode;
        newNode.number = i;
        newNode.weight = 0;
        newNode.edges.clear();
        adjList.push_back(newNode);
    }
}

// Definition of method show()
// Description: Print the Graph
void Graph::show()
{
  cout << "  ";
  for(list<Node>::iterator i=adjList.begin(); i != adjList.end(); ++i)
    cout << " " << nodeNames[(*i).number];
  cout << endl;
  for(list<Node>::iterator i=adjList.begin(); i != adjList.end(); ++i)
  {
    cout << " " << nodeNames[(*i).number];
    int shift=0;
    for(list<Node>::iterator j=(*i).edges.begin(); j != (*i).edges.end(); ++j)
    {
      int walk=(*j).number-shift;
      for(int k=0; k<walk; ++k)
      {
	cout << " -";
	shift++;
      }
      cout << " " << (*j).weight;
      shift++;
    }
    while (shift<numV)
    {
      cout << " -";
      shift++;
    }
    cout << endl;
  }
}

// Definition for get_note_value() method
// Description: Return node name linked to node number x
char Graph::get_node_value(int x)
{
  return nodeNames[x];
}

// Definition for set_node_value() method
// Description: Change node name (from 'x' to 'name')
void Graph::set_node_value(char x, char name)
{
  int posX = nodeNumbers[x];	// Get the number of node 'x'
  nodeNames[posX] = name;	// Link node number to 'name'
  nodeNumbers[name]=posX;	// Link 'name' to node number
}

// Definition for get_edge_value() method
// Description: Return edge weight between 'x' and 'y'.Return INF if edge doesn't exist
int Graph::get_edge_value(char x, char y)
{
  for(list<Node>::iterator i=adjList.begin(); i != adjList.end(); ++i)
  {
    if ((*i).number==nodeNumbers[x])
      for(list<Node>::iterator j=(*i).edges.begin(); j != (*i).edges.end(); ++j)
      {
	 if ((*j).number==nodeNumbers[y])
	   return (*j).weight; 
      }
  }
  return INF;
}

// Definition for set_edge_value() method
// Description: Set edge weight between 'x' and 'y'
void Graph::set_edge_value(char x, char y, int value)
{
  bool found;
  // Set edge weight to value. Add 'y' in the list of 'x' neighbors (if doesn't exist)
  for(list<Node>::iterator i=adjList.begin(); i != adjList.end(); ++i)
  {
    if ((*i).number==nodeNumbers[x])
    {
      found = false;
      for(list<Node>::iterator j=(*i).edges.begin(); j != (*i).edges.end(); ++j)
      {
	 if ((*j).number==nodeNumbers[y])
	 {  
	   (*j).weight=value;
	   found = true;
	 }
      }
      if (!found)
      {
	Node newNodeY;
	newNodeY.number = nodeNumbers[y];
	newNodeY.weight = value;
	newNodeY.edges.clear();
	(*i).edges.push_back(newNodeY);
      }
    }
  }
  
  // Set edge weight to value. Add 'x' in the list of 'y' neighbors (if doesn't exist)
  for(list<Node>::iterator i=adjList.begin(); i != adjList.end(); ++i)
  {
    if ((*i).number==nodeNumbers[y])
    {
      found = false;
      for(list<Node>::iterator j=(*i).edges.begin(); j != (*i).edges.end(); ++j)
      {
	 if ((*j).number==nodeNumbers[x])
	 {  
	   (*j).weight=value;
	   found = true;
	 }
      }
      if (!found)
      {
	Node newNodeX;
	newNodeX.number = nodeNumbers[x];
	newNodeX.weight = value;
	newNodeX.edges.clear();
	(*i).edges.push_back(newNodeX);
	++numE;
      }
    }
  }
}

// Definition for adjacent() method
// Description: Return true if 'x' and 'y' are neighbors and false otherwise
bool Graph::adjacent(char x, char y)
{
  for(list<Node>::iterator i=adjList.begin(); i != adjList.end(); ++i)
  {
    if ((*i).number==nodeNumbers[x])
    {
      for(list<Node>::iterator j=(*i).edges.begin(); j != (*i).edges.end(); ++j)
      {
	if ((*j).number==nodeNumbers[y])
	{  
	  return true;
	}
      }
    }
  }
  return false;
}

// Definition for neighbors() method
// Description: Return a list<char> containing the list of neighbors of 'x'
list<char> Graph::neighbors(char x)
{
  list<char> adjNodes;
  for(list<Node>::iterator i=adjList.begin(); i != adjList.end(); ++i)
  {
    if ((*i).number==nodeNumbers[x])
    {
      for(list<Node>::iterator j=(*i).edges.begin(); j != (*i).edges.end(); ++j)
      {
	adjNodes.push_back(nodeNames[(*j).number]);
      }
    }
  }
  return adjNodes;
}
   
// Definition for V() method
// Description: Return the number of nodes in the Graph
int Graph::V()
{
  return numV;
}

// Definition for E() method
// Description: Return the number of edges in the Graph
int Graph::E()
{
  return numE;
}

// Definition for vertices() method
// Description: Return a list<char> containing all nodes in the Graph
list<char> Graph::vertices()
{
  list<char> nodes;
  for(list<Node>::iterator i=adjList.begin(); i != adjList.end(); ++i)
  {
    nodes.push_back(nodeNames[(*i).number]);
  }
  return nodes;
}

int main(){
    
	Graph g(5);
	g.show();
 
    return 0;  
}

