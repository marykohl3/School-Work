/*
 * VertextType.h
 * Mary Kohl 
 * 11/27/18
 *
 */

#ifndef VERTEXTYPE_H
#define VERTEXTYPE_H

#include"ItemType.h"

#include <iostream>
using namespace std;
	
enum  MARK {DEFAULT, VISITED, QUEUED};

struct VertexType{

		ItemType item; 
		MARK mark;

		void printValue() {
			cout<<item;
		}//end printValue
};

#endif

