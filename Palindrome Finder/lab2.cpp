/*
 * Mary Kohl
 * Lab 2: Palindrome
 * 10/15/2018
 *
 * This lab uses stack to check if a string of numbers or variables is a palindrome
 *
 */

#include<iostream>
#include<stack>
#include<cstdlib>

using namespace std;

//Functions
string cleanString(string str);
bool isPalindrome(string str);

int main() {
	string str;
	
	do {
	
	cout<<"Enter a string: ";

	getline(cin, str);

	str = cleanString(str);
	
	} while (str.length() == 0); //runs until user enters valid input

	if (isPalindrome(str))
		cout<<"input is a palindrome"<<endl;
	else
		cout<<"input is not a palindrome"<<endl;
   
	
}//End main

//pre: string is entered by user
//post: lowercase string is returned without punctuation and spaces
string cleanString(string str) {
	string clean_str;
	
	for (int i = 0; i < str.length(); i++) {
		if ((!ispunct(str[i])) && (!isspace(str[i])))
				clean_str += tolower(str[i]);
	}
	
	return (clean_str);
}//end cleanString

//pre: string is not case sensitive, does not have punctuation or spaces
//post: boolean value is returned based if string is a palindrome or not
bool isPalindrome(string str) {
	stack<char> s;
	
	bool palindrome = true;

	//push half of string into stack
        for (int i = 0; i < (str.length())/2; i++)
                s.push(str[i]);
	
	int n = (str.length()+1)/2;

	//check if palindrome using stack
        //for (int i = (str.length()+1)/2; i < str.length(); i++) {
        do {        
		if (s.top() == str[n]){
                        palindrome = true;
			s.pop();
		} else {
                        palindrome = false;
		}

		n++;

        } while (n < str.length() && palindrome== true);

	return (palindrome);
}//end isPalindrome
