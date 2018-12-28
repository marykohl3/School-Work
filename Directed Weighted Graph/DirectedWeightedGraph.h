/*
 * Mary Kohl 
 * DirectedWeightedGraph.h
 * 11/27/2018
 *
 */

#ifndef DIRECTEDWEIGHTEDGRAPH_H
#define DIRECTEDWEIGHTEDGRAPH_H

#include <iostream>
using namespace std;

#include <queue>
#include "VertexType.h"

class DirectedWeightedGraph{

   public:
	//Constructors
        DirectedWeightedGraph();
        DirectedWeightedGraph(int max);

	//Destructor
        ~DirectedWeightedGraph();

        bool IsEmpty() const;
        bool IsFull() const;

	//Add a vertex
	void AddVertex(VertexType v1);

	//Delete a vertex
	void DeleteVertex(VertexType v1);

	//Add an edge with weight
	void AddEdge(VertexType v1, VertexType v2, int w);

	//Find whether there is a vertex v
	bool VertexExists(VertexType v);	

	void printNumVertices();

	//Find the weight of an edge connecting v1 and v2
	int GetWeight(VertexType v1, VertexType v2);
  
       //Delete an edge from v1 to v2 with weight w
       void DeleteEdge(VertexType v1, VertexType v2);	
   
       //Find whether there is an edge from v1 to v2
       bool EdgeExists(VertexType v1, VertexType v2);
   	
       //BreadthFirstSearch Traversal
       void BreadthFirstSearch(VertexType v1);
   
       //Marks a vertex
   	void MarkVertex(VertexType &v, MARK m);//mark whether the vertex has been visited or queued

	//gets neighbors and adds them to queue
        void GetNeighbors(VertexType v, queue<VertexType> &nq);
   
   private:

        int numVertices;
        int maxVertices;
        
        VertexType * vertices; //save all the vertices

        int edges[25][25];   //values from the book
	
	// Find the index of the vertex in the graph
        int IndexIs(VertexType v1); 

};

#endif

