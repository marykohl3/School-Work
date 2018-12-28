// SPECIFICATION FILE		( UnsortedType.h )
#ifndef UNSORTEDLIST_H
#define UNSORTEDLIST_H

#include "ItemType.h"

class  UnsortedListByArray		// declares a class data type
{				
public : 			

  UnsortedListByArray();

  void MakeEmpty( );        // 8 public member functions
  void InsertItem( ItemType  item ); 	
  void DeleteItem( ItemType  item ); 
void DeleteAllItems(ItemType item);
void SplitList(ItemType item, UnsortedListByArray &list1, UnsortedListByArray &list2);
void MergeList(UnsortedListByArray &list1, UnsortedListByArray &list2);

  bool IsFull( ) const;
  bool IsEmpty( ) const;              
  int  GetLength( ) const;  // returns length of list
  void RetrieveItem( ItemType &  item, bool&  found );

  void InsertItem(ItemType item, bool &done);
  void ResetList( );
  void GetNextItem( ItemType&  item ); 	

private :
   int length; 
   ItemType info[MAX_ITEM]; 
   int currentPos;
};


#endif
