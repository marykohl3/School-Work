/*
 * Mary Kohl 
 * lab4.cpp
 * 11/27/2018
 * Directed Weighted Graph
 */

#include <iostream>
#include "DirectedWeightedGraph.h"
#include <queue>

using namespace std;

int main()
{
    DirectedWeightedGraph graph;
    
    VertexType v1;
    v1.item.Initialize('A');
    v1.mark = DEFAULT;
    graph.AddVertex(v1);
    
    VertexType v2;
    v2.item.Initialize('B');
    v2.mark = DEFAULT;
    graph.AddVertex(v2);
    
    VertexType v3;
    v3.item.Initialize('C');
    v3.mark = DEFAULT;
    graph.AddVertex(v3);
    
    VertexType v4;
    v4.item.Initialize('D');
    v4.mark = DEFAULT;
    graph.AddVertex(v4);
    
    VertexType v5;
    v5.item.Initialize('E');
    v5.mark = DEFAULT;
    graph.AddVertex(v5);
    
    VertexType v6;
    v6.item.Initialize('F');
    v6.mark = DEFAULT;
    graph.AddVertex(v6);
    
    VertexType v7;
    v7.item.Initialize('G');
    v7.mark = DEFAULT;
    graph.AddVertex(v7);


    cout<<"Number of Vertices: "; //should be 7
    graph.printNumVertices();
    cout<<endl;

    //Values from book and city distance
    graph.AddEdge(v1, v1, 0);
    graph.AddEdge(v1, v2, 600);
    graph.AddEdge(v2, v1, 600);
    graph.AddEdge(v4, v2, 800);
    graph.AddEdge(v1, v3, 1300);
    graph.AddEdge(v2, v4, 1400);
    graph.AddEdge(v3, v5, 1500);
    graph.AddEdge(v3, v6, 2080);
    graph.AddEdge(v3, v7, 2200);
    graph.AddEdge(v5, v3, 1500);
    graph.AddEdge(v5, v4, 160); 

    //IsEmpty and IsFull 
    cout<<"graph IsEmpty() "<<graph.IsEmpty()<<endl; //should be 0
    cout<<"graph IsFull() "<<graph.IsFull()<<endl; //should be 0 unless 10 items are initalized

    //BreadthFristTraversal
    cout<<"BreadthFirstTraversal: v5"<<endl;
    graph.BreadthFirstSearch(v5);
    cout<<endl;

    //Delete v5
    cout<<"DeleteVertex(v5)";
    graph.DeleteVertex(v5);

    //Number of Vertices should be 6
    cout<<"Number of Vertices: ";
    graph.printNumVertices();
    cout<<endl;

    //VertexExists
    if (!(graph.VertexExists(v5)))
	    cout<<"Vertex v5 DNE"<<endl;

    //EdgeExists will output 1
    cout<<"EdgeExists v4 -> v2 "<<graph.EdgeExists(v4, v2)<<endl;

    //GetWeight v5, v3
    cout<<"GetWeight v5 -> v3 "<<graph.GetWeight(v5, v3)<<endl;


    cout<<"BreadthFirstTraversal: v3"<<endl;
    graph.BreadthFirstSearch(v3);
    cout<<endl;
    
    cout<<"BreadthFirstTraversal: v6"<<endl;
    graph.BreadthFirstSearch(v6);
    cout<<endl;

    //run Deconstructor
    graph.~DirectedWeightedGraph(); 

    return 0;
}

