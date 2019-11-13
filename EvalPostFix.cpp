#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <stdlib.h> // for atof

double processOperator(std::string oper, double rand1, double rand2);
bool evalPostfix(std::vector<std::string> & v, std::stack<double> & s, double & result)
{
	if (v.empty() == true)
	{ // if vector is completely read then read the stack size
		if (s.size() == 1)
		{ // anchor case - case 1
			result = s.top();
			s.pop(); // empty stack
			return true;
		}
		else // error occured - anchor case - case 2 and 3 covered
			return false;
	}
	else
	{ // more tokens to read
		if ((v[0].compare("+") == 0) || (v[0].compare("-") == 0) || (v[0].compare("*") == 0) || (v[0].compare("/") == 0))
		{ // if the next token is an operator
			if (s.size() >= 2)
			{ // recursive case - case 5
				double rand1 = s.top();
				s.pop();
				double rand2 = s.top();
				s.pop();
				s.push(processOperator(v[0], rand2, rand1));
				v.erase(v.begin());
				return evalPostfix(v, s, result);
			}
			else // error occured - anchor case - case 4
				return false;
		}
		else // next token is an operand - recursive case - case 6
		{ // recursive case - case 
			s.push(atof(v[0].c_str()));
			v.erase(v.begin());
			return evalPostfix(v, s, result);
		}
	}
	return false; // should never be reached
}
double processOperator(std::string oper, double rand1, double rand2)
{
	if (oper.compare("+") == 0)
		return rand1 + rand2;
	else if (oper.compare("-") == 0)
		return rand1 - rand2;
	else if (oper.compare("*") == 0)
		return rand1 * rand2;
	else
		return rand1 / rand2;
}
