/*
 * Mary Kohl 
 * DirectecWeightedGraph.cpp
 * 11/27/18
 *
 */

#include "DirectedWeightedGraph.h"
#include <queue>
#include<iostream>

DirectedWeightedGraph::DirectedWeightedGraph() {
	numVertices = 0;
	maxVertices = 10;
	vertices = new VertexType[maxVertices]; 

}

DirectedWeightedGraph::DirectedWeightedGraph(int max) {
	numVertices = 0;
	maxVertices = max;

	vertices = new VertexType[maxVertices]; 

}

DirectedWeightedGraph::~DirectedWeightedGraph() {}

//Tests whether the set is empty
//post: function value = (set is full)
bool DirectedWeightedGraph::IsEmpty() const {
	return(numVertices == 0);
}

//Tests whether the set is full
//post: function value = (set is full)
bool DirectedWeightedGraph::IsFull() const {
	return(numVertices == maxVertices);
}

//Adds a vertex to the graph
//pre: graph is not full
//post: vertex is in graph
void DirectedWeightedGraph::AddVertex(VertexType v1) {
	vertices[numVertices] = v1;
	numVertices++;
}//End AddVertex

//Deletes a vertex to the graph
//post: vertex is no longer in graph
void DirectedWeightedGraph::DeleteVertex(VertexType v1) {
	int index = IndexIs(v1);

	vertices[index] = vertices[numVertices-1];

	for(int i = 0; i < numVertices; i++) {
		edges[index][i] = 0;
		edges[i][index] = 0;

	}

	for(int i = 0; i < numVertices; i++) {
		if(edges[numVertices-1][i] > 0)
			edges[index][i] = edges[numVertices-1][i];
		else if(edges[i][numVertices-1] > 0)
			edges[i][index] = edges[i][numVertices-1];
	}

	for(int i = 0; i < numVertices; i++) {
		edges[numVertices-1][i] = 0;
       		edges[i][numVertices-1] = 0;
	}
	
	numVertices--;

}//End Delete Vertex

//Returns the index of graph
int DirectedWeightedGraph::IndexIs (VertexType v1) {
	int index;
    	
	for (index = 0; index < maxVertices; index++) {
        	if(v1.item.ComparedTo(vertices[index].item) == EQUAL)
            		return (index);
    	}

    	index = -1;
    
	return (index);

}//end IndexIs

//Adds Edge to a graph
//pre: vertices are already initalized
//post: edge is added to graph
void DirectedWeightedGraph::AddEdge(VertexType v1, VertexType v2, int w) {
	int row; 
	int column; 

	row = IndexIs(v1);
	column = IndexIs(v2);
}//end AddEdge

//checks to see if an edge exists
//post: returns true or false
bool DirectedWeightedGraph::EdgeExists(VertexType v1, VertexType v2) {
         int row;
         int column;
         bool exists = true;

         row = IndexIs(v1);
         column = IndexIs(v2);

         if(edges[row][column] <= -1)
                 exists = false;
         return(exists);
}//End EdgeExists


//Gets the weight of vertices
//pre: Edge exists
//post: weight is returned
int DirectedWeightedGraph::GetWeight(VertexType v1, VertexType v2) {
	int row;
	int column;

	row = IndexIs(v1);
	column = IndexIs(v2);

	if(EdgeExists(v1, v2)) {
			int weight; 
			weight = edges[row][column];
			return (weight);
	}//end if

	else {
		cout<<"Edge does not exist"<<endl;
		return (0);
	}//end else

}//end GetWeight

//Checks to see if VertexExists
bool DirectedWeightedGraph::VertexExists(VertexType v1) {
	int check = IndexIs(v1);
    	bool exists = false;

    	if (v1.item.ComparedTo(vertices[check].item) == EQUAL) {
        
		exists = true;
    	}

    	return (exists);

}//End VertexExists

//deleted edge
//pre: edge exists
//post: edge is deleted
void DirectedWeightedGraph::DeleteEdge(VertexType v1, VertexType v2) {
	int row;
        int column;
	
        row = IndexIs(v1);
        column = IndexIs(v2);

	if(EdgeExists(v1,v2)) 
		edges[row][column] = 0;
	else
		cout<<"Edge DNE"<<endl;

}//End DeleteEdge

//prints the number of vertices
void DirectedWeightedGraph::printNumVertices() {
        cout<<numVertices;
}//End printNumVertices

//Marks vertex
void DirectedWeightedGraph::MarkVertex(VertexType& v, MARK m) {
    int x = IndexIs(v);
    vertices[x].mark = m;
}

//Gets Neighbors and marks neighbors in the queue as QUEUED
void DirectedWeightedGraph::GetNeighbors(VertexType v, queue<VertexType> &nq) {
    int x = IndexIs(v);

    for(int i = 0; i < numVertices; i++) {
        if(edges[x][i] != 0 && vertices[i].mark != QUEUED && vertices[i].mark != VISITED) {
            nq.push(vertices[i]);
	    MarkVertex(vertices[i], QUEUED);
	}//end if
    }//ends for
}//End GetNeighbors

//BreadthFirstSearch Function
// traverses a graph using queue, returns in layered order
void DirectedWeightedGraph::BreadthFirstSearch(VertexType v) {
	
	for (int i = 0; i < numVertices; i++) {
		MarkVertex(vertices[i], DEFAULT);
	}
	
	queue<VertexType> neighbors;
	neighbors.push(v);
	MarkVertex(v, QUEUED);

	while (!neighbors.empty()) {
		neighbors.front().printValue();
		GetNeighbors(neighbors.front(), neighbors);
		MarkVertex(neighbors.front(), VISITED);
		neighbors.pop(); //check to see if the last value prints
	}//end while

}//End BreadthFirstSearch
