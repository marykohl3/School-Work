/*Mary Kohl 
 * 23 April 2019
 * Midterm #6 Correction 
 * Computer Algorithsms
 */

using namespace std;
#include<vector>
#include<iostream>
#include<stdlib.h>

//Prints Array
void Print(int A[], int n) {
	for(int i = 0; i < n; i++)
		cout<<"A["<<i+1<<"] = "<<A[i]<<endl;
}

//Finds the index value of array so that A[6] = 6
//returns -1 if there is no such value
int FindIndexValue(int A[], int left, int right) {
	int mid = (left + (right-1)) / 2;
	if (mid == A[mid-1])
		return mid;
	else if (mid < A[mid-1]) 	
		return FindIndexValue(A, left, mid-1);
	else if (mid > A[mid-1])
		return FindIndexValue(A, mid+1, right); 
	else
		return -1; 

}//end FindIndexValue

int main () {
	cout<<"Given a sorted arrat of distince integers A[1...n], you want to\nfind out whether there is an index i for which A[i]=i.\nGive a divide-and-conquer algorithm that runs\nin time O(logn)"<<endl;
	int n = 10; 
	int A[n] = {1,2,3,4,5,6,7,8,9,10};

	int left = 0; 
	int right = 9; 
	
	cout<<"ARRAY A"<<endl;
	Print(A, n);
	cout<<"Index A[i] = i at: "<<FindIndexValue(A, left, right)<<endl;	

	cout<<"\n ARRAY B"<<endl;
	int B[n] = {1, 3, 5, 6, 7, 8, 9, 10, 12, 13};
	Print(B, n);
	cout<<"Index B[i] = i at: "<<FindIndexValue(B, left, right)<<endl;
	
	cout<<"\n ARRAY C"<<endl; 
	int C[n] = {0, 1, 2, 3, 4, 5, 7, 10, 12, 13};
	Print(C, n); 
	cout<<"Index C[i] = i at: "<<FindIndexValue(C, left, right)<<endl;
}//end main
