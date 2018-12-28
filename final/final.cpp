/*
 * Mary Kohl
 * 12/14/2018
 * finalProject.cpp
 * postfix calculator
 */

#include<iostream>
#include<string>
#include<stack>
#include<ctype.h> // for isdigit()

using namespace std;

//Used overflow_error as my exception class, using cplusplus.com as reference

//Calculator Precedence
//determines the precedence of operands and returns respective value
int precedence(char op) {
	if (op == '+' || op == '-')
		return 1; 
	else if (op == '*' || op == '/')
		return 2;
	else 
		return 0;	//function only works for +, -, *, /
}//end precendece

//infixToPostfix
//takes a string and converts into postfix notation while checking for errors using std::overflow_error
string infixToPostfix(string input) {
	stack<char>equation;
	string postfix;

	//Parenthesis counter:
	int open = 0;
	int close = 0;

	 for(int i = 0; i <= input.length(); i++) {
                if(input[i] == '(')
                        open++;
                if(input[i] == ')')
                        close++;
        }//end for

        if (open != close)
                throw std::overflow_error("Not equal amount of parenthesis\n");

	//PostFix Loop
	for(int i = 0; i < input.length(); i++) {
		//1 and 2 ...
		if(isdigit(input[i])) {
			int x = 1;
			postfix += input[i];
		
			while(isdigit(input[i+x])){	
				postfix += input[i+x];
				x++;
			}//end while
		
			postfix += " ";
		
			i += (x - 1);
		}//end if	
		
		//3. if it is opening parenthesis...
		else if(input[i] == '(') {
			equation.push(input[i]);
		}//end else if

		//4. if it is an operator then...
		else if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'){
			if(equation.empty() || equation.top() == '(' || precedence(input[i]) > precedence(equation.top())){
				equation.push(input[i]);

			}//end if
			else { 					//4d, else pop the operator from the stack...
				postfix += equation.top();
				postfix += " ";
				equation.pop();
				equation.push(input[i]);
			}//end else
			
			//Extra Operator Exception
			if((!isdigit(input[i+1]) && input[i+1] != '(') || i == input.length())
                                throw std::overflow_error("Extra operator\n");
		}//end else if
		
		//5. if it is a closed parenthesis...
		else if(input[i] == ')'){
			while(equation.top() != '('){
				postfix += equation.top();
				postfix += " ";
				equation.pop();
			}//end while
			if(equation.top() == '(') {
				equation.pop(); //pop final value
			}
		}//end else if

		//Invalid Operator Exception
		else
			throw std::overflow_error("Invalid operator\n");

		//Add Space
		if (!isdigit(input[i+1]) && input[i+1] != ' ')
			postfix += ' ';
	}

	while(!equation.empty()) {
		if(equation.top() != ')') {
			postfix += equation.top();
			postfix += " ";
		}
		equation.pop();
	}//end while

	return (postfix);

}//end infixToPostfix

//calculator
//basic calculator containting the division by zero exception class
double calculator(double int1, double int2, char op) {
        double answer; 

	switch(op) {
                case('+'):
                        answer = (int1 + int2);
                        break;
                case('-'):
                        answer = (int1 - int2);
                        break;
                case('*'):
                        answer = (int1 * int2);
                        break;
                case('/'):
			if (int2 == 0)
				//Divide by 0 Exception
				//output is not seen but caught by calculatePost
				throw std::overflow_error("Calculator Error: Cannot divide by 0\n");
			else
                                answer = (int1 / int2);
			break;
        }//end switch

        return answer;

}//end calculator


//calculatePost
//calculates the equation using postfix and calling the calculator function
double calculatePost(string postFix) {
	int op1, op2;
	stack<int>answer;
	string tempString;

	for (int i = 0; i < postFix.length(); i++) {
		int x = 1; 

		if(isdigit(postFix[i])) {
			tempString = ""; 
			tempString += postFix[i];		

			while(isdigit(postFix[i+x])) {
				tempString += postFix[i+x];
				x++;
			}//end while

			i += (x - 1);
			
			answer.push(stod(tempString, NULL)); //convert string to double

		}//end if

		if ((postFix[i] == '+') || (postFix[i] == '-') || (postFix[i] == '*') || (postFix[i] == '/')) {
			char op = postFix[i];
			double result; 
			
			op2 = answer.top(); //op2 needs to be first incase it is 0
			answer.pop();
			op1 = answer.top();
			answer.pop();
			
			try {
				result = calculator(op1, op2, op);
			}//end try
		
			catch (overflow_error exception) {
				throw std::overflow_error("Cannot divide by zero\n");
			}//end catch
			
			answer.push(result);

		}//end else if	
		
	}
	return (answer.top());
}//end calculatePost

int main () {
	string preFix, postFix;
	double answer;
	string resp; //user response to continue

	do {
		cout<<"Enter a calculation: ";
		getline(cin, preFix);

		try {
			postFix = infixToPostfix(preFix);
			cout<<"PostFix is: "<<postFix<<endl;
       			answer = calculatePost(postFix);
        		cout<<preFix<<" = "<<answer<<endl;
	
		} catch (overflow_error exception) {
			cout<<exception.what()<<endl;
		}//end catch
		cout<<"Do you want to continue? (y/n) ";
	//	getline(cin, resp);
		cin>>resp;
		cin.ignore(256, '\n');
	} while (resp == "y");
}//End main
