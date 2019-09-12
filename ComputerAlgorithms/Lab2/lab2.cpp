/*
 * Mary Kohl
 * Lab 2- Heap Driver File
 * 26 March 2019
 *
 */

#include <iostream>
#include "heap.h"
using namespace std;

/* arrange values in array a in ascending order
param a: the array
param size: the length of array (# of element)
*/
void heapsort(int a[], int size)
{
	Heap<int> heapInt(a, size);
	for (int i=size-1;i>=0;i--)
		a[i] = heapInt.RemoveRoot();
	if(!heapInt.IsHeap())
                cout<<"Something is wrong!"<<endl;
        else
                cout<<"heapsort works"<<endl;
}

int main()
{
	int data[5]={4, 10, 3, 5, 1};  

	Heap<int> intHeap (data, 5);

	if (!intHeap.IsHeap())
		cout <<"Something is wrong!\n";
	if(intHeap.IsHeap())
		cout<<"IsHeap()\n";

	intHeap.Display();

	//Insert a new element, and test heap property
	cout<<"Insert(8)"<<endl; 
	intHeap.Insert(8);	
	intHeap.Display(); 
	

	//Test Modify() to a larger value, to a smaller value
        cout<<"Modify(4, 2): data[4] will be replaced by 2"<<endl;
        intHeap.Modify(4, 2);
        intHeap.Display();
        cout<<"Modify(4, 6): data[4] will not  be replaced by 6"<<endl;
        intHeap.Display();


	//Test RemoveRoot. 
	cout<<"RemoveRoot(): "<<intHeap.GetRoot()<<endl; 
	intHeap.RemoveRoot();
	intHeap.Display(); 
	cout<<"New Root: "<<intHeap.GetRoot()<<endl; 

	//Test heapsort 
	cout<<"Testing HeapSort:";		
	heapsort(data, 5);
}
