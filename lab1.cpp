/*
 * Mary Kohl 
 * Lab1.cpp
 * Computer Algorithms
 * 4 Feb 2019
 * This lab times the sorting algorithms and is the extra credit EXTENTION portion 
 *
 */

using namespace std;
#include<vector>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<sys/time.h>

/*
 * Generate an vector and fill it with random integers between 1 and 10,000
 * return the address of the array
 * @param v1: vector that will be returned 
 * @param array: array that is generated and then pushed into the vector
 * @param size: the size of the array to be generated
 * @return the vector 
 * */
vector<int> GenerateRandomVector(int size) {
	srand(time(0));
	vector<int> v1;
	int array[size];

	for (int i = 0; i < size; i++) {
		array[i] = rand()%9999;
		v1.push_back(array[i]);
	}//end for

	return(v1);
}//end GenerateRandomVector

/*display the content of the vector*/
void PrintVector (vector<int> &intList) {
	for (int i = 0; i < intList.size(); i ++) {
		cout<<intList[i]<<" ";
	}
	cout<<endl;
}//end PrintVector

//swaps two values using pointers
//@param x, y are the values being swapped
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}//end swap

//checks to see if a vector is sorted in ascending order and outputs the answer
//@param sorted: function was made a void from a bool to avoid repetition of code
template <class T>
void  IsSorted(vector<T> a) {
	bool sorted = true; 
	for (int i = 0; i < a.size(); i++) {
		if (a[i] > a[i+1]) {
			sorted = false; 
			break;
		}
	}//end for loop	

	if(sorted)
		cout<<"correct!"<<endl;
	else
		cout<<"Not Sorted"<<endl;
}//end IsSorted

//recursive bubbleSort algorithm
//@param a is the vector being sorted
//@param size is the size of the vector
//@precondition: a has been filled with elements 0 to size - 1
//@postcondition: a has been sorted in ascending order
template<class T>
void bubbleSort(vector<T> &a, int size) {
        
	if (size <= 1)
                return;

        for (int i = 0; i < size - 1; i++) {
		if (a[i] > a[i+1])
                        swap(a[i], a[i+1]);
        }//end for

        bubbleSort(a, size-1);
}//end bubbleSort

//i could not get the recursive algorithm to work for insertion sort
//@param a is the vector being sorted
//all other parameters are self explainatory and based off of the homework and book
//@precondition: a has been filled with elements 0 to size - 1
//@postcondition: a has been sorted in ascending order
template<class T>
void insertionSort(vector<T> & a) {
	int key;
	int j;

	for(int i = 1; i < a.size(); i++) {
		key = a[i];
		j = i - 1;

		while (j >= 0 && a[j] > key) {
			a[j+1] = a[j];
			j--;
		}

		a[j+1] = key;
	}//end for	

}//end insetionSort

//merges array by accordance for mergesort
//@param p: starts with left and iterated
//@param q: middle value iterator 
//@param k: iterator at 0
//@param b: alternate array that is merged
template<class T>
void merge(vector<T> & a, int left, int mid, int right) {
	int p = left; 
	int q = mid+1;
	int k = 0; 
	int b[right-left+1];

	for(int i = left; i <= right; i++) {
    		if(p > mid)
       			b[k++] = a[q++] ;
   		else if (q > right)
       			b[k++] = a[p++];
   		else if(a[p] < a[q])
      			b[k++] = a[p++];
   		else
      			b[k++] = a[q++];
 	}//end for	
  	for (int i = 0 ; i < k; i++) 
    		a[left++] = b[i];                          
}//end merge

//@param a is the vector being sorted
//@param left is the first most value in the array
//@param rightis the last most value in the array
//@precondition: a has been filled with elements 0 to size - 1
//@postcondition: a has been sorted in ascending order by using the concept of mergesort
template<class T>
void mergeSort(vector<T> & a, int left, int right) {
         if(left < right) {
           int mid = (left + right) / 2 ; 
           mergeSort(a, left, mid);                
           mergeSort(a, mid+1, right);              
           merge(a, left, mid, right);   
	 }//end if 
}//end mergeSort

//partition function finds the partition value for quicksort
template<class T>
int partition(vector<T> & a, int left, int right) {
	int piv = a[right];
	int i = (left - 1);

	for (int j = left; j <= right - 1; j++) {
		if(a[j] <= piv) {
			i++; 
			swap(&a[i] , &a[j]);
		}//end if
	}//end for

	swap(&a[i+1], &a[right]);

	return (i+1);
}//end parition

//@param a is the vector being sorted
//@param left is the first most value in the array
//@param rightis the last most value in the array
//@precondition: a has been filled with elements 0 to size - 1
//@postcondition: a has been sorted in ascending order by using the concept of quicksort
template<class T>
void quickSort(vector<T> & a, int left, int right) {
	if (left < right) {
		int par = partition(a, left, right); 
		quickSort(a, left, par-1);
		quickSort(a, par+1, right); 
	}//end if
}//end quickSort

//recursive selectionSort algorithm
//@param a is the vector being sorted
//@param size is the size of the vector
//@param min is the minimum value a[i] that is compared in selection sort...ie minimum in location on list, not value
//@param iterator is the iterator starting at 0 for recursive loop
//i did not set the iterator to be zero incase the user implemented the funtion a different way and i wanted to acoid error
//@precondition: a has been filled with elements 0 to size - 1
//@postcondition: a has been sorted in ascending order
template<class T>
void selectionSort(vector<T> &a, int size, int iterator) {
	
	if (iterator == size)
		return;

	int min = iterator;
	
	for (int j = (iterator + 1); j < size; j++) {
		if(a[j] < a[min])
			min = j;
	}//end for

        swap(a[min], a[iterator]);
	
	if (iterator + 1 < size) 
	   selectionSort(a, size, (iterator+1));

}//end selectionSort


/*
 Measure running time of three sorting algorithms, using
 randomly generated array of given size (input_size)
 Find and return avg, min and max running time for the @run_numer runs
   (recall that for different input instance, the running time of an algorithm
    can vary due to many factors, one of them being some input are easier to
     sort), here we want to repeat the experiements for @run_number times
     and report the minimum, maximum, and average from these runs
     
     parameters explained in comments within code

     some parameters and calculations are from the fib code on the course page - these should be obvious
*/
void MeasureSortingFunction (int input_size, int run_number) {
	struct timeval begin, end; //from fib code on class page
	double elapsed;
	int result1, result2;
	float b_average, b_min, b_max; //varibale for bubblesort
	float s_average, s_min, s_max; //variagbles for selection sort
      	float  i_average, i_min, i_max; //varibales for insertion sort
	float m_average, m_min, m_max; 
	float q_average, q_min, q_max; 

	for (int i = 0; i < run_number; i++) {
		vector<int> same_input = GenerateRandomVector(input_size);
		vector<int> work_copy = same_input;

		//bubblesort
		gettimeofday(&begin, NULL);
		bubbleSort(work_copy, input_size);
		gettimeofday(&end, NULL);
		elapsed = (end.tv_sec-begin.tv_sec)+((end.tv_usec-begin.tv_usec)/1000000.0);
		if (b_min > elapsed || b_min == 0)
			b_min = elapsed;
		if (b_max < elapsed || b_max == 0)
			b_max = elapsed;
		b_average = (b_average + elapsed) / (i+1);

		//selection sort
		work_copy = same_input;
		selectionSort(work_copy, input_size, 0);
                gettimeofday(&end, NULL);
                elapsed = (end.tv_sec-begin.tv_sec)+((end.tv_usec-begin.tv_usec)/1000000.0);
                if (s_min > elapsed || s_min == 0)
                        s_min = elapsed;
                if (s_max < elapsed || s_max == 0)
                        s_max = elapsed;
                s_average = (s_average + elapsed) / (i+1);

		 //insertion sort
                work_copy = same_input;
                insertionSort(work_copy);
                gettimeofday(&end, NULL);
                elapsed = (end.tv_sec-begin.tv_sec)+((end.tv_usec-begin.tv_usec)/1000000.0);
                if (i_min > elapsed || i_min == 0)
                        i_min = elapsed;
                if (i_max < elapsed || i_max == 0)
                        i_max = elapsed;
                i_average = (i_average + elapsed) / (i+1);
		
		//merge
		work_copy = same_input;
                mergeSort(work_copy, 0,  input_size-1);
                gettimeofday(&end, NULL);
                elapsed = (end.tv_sec-begin.tv_sec)+((end.tv_usec-begin.tv_usec)/1000000.0);
                if (m_min > elapsed || m_min == 0)
                        m_min = elapsed;
                if (m_max < elapsed || m_max == 0)
                        m_max = elapsed;
                m_average = (m_average + elapsed) / (i+1);

		//quick sort
		work_copy = same_input; 
                quickSort(work_copy, 0,  input_size-1);
                gettimeofday(&end, NULL);
                elapsed = (end.tv_sec-begin.tv_sec)+((end.tv_usec-begin.tv_usec)/1000000.0);
                if (q_min > elapsed || q_min == 0)
                        q_min = elapsed;
                if (q_max < elapsed || q_max == 0)
                        q_max = elapsed;
               q_average = (q_average + elapsed) / (i+1);

	}//end for

//See above EXTRA CREDIT EXTENION to see why this part was commented out
//	cout<<input_size<<"\t\t\t"<<b_average<<"\t"<<b_min<<"\t\t"<<b_max;
//	cout<<"\t\t\t\t"<<s_average<<"\t\t"<<s_min<<"\t\t"<<s_max;
//	cout<<"\t\t\t"<<i_average<<"\t\t"<<i_min<<"\t\t"<<i_max<<endl;
	cout<<input_size<<"\t\t\t"<<q_average<<"\t\t"<<q_min<<"\t\t"<<q_max;
	cout<<"\t\t\t\t"<<m_average<<"\t\t"<<m_min<<"\t\t"<<m_max<<endl;
}//end MeasureSortingFunction

int main() {
	vector<int> v1; // vector that will be randomally generated

	int size = 10; // size of vector 
	int run_time = 10; // amount of run times

	v1 = GenerateRandomVector(size); 
	
	cout<<"Original Vector: ";
	PrintVector(v1);
	vector<int> copy_v1 = v1; //copy of v1

	cout<<"1. Testing the three sorting algorthims:"<<endl;
	cout<<"Testing bubble sort with an array of size "<<size<<": ";
	bubbleSort(copy_v1, size);
	IsSorted(copy_v1);

	cout<<"Testing insertion sort with an array of size "<<size<<": ";
        copy_v1 = v1;
	insertionSort(copy_v1);
        IsSorted(copy_v1);

	cout<<"Testing selection sort with an array of size "<<size<<": ";
        copy_v1 = v1;
	selectionSort(copy_v1, size, 0);
        IsSorted(copy_v1);

	cout<<"Testing mergesort with an array of size "<<size<<": ";
        copy_v1 = v1;
        mergeSort(copy_v1, 0, size-1); 
        IsSorted(copy_v1);

	cout<<"Testing quick sort with an array of size "<<size<<": ";
        copy_v1 = v1;
        quickSort(copy_v1, 0, size-1);
        IsSorted(copy_v1);

	cout<<"Summary of measurement results:"<<endl;
	cout<<"Input Size\t\tbubble\t\t\t\t\t\t\t\tselection\t\t\t\t\t\t\tinsert\n";
      cout<<"\t\t\tavg\t\tmin\t\tmax\t\t\t\t\tavg\t\t\tmin\t\tmax\t\t\tavg\t\t\tmin\t\tmax\n";
	
	MeasureSortingFunction(size, run_time);

//For viewing purposed, the extra credit extension only shows the quick and merge sort
/*
	cout<<endl<<"*********************************EXTRA CREDIT #6*********************************"<<endl;

	//note: orientation of information gets mixed, this was the best that i could do and the results are accurate which is what is being counted
	cout<<"Input Size\t\tbubble\t\t\t\t\t\t\t\t\tselection\t\t\t\t\t\tinsert\n";
        cout<<"\t\t\tavg\t\tmin\t\tmax\t\t\t\t\t\tavg\t\tmin\t\tmax\t\t\tavg\t\tmin\t\tmax\n";
	MeasureSortingFunction(10, run_time);
	MeasureSortingFunction(20,run_time);
	MeasureSortingFunction(40, run_time);
        MeasureSortingFunction(50, run_time);
	MeasureSortingFunction(100, run_time);
        MeasureSortingFunction(200, run_time);
	MeasureSortingFunction(500, run_time);
	MeasureSortingFunction(1000, run_time);

	cout<<"Extra credit answers are in comments"<<endl;
*/
	//EXTRA CREDIT ANSWERS
	//Do the running time of the three algorithms grow quadratically when the size of input grows?
	//the run times of all the algorithms grow exponentially when the size of the input grows 
	//How do you explain the difference in running time by the three algorithms?
	//in order of smallest to largest growth: bubble < selection < insertion
	
	cout<<endl<<"*********************************EXTRA CREDIT EXTENTION*********************************"<<endl;
	cout<<"Only showing QuitSort and MergeSort since original lab showed Bubble, Insertion, and Selection. I did this to make sure that the QuickSort and MergeSort data could be displayed properly"<<endl; 
        //note: orientation of information gets mixed, this was the best that i could do and the results are accurate which is what is being counted
        cout<<"Input Size\t\tquicksort\t\t\t\t\t\t\t\t\t\tmerge\n";
        cout<<"\t\t\tavg\t\t\tmin\t\t\tmax\t\t\t\t\tavg\t\tmin\t\tmax\n";
	MeasureSortingFunction(10, run_time);
        MeasureSortingFunction(20,run_time);
        MeasureSortingFunction(40, run_time);
        MeasureSortingFunction(50, run_time);
        MeasureSortingFunction(100, run_time);
        MeasureSortingFunction(200, run_time);
        MeasureSortingFunction(500, run_time);
        MeasureSortingFunction(1000, run_time);

}//end main

