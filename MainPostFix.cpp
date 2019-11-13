#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <stdlib.h> // for atof

bool evalPostfix(std::vector<std::string> & v, std::stack<double> & s, double & result);
void emptyStack(std::stack<double> & s);
bool isSame(double x, double y);
int main()
{
	std::cout << "COP3530 - Homework 4 Task 2 by Gregory Hudson" << std::endl;
	int testcount = 1;
	std::vector<std::string> v;
	std::stack<double> s;
	double result;
	bool found;

	// Test case #1 test the + operator
	std::string array1[] = { "2.2", "-108.3", "+", "-" }; // 2.2 -108.3 + Postfix expression
	emptyStack(s);
	v = std::vector<std::string>(array1, array1 + 3);  // load the vector with the tokens
	found = evalPostfix(v, s, result);
	if ((found == true) && (isSame(result, -106.1) == true))
		std::cout << "Test case " << testcount << " Passed" << std::endl;
	else
		std::cout << "Test case " << testcount << " Failed" << std::endl;
	testcount++;

	// Test case #2  -  valid expression
	emptyStack(s);
	v = std::vector<std::string>(array1, array1 + 1);  // load the vector with the tokens
	found = evalPostfix(v, s, result);
	if ((found == true) && (result == 2.2))
		std::cout << "Test case " << testcount << " Passed" << std::endl;
	else
		std::cout << "Test case " << testcount << " Failed" << std::endl;
	testcount++;

	// Test case #3  -  invalid empty expression
	emptyStack(s);
	v = std::vector<std::string>(array1, array1 + 0);  // load the vector with the tokens
	found = evalPostfix(v, s, result);
	if (found == false)
		std::cout << "Test case " << testcount << " Passed" << std::endl;
	else
		std::cout << "Test case " << testcount << " Failed" << std::endl;
	testcount++;

	// Test case #4  -  invalid expression
	emptyStack(s);
	v = std::vector<std::string>(array1, array1 + 2);  // load the vector with the tokens
	found = evalPostfix(v, s, result);
	if (found == false)
		std::cout << "Test case " << testcount << " Passed" << std::endl;
	else
		std::cout << "Test case " << testcount << " Failed" << std::endl;
	testcount++;

	// Test case #5  -  invalid expression
	emptyStack(s);
	v = std::vector<std::string>(array1, array1 + 4);  // load the vector with the tokens
	found = evalPostfix(v, s, result);
	if (found == false)
		std::cout << "Test case " << testcount << " Passed" << std::endl;
	else
		std::cout << "Test case " << testcount << " Failed" << std::endl;
	testcount++;

	// Test case #6  -  invalid expression
	emptyStack(s);
	v = std::vector<std::string>(array1+2, array1 + 3);  // load the vector with the tokens
	found = evalPostfix(v, s, result);
	if (found == false)
		std::cout << "Test case " << testcount << " Passed" << std::endl;
	else
		std::cout << "Test case " << testcount << " Failed" << std::endl;
	testcount++;

	// Test case #7  -  invalid expression
	emptyStack(s);
	v = std::vector<std::string>(array1 + 2, array1 + 4);  // load the vector with the tokens
	found = evalPostfix(v, s, result);
	if (found == false)
		std::cout << "Test case " << testcount << " Passed" << std::endl;
	else
		std::cout << "Test case " << testcount << " Failed" << std::endl;
	testcount++;

	// Test case #8  -  test subtract
	std::string array2[] = { "2.2", "-108.3", "-", "-" }; // 2.2 -108.3 - Postfix expression
	emptyStack(s);
	v = std::vector<std::string>(array2, array2 + 3);  // load the vector with the tokens
	found = evalPostfix(v, s, result);
	if ((found == true) && (isSame(result, 110.5) == true))
		std::cout << "Test case " << testcount << " Passed" << std::endl;
	else
		std::cout << "Test case " << testcount << " Failed" << std::endl;
	testcount++;

	// Test case #9  -  test multiply
	std::string array3[] = { "2.2", "-108.3", "*", "-" }; // 2.2 -108.3 * Postfix expression
	emptyStack(s);
	v = std::vector<std::string>(array3, array3 + 3);  // load the vector with the tokens
	found = evalPostfix(v, s, result);
	if ((found == true) && (isSame(result, -238.26) == true))
		std::cout << "Test case " << testcount << " Passed" << std::endl;
	else
		std::cout << "Test case " << testcount << " Failed" << std::endl;
	testcount++;

	// Test case #10  -  test division
	std::string array4[] = { "10", "-2", "/", "-" }; // 2.2 -108.3 / Postfix expression
	emptyStack(s);
	v = std::vector<std::string>(array4, array4 + 3);  // load the vector with the tokens
	found = evalPostfix(v, s, result);
	if ((found == true) && (isSame(result, -5) == true))
		std::cout << "Test case " << testcount << " Passed" << std::endl;
	else
		std::cout << "Test case " << testcount << " Failed" << std::endl;
	testcount++;

	// Test case #11  -  larger expression
	std::string array5[] = { "2", "3", "4", "+", "5", "6", "-", "-", "*" }; // 2 3 4 + 5 6 - - * Postfix expression
	emptyStack(s);
	v = std::vector<std::string>(array5, array5 + 9);  // load the vector with the tokens
	found = evalPostfix(v, s, result);
	if ((found == true) && (isSame(result, 16) == true))
		std::cout << "Test case " << testcount << " Passed" << std::endl;
	else
		std::cout << "Test case " << testcount << " Failed" << std::endl;
	testcount++;

	// Test case #12  -  larger expression
	std::string array6[] = { "2", "3", "*", "8", "4", "/", "1", "/", "+", "11", "+" }; //  2  3 *  8  4 /  1 / +  11 + Postfix expression
	emptyStack(s);
	v = std::vector<std::string>(array6, array6 + 11);  // load the vector with the tokens
	found = evalPostfix(v, s, result);
	if ((found == true) && (isSame(result, 19) == true))
		std::cout << "Test case " << testcount << " Passed" << std::endl;
	else
		std::cout << "Test case " << testcount << " Failed" << std::endl;
	testcount++;

	return 0;
}
bool isSame(double x, double y)
{
	double error = .00001;
	bool rv = false;
	if (((x + error) >= y) && ((x - error) <= y))
	{
		rv = true;
	}
	return rv;
}
void emptyStack(std::stack<double> & s)
{
	for (; s.size() > 0;)
	{
		s.pop();
	}
}
