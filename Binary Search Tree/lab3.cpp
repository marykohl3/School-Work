/*
 * Mary Kohl 
 * Lab 3: Binary Search Tree
 * Extend a Binary Search Tree ADT
 *
 */

#include "ItemType.h"
#include "TreeType.h"

int main(){

    TreeType firstTree;

    ItemType x;
    x.Initialize('M');
    firstTree.InsertItem(x);
    if (firstTree.IsEmpty() == false)
       cout<<"the first item is inserted"<<endl;

    cout<<"After inserting the first item "<<x<<" into the tree"<<endl;
    firstTree.Print();
    
    x.Initialize('J');
    firstTree.InsertItem(x);
    x.Initialize('H');
    firstTree.InsertItem(x);
    x.Initialize('D');
    firstTree.InsertItem(x);
    x.Initialize('B');
    firstTree.InsertItem(x);
    x.Initialize('F');
    firstTree.InsertItem(x);
    x.Initialize('A');
    firstTree.InsertItem(x);
    x.Initialize('C');
    firstTree.InsertItem(x);
    x.Initialize('E');
    firstTree.InsertItem(x);
    x.Initialize('G');
    firstTree.InsertItem(x);

    cout<<"After inserting nine items into the tree"<<endl;
    firstTree.Print();
    firstTree.prettyTree(firstTree);

    int count = firstTree.GetLength();
    cout<<"The tree has "<<count<<"  elements"<<endl;

    //LeafCount
    int leaves;
    leaves = firstTree.LeafCount();
    cout<<"firstTree has "<<leaves<<" leaves"<<endl;

    //Ancestors
    ItemType E;
    E.Initialize('E');
    cout<<"Ancestors of E:"<<endl;
    firstTree.Ancestors(E);
    cout<<endl;

    //Delete
    ItemType D;
    D.Initialize ('D');
    firstTree.DeleteItem(D);
    cout<<"Delete 'D':"<<endl;
    firstTree.Print();
    firstTree.prettyTree(firstTree);
    
    //Swap
    cout<<"Print firstTree:"<<endl;
    firstTree.Print();
    cout<<"Swapped: "<<endl;
    firstTree.Swap(firstTree);
    firstTree.Print();
    cout<<"End swap"<<endl;

    return 0;
}

