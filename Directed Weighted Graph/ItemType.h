/*
 * ItemType.h
 * Mary Kohl
 * 11/27/18
 *
 */

#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <iostream>
using namespace std;

const int  MAX_ITEM = 10;

enum  RelationType {LESS, EQUAL, GREATER};

class  ItemType {						
	
	friend ostream &operator<<(ostream &output, const ItemType& it ){  
     		output<<it.value; 
     		return (output);
  	}
	
	public:
	
	ItemType() {}

  	RelationType ComparedTo(ItemType otherItem) const {						
    		if (value < otherItem.value)
       			return LESS;
    		else if (value > otherItem.value)
       			return GREATER;
    		else  return EQUAL;
  	}//End ComparedTo

  	void Print() const {
   		cout<<value<<endl;
  	}//End Print

   	void Initialize(int value){
    		this->value  =  value;              
  	} 	           

	private :		
		char  value; 		 
} ;
#endif	

