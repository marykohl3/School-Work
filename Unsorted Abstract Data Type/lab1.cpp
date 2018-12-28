/* Mary Kohl 
 * Data Structures Lab 1
 * 09/25/18
 * Lab extends an UnsortedType ADT that is implemetnets with an array, four functions are added
 */

#include "ItemType.h"
#include "UnsortedList.h"

#include<iostream>

void PrintList( UnsortedListByArray& list)
// Pre:  list has been initialized.         
// Post: Each component in list has been written. 
// 
{
  int length;
  ItemType item;

  list.ResetList( );
  length = list.GetLength( );
  for (int counter = 1; counter <= length; counter++)
  {
    list.GetNextItem(item);
    item.Print( );
  }
}

int main(){

    UnsortedListByArray listOne, listTwo; //two UnsortedTypes that will be manipulated with the functions

    ItemType x;
    x.Initialize(1);
    listOne.InsertItem(x);

    ItemType y;
    y.Initialize(3);
    listOne.InsertItem(y);

    ItemType z;
    z.Initialize(5);
    listOne.InsertItem(z);

    ItemType a;
    a.Initialize(12);
    listOne.InsertItem(a);

    ItemType b;
    b.Initialize(10);
    listOne.InsertItem(b);

    ItemType c;
    c.Initialize(12);
    listOne.InsertItem(c);

    ItemType d;
    d.Initialize(0);
    listOne.InsertItem(d);

    cout<<"PrintList(listOne):\n";
    PrintList(listOne);

    //item y is deleted from listOne, list is printed
   listOne.DeleteAllItems(a);
   cout<<"DeleteAllItems(12): \n";
   PrintList(listOne);

   //item a is inserted into listOne if it does not already exist, list is printed
   cout<<"InsertItem:\n"; 
   bool done = false;
   listOne.InsertItem(a, done);
   PrintList(listOne);

    //listOne splits at item z into two lists
    cout<<"Split list:\n";
    listOne.SplitList(z, listOne, listTwo);
    PrintList(listOne);
    cout<<"--------\n";
    PrintList(listTwo);

    //lists are merged into listOne
    listOne.MergeList(listOne, listTwo);
    cout<<"MergeList:\n";
    PrintList(listOne);
    
    return 0;
}
