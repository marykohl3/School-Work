/***********************************************
 * File : TreeType.h
 * Date : 10/10/08
 * Description : Header file of Class TreeType 
 *               A binary search tree
 **********************************************/
#ifndef TREETYPE_H
#define TREETYPE_H

#include <iostream>
#include <fstream>
using namespace std;

#include <queue>

#include "ItemType.h"


class TreeNode{

public:
   ItemType info;
   TreeNode * left;
   TreeNode * right;   
}; 

enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};

class TreeType
{
public:
   TreeType();
   ~TreeType();
 
   TreeType(const TreeType & originalTree); //copy constructor
   void operator=(const TreeType & originalTree);

   void MakeEmpty();

   bool IsEmpty() const;
   bool IsFull() const;

   int GetLength() const;  //how many nodes in the tree

   

   void RetrieveItem( ItemType & item, bool & found) const;
   void InsertItem ( ItemType  item);
   void DeleteItem ( ItemType  item);

   void ResetTree(OrderType order);
   void GetNextItem(ItemType & item, OrderType order, bool & finished);

   void Print(ofstream & output) const;
   void Print() const;

   int LeafCount() const;
   int LeafCount(TreeNode *root) const;
   void Ancestors(TreeNode *root, ItemType item);
   void Ancestors(ItemType item);
   void Swap(TreeType &newTree);
   void SwapTree(TreeNode *&copy, const TreeNode* originalTree);
   void prettyTree(TreeType &newTree);	
   void treePrintPretty(TreeNode* p, int indent);

private:

   TreeNode * root;

   queue<ItemType> * preQue;
   queue<ItemType> * inQue;
   queue<ItemType> * postQue;

   void Destroy(TreeNode *& tree);
   void CopyTree(TreeNode *& copy, const TreeNode * originalTree);

   int Count(TreeNode * tree) const;
   void Retrieve(TreeNode * tree, ItemType & item, bool &found) const;
   void Insert(TreeNode *& tree, ItemType item);
  
   void Delete(TreeNode *& tree, ItemType item);
   void DeleteNode(TreeNode *& tree);
   void GetPredecessor (TreeNode * tree, ItemType & item);
   void GetSuccessor (TreeNode *tree, ItemType &item);
   void PrintTree(TreeNode * tree, ostream& output) const;


   void PreOrder(TreeNode* tree, queue<ItemType> *& preQue);
   void InOrder (TreeNode* tree, queue<ItemType> *& inQue);
   void PostOrder(TreeNode* tree, queue<ItemType> *& postQue);

   

};

#endif
