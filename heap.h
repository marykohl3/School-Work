/*
 * Mary Kohl 
 * Lab2 - Heap
 * 26 March 2019
 *
 */

#include <iostream>
#include <assert.h>
using namespace std;

const int MAX_SIZE=100;

/* Note the type ItemType needs to implement comparison operators */
template <class ItemType>
class Heap{
public:
    Heap(){
	heapLength=0;
    }

    //Initialize the heap with the given data, and call build_heap to make it a heap
    Heap(ItemType initData[], int len);

    //return true if heap property is satisfied, false if violated
    bool IsHeap();

    /* precondition:
     *   1) heapLength>=i>1
     *   2) node i's left subtree and right subtree meet the heap property, 
     *   node i might violate heap property, 
     * postcondition: the subtree rooted at node i met heap property */
    void heapify(int i /*, int n*/);

    /* insert a new item into the heap. 
     * Precondition: length+1<MAX_SIZE; //We have room to grow 
	1. increment heap length by 1
	2. store new item at the end of the heap, say the location is j
	3. walk your way up from node j to root (going one level up to parent in each step,
		compare values stored at a node with its parent and swap
	  the items if necessary.
	  */
    void Insert(ItemType item);

    void Display();
     /*  modify item stored in position i to the newValue, and repair heap property.
      *   Precondition: heap property is statisfied, 
      *   	        1<=i<=length
      *   Postcondition: i-th element is modified, and heap property is satisfied 
      *   Note that you cannot just call build_heap, which is overkill, instead you 
      *   need to repair heap property as efficient as possible).
     When node i's value is changed to a smaller value, then heapify(i) can fix the whole heap.
     When node i's value is changed to a larger value, then the tree rooted at i is still a heap, 
       but the whole tree might not. THink about how to fix! 
      */
    void Modify(int i, ItemType newValue);
    
    //precondition: items are initalized
    //postconsition: items are swapped
    void swap(ItemType &x, ItemType &y);  

    // return the item stored in the root node of the heap
    ItemType GetRoot();
	

    // remove and return item stored in root from the heap
    ItemType RemoveRoot(){
	ItemType rootElement=data[heapLength - 1];
	
	// swap last with root
	int stored = rootElement; 
	swap(rootElement, data[0]); 
 
	// decrease length,
	heapLength--;

	// heapify
	heapify(0); 

	if(!IsHeap())
                cout<<"RemoveRoot() function failed, not a heap"<<endl;
	return GetRoot();
    }
private:
     //precondition: i is the numbering of node (starting from 1)
     //              i is not 1 (as root node has no parent)
     //postcondition: the numbering of node i's parent is returned
     int parent(int i);     //return i/2 (calculating i/2 using bitewise shift operators)

     //return the numbering of the left child of node i
     // if node i has no left child, return -1 (note use heapLength to see if there is one)
     int leftchild (int i); //return 2*i (calculated using bitwise shift operators)

     //return the numbering of the right child of node i
     // if node i has no right child, return -1 (note use heapLength to see if there is one)
     int rightchild (int i); // return 2*i+1 (left shift, bitwise OR)

    /* Precond: 
      the array has been filled with elements, but heap property is not satisfied
      Postcondition:  rearrange elements so that the whole heap statisfies heap property. 
      *This method should be called in the second constructor*/
    void build_heap(); 

     ItemType data[MAX_SIZE];  //You could store elements from index 1 (i.e., leave
     	//first slot of the array empty), this way, you can use abvoe parent(),leftchild(),
	//rightchild() function to return the location of the nodes
     int heapLength;   // the actual number of elements in the heap
};
 

//Initialize the heap with the given data, and call build_heap to make it a heapt
template <class ItemType>
Heap<ItemType>::Heap(ItemType initData[], int len)
{
   for (int i=0;i<len;i++)
	   data[i] = initData[i];

   heapLength=len;
   build_heap();

//   assert (IsHeap());
}

template<class ItemType>
int Heap<ItemType>::parent(int i){
	return ((i-1)/2);
}//end parent

template<class ItemType>
int Heap<ItemType>::leftchild(int i){
        return (2*i+1);
}//end leftchild

template<class ItemType>
int Heap<ItemType>::rightchild(int i){
        return (2*i+2);
}//end right child

//swaps two integers - self explanatory 
template<class ItemType>
void Heap<ItemType>::swap(ItemType &x, ItemType &y) {
	int temp = x; 
	x = y; 
	y = temp; 
}

//pre: node i's left and right subtree meet heap property
//post: fixes subtree rooted at node i so that the subtree is a heap
//@param i: node of subtree that needs to be fixed
//@param len; length that is being fixed
//I had to change the parameters since I was not sure how to do it without len 
template<class ItemType>
void Heap<ItemType>::heapify(int i /* , int len*/){
       	int largest = i; 
	int left = 2*i +1;
	int right = left + 1;

		if (left < heapLength && data[left] > data[largest]) 
			largest = left;
       		if (right < heapLength && data[right] > data[largest])
       			largest = right; 	
		if (largest != i) {
		 	swap(data[i], data[largest]); 
			heapify(largest); 
		}//end if 
}//end parent

//pre: array has been filled with elements
//post: builds array to meet heap property by rearranging the elements so taht the whole heap 
//satisfies heap properpty
template<class ItemType>
void Heap<ItemType>::build_heap(){

	//heapify first half of heap
	for(int i = ((heapLength/2) - 1); i >= 0; i--) 
		heapify(i);

	//heapify tree from bottom up
//	for(int i = (heapLength-1); i >= 0; i--) {
///		swap(data[0], data[i]); 
//		heapify(0);
//	}//end for
}//end build_heap

//pre: heap has been created
//post: returns true or false balue to test if it follows heap property
template<class ItemType>
bool Heap<ItemType>::IsHeap() {
 
	for (int i = 0; i < heapLength; i++) {
		if((leftchild(i) <= heapLength) && (data[i] < data[leftchild(i)]))
			return false; 
		if((rightchild(i) <= heapLength) && (data[i] < data[rightchild(i)]))
			return false; 
	}

	return true; 
}//end IsHeap()

//pre: heap has been created and follows heap property
//post: insert a new item into teh heap and heap still follows heap property
template<class ItemType>
void Heap<ItemType>::Insert(ItemType item) {
	//1. increment heap length by 1
	heapLength++; 

	//2. store new item at the end of the heap, say the location is j
	data[heapLength-1] = item; 
	
	//3. walk you way up from node j to root and compare values, swap if necessary 
	bool done = false; 
	int index = heapLength-1;
		
	while((index > 0) && (!done)) {
		if(data[index] > data[parent(index)]) {
			swap(data[index], data[parent(index)]); 
			index = parent(index);
		}//end if
		else 
			done = true; 
	}//end while 

	if(!IsHeap())
		cout<<"Insert() function failed, not a heap"<<endl; 
}//end Insert

//displays heap
template<class ItemType>
void Heap<ItemType>::Display() {
	cout<<"Heap contains "<<heapLength<<" elements\n";

	for(int i = 0; i < heapLength; i++) {
		cout<<i+1<<" : "<<data[i]<<endl;
	}//end for
}//end Display()

//pre: heap has been created and follows new heap
//post: modify item stored in position i to the newValue and repair heap property
//@param i: data[i] is the key value which will be modified
//@param newValue: new number that will replace data[i]. must be < parent 
template<class ItemType>
void Heap<ItemType>::Modify(int i, ItemType newValue){
	if(newValue > data[i] && newValue > data[parent(i)]) 
		cout<<"Invalid newValue"<<endl;
	else { 
		data[i] = newValue;
		bool done = false; 
		while((i > 0) && (!done)) {
			if(data[rightchild(i)] > data[leftchild(i)]) {
				swap(data[rightchild(i)], data[leftchild(i)]);
				i = parent(i);
			}//end if 
			else
				done = true; 	
		}//end while
	if(!IsHeap())
		cout<<"Modify() function failed, not a heap"<<endl; 
	}
}//end Modify


template<class ItemType>
ItemType Heap<ItemType>::GetRoot() {
	return data[0];	
}//end GetRoot()
