/*Mary Kohl
 * 23 April 2019
 * Midterm Q6
 */

#include <iostream>
#include <stdio.h>
#include<sys/time.h>

using namespace std;

void CheckDuplicates(int A[], int n){
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			if (A[i] == A[j])
				cout<<"A["<<i<<"] = A["<<j<<"]\n";
		}//end for j
	}//end for i 
}//end CheckDuplicats
/*
int partition(int a[], int left, int right) {
	int pivot = a[right];
	int temp =0; 
	int i = left - 1;

       for(int j = left; j <=right -1; j++) {
                        if (a[j] <= pivot) {
                                i++;
                                temp = a[i];
                                a[i] = a[j];
                                a[j] =temp;
                        }
                }//end for
                temp = a[i+1];
                a[i+1] = a[right];
                a[right] = temp;

		return(i+1);
}//end parition 
void quickSort(int a[], int left, int right) {
	if (left < right) {
		int pi = partition(a, left, right);
		quickSort(a, left, pi-1); 
		quickSort(a, pi+1, right);
	}
}//end quickSort */
int CheckFaster(int a[], int left, int right, bool checked) { 
	if (left > right) 
		return -1; 
	if (a[left] == a[right]) {
		checked = true; 
		return left; 
	}
		int mid = (left + right) / 2;
		CheckFaster(a, left, mid, false); 
		CheckFaster(a, mid+1, right, false);	
	 for (int i = 0; i < right; i++) {
                for (int j = i + 1; j < right - 1; j++) {
                        if (a[i] == a[j])
                                return i; 
		}
	}
}//end Check Faster

int main () {
	int n = 12;
	int A[n] = {1, -30, -30, 20, 3, 20, -3, -3, -2, 18, -30, 5};
	//gettimeofday(&begin, NULL);
	cout<<"Brute Force Check Duplicates"<<endl; 
	CheckDuplicates(A, n);
	cout<<"Divide and Conquer Check Duplicates"<<endl; 
	int i = CheckFaster(A, 0, n-1, false); 	
       cout<<"Check faster exists at A["<<i<<"]"<<endl;	
}//end main
