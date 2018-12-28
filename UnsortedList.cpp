/* Mary Kohl
 * lab1
 * 09/25/18
 */

#include "UnsortedList.h"

//constructor
UnsortedListByArray::UnsortedListByArray()
{
  length = 0;
}

//check whether the list is full
bool UnsortedListByArray::IsFull() const
{
  return (length == MAX_ITEM);
}

//check how many elements are in this list
int UnsortedListByArray::GetLength( ) const
{
  return length;
}

//check whether there is element in this list
bool UnsortedListByArray::IsEmpty() const
{
  return (length == 0);
}

//Pre: the list should not be full
// Post: item is in the list.
void UnsortedListByArray::InsertItem(ItemType item)
{
  info[length] = item;
  length++;
}

// Pre:  Key member(s) of item is initialized. 
// Post: If found, item's key matches an element's key in the 
//       list and a copy of that element has been stored in item; 
//       otherwise, item is unchanged.
void UnsortedListByArray::RetrieveItem(ItemType& item, bool& found) 
{
  bool moreToSearch;
  int location = 0;
  found = false;
  moreToSearch = (location < length);
  while (moreToSearch && !found) 
  {
    switch (item.ComparedTo(info[location]))
    { case LESS    : 
      case GREATER : location++;
                     moreToSearch = (location < length);
                     break;
      case EQUAL   : found = true;
                     item = info[location];
                     break;
    }
  }
}

// Pre: item's key has been inititalized.
//	One and only one element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item�s.
void UnsortedListByArray::DeleteItem ( ItemType  item ) 
{    
  int  location  =  0 ;

  while (item.ComparedTo (info[location])  !=  EQUAL)
         location++;
  // move last element into position where item was located

  info [location] = info [length - 1 ] ;
  length-- ; //the length of the list is decreased
}

// Pre:  N/A   
// Post: the list is empty
void UnsortedListByArray::MakeEmpty()
{
   length = 0;
}


// Pre:  List has been inititalized.
// Post: Current position is prior to first element.
void UnsortedListByArray::ResetList ( )  
{    
  currentPos  =  -1 ;
}

// Pre:  List has been initialized. Current position is 
//       defined. 
//       Element at current position is not last in list.
// Post: Current position is updated to next position.
// 	  item is a copy of element at current position.
void UnsortedListByArray::GetNextItem ( ItemType&  item )  
{
  currentPos++  ;
  item = info [currentPos] ;
}

//Pre: list has been initizlized and is not empty. The list has at least one copy of the item
//Post: list does not have any copies of the item
void UnsortedListByArray::DeleteAllItems ( ItemType  item ) {
	bool done = false;
	RetrieveItem(item, done);
	
	if ((done == false) || IsEmpty()) {
		cout<<"item does not exist\n";
	}//End if
	else {
		for(int i = 0; i < length; i++){
			if (item.ComparedTo(info[i]) == EQUAL) {
				info[i] = info[length-1];
				length--;
			}//End if
		}//End for
	}//End else
}//End DeleteAllItems

//Pre:List has been initialized
//Post: List shoudl have at least one copy of the item
void UnsortedListByArray::InsertItem(ItemType item, bool &done) {
	RetrieveItem(item, done);
	
	if (done == false)
		InsertItem(item);
	else
		cout<<"item already exists\n";
}//End InsertItem

//Pre: list has been initilzaied and is not empty. listOne and listTwo are initialized but empty
//Post: listOne contins all the items of the list whose keys are less than or equal to the item's key. listTwo contains all the items of list whose keys are greater than the item's key
void UnsortedListByArray::SplitList(ItemType item, UnsortedListByArray &list1, UnsortedListByArray &list2) {
	UnsortedListByArray listTemp;

	listTemp.MakeEmpty();

	for (int i = 0; i < length; i++){
		if(item.ComparedTo(info[i]) == GREATER)
			listTemp.InsertItem(info[i]);
		else
			list2.InsertItem(info[i]);

	}
	list1 = listTemp;	//make listTemp list1 due to address return 
}//End SplitList

//Pre: list has been initialized. listOne and listTwo have been initialized
//Post: list contains all items from listOne and listTwo
void UnsortedListByArray::MergeList(UnsortedListByArray &list1, UnsortedListByArray &list2) {
	UnsortedListByArray listTemp;

	list1.ResetList();
	
	for (int i = 0; i < list1.GetLength(); i++){
		listTemp.InsertItem(list1.info[i]);
	}
	
	for (int i = 0; i < list2.GetLength(); i++)
		listTemp.InsertItem(list2.info[i]);
	
	list1 = listTemp;	//make listTemp list1 due to address return
	list2.MakeEmpty();	//make list2Empty since it has no info now
}//End mergelist
