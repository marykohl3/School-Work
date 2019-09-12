/* Alexander Koniuta, Joey Houser, Mary Kohl
 * Algorithm to solve the printing neatly problem
 * Note: in the problem we assumed that the spaces were contained within the size of the word, e.g. 
 * a word size of 3 meant 2 characters + 1 space. If the directions are changed then this requires a 
 * little bit of tweaking but doesn't affect the overall runtime. 
 * 
 * We have three approaches: a brute force solution, a greedy solution, and a dynamic solution. 
 * Each algorithm is given the same input and parameters and is timed.
 */

#include<iostream> 
#include<vector>
#include<numeric>
#include<sstream>
#include<cmath>
#include<time.h>
#include<sys/time.h>
#include <climits>
#include <stdexcept> 

using namespace std; 
#define INF INT_MAX  

//brute force algorithm with time complexity of O(m^n)
/* This brute force algorithm takes both an input vector, output vector
 * line size, input vector size, index, and addition parameter
 * The input is provided by the user while the output is initialized to start at 1
 * The recursive call looks at a new index with a smaller total size
 * Returns the output vector which was called by reference
 * Idea is to observe every possibility for each line and return the best one
*/
vector<int> brute_force(vector<int> input, vector<int> &output, int m, int n, int &i, int &add) {
	// base case: function will recursively reach this at the end and return the output
    if(m == 0 || n == 0 || i == n || i > n) { 
        return output; 
	}
	// evaluate the addition of another word in the line
	add += input[i]++; 	//	"++" for the space between each word

	// if we add more words than allow characters on a line
	if (add >=  m) {   
        output.push_back(i);	// add i to the output array so we know 
		i++; 					
	    add = 0; 				// edit the index and return the add variable to 0 so we can start a new line
		return brute_force(input, output, m, n-1, i, add);	// recall function at a smaller n size 
	}
    else {	// if we can still put more strings in the line, recall the function with an edited add variable
    	i++;
        return brute_force(input, output, m - add, n-1, i, add);		// do not adjust the output array until a new line starts
    }//end else

}//end brute_force

//auxilliary function for the dynamic algorithm to output. runtime is T(n) = T(n-1) + 1, and time complexity is O(n)
void finalize_output_dynamic(int o[], int n)  
{
    if (o[n] == 1) //base case: the first line will always begin with word 1. 
    {
        cout<<o[n]<<" "<<n<<endl;  
        return;  
    }
    else //recursively get the line breaks
    {
        finalize_output_dynamic(o, o[n]-1);  
        cout<<o[n]<<" "<<n<<endl;
    }
    //return(i);    
}  
    
/* this dynamic algorithm takes a vector and line size/size paramaters as input, and calculates the 
 * configuration of words that leads to the least overall cost.
 * The runtime is T(n) = 6 + n((n+1)/2 + 1) + n((3(n+1))/2) + 1 + n(n+1) + O(n), and the time complexity is O(n^2)
 * The original approach involved  using vectors but the pointer arithmetic got too complicated without a predefined
 * size, so it was ultimately simpler to just use arrays for this algorithm. 
 */

void print_neatly_dynamic(vector<int> a, int m, int n)  
{   
    int lookup_table[n+1][n+1]; //table that stores the spaces at the end of the line
    int penalty[n+1][n+1];  //table that stores the penalty for a certain configuration
    int optimal_cost[n+1];  //the optimal cost of the entire confuguration 
    int output[n+1]; //array that contains line breaks
  
    int i, j;  
  
    /* table to get the number of extra spaces in a single line. I originally didn't have this,
     * but it was getting too clunky for me to code  so I accepted the space penalty 
     */
    for (i = 1; i <= n; i++)  
    {  
        lookup_table[i][i] = m - a[i-1];  
        for (j = i+1; j <= n; j++)  
            lookup_table[i][j] = lookup_table[i][j-1] - a[j-1] - 1;  
    }  
  
    /* Three possibilities: either the selected words don't fit on the line, in which case cost is infinite,
     * It's the last line, in which case cost will be 0, 
     * Or it fits and isnt the last line, in which case it's the cube of the penalty
     */
    for (i = 1; i <= n; i++)  
    {  
        for (j = i; j <= n; j++)  
        {  
            if (lookup_table[i][j] < 0)  //doesn't fit
            {
                penalty[i][j] = INF;  
            }
            else if (j == n && lookup_table[i][j] >= 0) //last line
            { 
                penalty[i][j] = 0;  
            }
            else //'acceptable' input 
            {
                penalty[i][j] = pow(lookup_table[i][j],3);  
            }
        }  
    } 

    /* get the optimal cost and conclude the output from there
     * Optimal substructure: the optimal cost of the next line is the optimal cost 
     * of the last line+the current penalty, so by solving subproblem i-1, we should 
     * arrive at the solution for problem i.
     * This is done in a bottom-up fashion.  
     */
    optimal_cost[0] = 0;  
    for (j = 1; j <= n; j++)  
    {  
        optimal_cost[j] = INF;  
        for (i = 1; i <= j; i++)  
        {  
            if (optimal_cost[i-1] != INF && penalty[i][j] != INF &&  
                (optimal_cost[i-1] + penalty[i][j] < optimal_cost[j])) //only add to the output array if the potential cost is the best
            {  
                optimal_cost[j] = optimal_cost[i-1] + penalty[i][j];  
                output[j] = i;  
            }  
        }  
    }  
  
    finalize_output_dynamic(output, n);  
}  

//auxilliary function to output greedy solution
void finalize_output_greedy(vector<int> o)
{
    vector<int> final_output;
    final_output.push_back(1);
    int size = o.size();
    
    for(int i = 0; i < size; i++)
    {
        final_output.push_back(o.at(i));
    }
    
    int final_size = final_output.size();

    cout<<final_output.at(0)<<" ";
    for(int i  = 1; i < final_size; i++)
    {
        cout<<final_output.at(i)<<" ";
        
        if(i % 2 == 1)
        {
            cout<<endl;
        }
    }
}

/* First attempt at constructing the algorithm. this is a greedy approach that attempts to pack as
 * many words as possible on one line. it is right in many cases but not all, but the time. I know
 * that this isn't part of the assignment but I thought it would be a good insight into our 
 * thought process for ultimately designing the dynamic solution. 
 * complexity is superior to dynamic: O(nm) vs O(n^2) 
 * runtime is T(n) 8 + O(n) + 4n + T(n-z), where z is the size of the array that is being deleted.
 * The time complexity is therefore O(nm) ->there are m while loops, where m is the final number of lines of output
 * Note: this destroys the vector. It is not nescessary but for clarity and a 
 * bit of space saving this approach was chosen.
 */
vector<int> print_neatly_greedy(vector<int> c, vector<int> o, int m, int placeholder, int n)
{
    int quit_sum = 0; 
    int i = 0; 
    int total_sum = accumulate(c.begin(), c.end(), 0); //O(n) time complexity
    int size = c.size();
    int z;

    if(total_sum < m) //exit condition/base case: when the size of the vector is less than m
    {
        o.push_back(n);
        return(o);
    }

    //add as many words as possible up to m, and store the location of the last word
    while(quit_sum <= m && i < size)
    {
        if((quit_sum+c.at(i) <= m))
        {
            quit_sum+=c.at(i);
            i++;
        }
        else //Prevents the while loop exceeding limit imposed by m. I couldn't think of a more elegant way off the top of my head. 
        {
            break;
        }
    }
    z = i + placeholder - 1; //the address of the minimum penalty + the placeholder carried over from previous iterations

    o.push_back(z); //update output
    o.push_back(++z); //the next line will always start at 1+ the preceeding line, so just add it in now
    c.erase(c.begin(), c.begin()+i); //destroy the elements that were just counted 
        
    return(print_neatly_greedy(c, o, m, z, n)); //continue onto the next search for the most words <= m
}

//driver
int main()  
{  
    vector<int> input; //input
    vector<int> storage; //for the greedy algorithm
    vector<int> greedy_output; //output of the greedy
    vector<int> dynamic_input;
    vector<int> brute_output; 
    int number; //for the input
    string input_string; //the entire line of input 
    cout<<"Enter c1... cN, then M:"<<endl;
    getline(cin, input_string); 
    istringstream stream(input_string);
    double elapsed; //time elapsed
    struct timeval begin, end; //taken from lab1 to time functions

    while(stream >> number) //parse the stream for numbers
    {
        input.push_back(number); 
    } 
    

    int line_length = input.back();  //get m
    input.pop_back(); //gets rid of m
    int word_quantity = input.size(); //get n
     
    // line length and word quantity must be at least 1 
    if (line_length <= 0 || word_quantity <= 0 || word_quantity < input.at(0)) {
	    cout<<"Invalid Entry"<<endl; 
	    exit(0); 
    }//end exceptions 

    copy(input.begin(), input.end(), back_inserter(dynamic_input));
    
    // begin brute force solution test
    cout<<"\nBrute Force Solution: "<<endl;
    gettimeofday(&begin, NULL); 	
    brute_output.push_back(1);
    int add = 0; 
    int k = 1;  
    brute_output = brute_force(input, brute_output, word_quantity, line_length, k, add);
    for(int i  = 0; i < brute_output.size(); i++)
    {
        if(i % 2 == 0)
        {
            cout<<endl;
        }
        cout<<brute_output.at(i)<<" ";
    }  
    gettimeofday(&end, NULL);	// measure time elapsed by algorithm
    elapsed = (end.tv_sec-begin.tv_sec)+((end.tv_usec-begin.tv_usec)/1000000.0);
    cout<<"\nBrute Force Time: "<<elapsed<<endl;
   // print_neatly_dynamic(dynamic_input, line_length, word_quantity);

	// begin dynamic solution test
    cout<<"\nDynamic solution:"<<endl;
    gettimeofday(&begin, NULL);
    print_neatly_dynamic(dynamic_input, line_length, word_quantity);
    gettimeofday(&end, NULL);
    elapsed = (end.tv_sec-begin.tv_sec)+((end.tv_usec-begin.tv_usec)/1000000.0); 	// measure time elapsed by algorithm
    cout<<"Dynamic Solution Time: "<<elapsed<<endl; 

	// begin greedy solution test
    cout<<endl<<"Greedy solution"<<endl;
    gettimeofday(&begin, NULL);
    greedy_output = print_neatly_greedy(input, storage, line_length, 1, word_quantity);
    finalize_output_greedy(greedy_output);
    gettimeofday(&end, NULL);
    elapsed = (end.tv_sec-begin.tv_sec)+((end.tv_usec-begin.tv_usec)/1000000.0);	// measure time elapsed by algorithm
    cout<<"Greedy Solution Time: "<<elapsed<<endl;
}  

