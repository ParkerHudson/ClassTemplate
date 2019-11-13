#include <iostream>
#include <string>
#include "LinkedList.h"

bool compareArray(int array1[], int array2[], int count);
void testCases();

int main()
{
	testCases();
	return 0;
}
void testCases()
{
	std::cout << "COP3530 - Homework 4 Task 1 by Gregory Hudson" << std::endl;
	int array[50]; // holds max list size I need for testing
	int array1[] = { 11, 22, 33, 44 }; // pattern used for testing
	int tempInt;
	int temp8;
	int testCount = 1;  // used to track test numbers
	bool temp;

	LinkedList<int> empty1; // empty list
	LinkedList<int> a;  // list a used for testing

	// Test Case 1 - test insert()
	tempInt = a.insert(11, 0); // insert at first position
	if (tempInt == LinkedList<int>::NO_ERROR)
		std::cout << "Test Case " << testCount << " Passed" << std::endl;
	else
		std::cout << "Test Case " << testCount << " Failed" << std::endl;
	testCount++;

	// Test Case 2 - test that the one element is correct
	tempInt = a.getListElement(0, 1 - 1, array);
	if (compareArray(array, array1, 1) == true && tempInt == LinkedList<int>::NO_ERROR)
		std::cout << "Test Case " << testCount << " Passed" << std::endl;
	else
		std::cout << "Test Case " << testCount << " Failed" << std::endl;
	testCount++;

	// Test Case 3 - add 2 elements to the beginning position
	LinkedList<int> b;  // list a used for testing
	b.insert(22, 0); // insert at first position
	b.insert(11, 0); // insert at first position
	tempInt = b.getListElement(0, 2 - 1, array);
	if (compareArray(array, array1, 2) == true && tempInt == LinkedList<int>::NO_ERROR)
		std::cout << "Test Case " << testCount << " Passed" << std::endl;
	else
		std::cout << "Test Case " << testCount << " Failed" << std::endl;
	testCount++;

	// Test Case 4 - test that the 3 elements are correct
	LinkedList<int> c;  // list a used for testing
	c.insert(22, 0); // insert at first position
	c.insert(11, 0); // insert at first position
	c.insert(33, 2); // insert at last position
	c.getListElement(0, 3 - 1, array);
	if (compareArray(array, array1, 3) == true)
		std::cout << "Test Case " << testCount << " Passed" << std::endl;
	else
		std::cout << "Test Case " << testCount << " Failed" << std::endl;
	testCount++;

	// Test Case 5 - insert elements to the front end and middle
	LinkedList<int> d;  // list a used for testing
	d.insert(22, 0); // insert at first position
	d.insert(11, 0); // insert at first position
	d.insert(44, 2); // insert at last position
	d.insert(33, 2); // insert at middle position
	d.getListElement(0, 4 - 1, array);
	if (compareArray(array, array1, 4) == true)
		std::cout << "Test Case " << testCount << " Passed" << std::endl;
	else
		std::cout << "Test Case " << testCount << " Failed" << std::endl;
	testCount++;

	// Test Case 6 - test an illegal insertion
	LinkedList<int> e;  // list a used for testing
	e.insert(22, 0); // insert at first position
	e.insert(11, 0); // insert at first position
	e.insert(44, 2); // insert at last position
	e.insert(33, 2); // insert at middle position
	tempInt = e.insert(99, -1); // insert in an illegal position
	e.getListElement(0, 4 - 1, array);
	if (compareArray(array, array1, 4) == true && tempInt == LinkedList<int>::ILLEGAL_LIST_POSITION)
		std::cout << "Test Case " << testCount << " Passed" << std::endl;
	else
		std::cout << "Test Case " << testCount << " Failed" << std::endl;
	testCount++;

	// Test Case 7 - test an illegal insertion
	tempInt = e.insert(99, 5); // insert in an illegal position
	e.getListElement(0, 4 - 1, array);
	if (compareArray(array, array1, 4) == true && tempInt == LinkedList<int>::ILLEGAL_LIST_POSITION)
		std::cout << "Test Case " << testCount << " Passed" << std::endl;
	else
		std::cout << "Test Case " << testCount << " Failed" << std::endl;
	testCount++;

	// Test Case 8 - test an illegal erase
	tempInt = e.erase(-1); // erase from an illegal position
	e.getListElement(0, 4 - 1, array);
	if (compareArray(array, array1, 4) == true && tempInt == LinkedList<int>::ILLEGAL_LIST_POSITION)
		std::cout << "Test Case " << testCount << " Passed" << std::endl;
	else
		std::cout << "Test Case " << testCount << " Failed" << std::endl;
	testCount++;

	// Test Case 9 - test an illegal erase
	tempInt = e.erase(4); // erase from an illegal position
	e.getListElement(0, 4 - 1, array);
	if (compareArray(array, array1, 4) == true && tempInt == LinkedList<int>::ILLEGAL_LIST_POSITION)
		std::cout << "Test Case " << testCount << " Passed" << std::endl;
	else
		std::cout << "Test Case " << testCount << " Failed" << std::endl;
	testCount++;

	// Test Case 10 - test erase from an empty list
	tempInt = empty1.erase(0); // erase from an empty list
	if (tempInt == LinkedList<int>::ILLEGAL_LIST_POSITION)
		std::cout << "Test Case " << testCount << " Passed" << std::endl;
	else
		std::cout << "Test Case " << testCount << " Failed" << std::endl;
	testCount++;

	// Test Case 11 - test erase from the end of the list
	tempInt = e.erase(3); // erase from back of list
	e.getListElement(0, 3 - 1, array);
	if (compareArray(array, array1, 3) == true && tempInt == LinkedList<int>::NO_ERROR)
		std::cout << "Test Case " << testCount << " Passed" << std::endl;
	else
		std::cout << "Test Case " << testCount << " Failed" << std::endl;
	testCount++;

	// Test Case 12 - test erase from the middle of the list
	tempInt = e.erase(1); // erase from middle of list
	array1[1] = 33;
	e.getListElement(0, 2 - 1, array);
	if (compareArray(array, array1, 2) == true && tempInt == LinkedList<int>::NO_ERROR)
		std::cout << "Test Case " << testCount << " Passed" << std::endl;
	else
		std::cout << "Test Case " << testCount << " Failed" << std::endl;
	testCount++;

	// Test Case 13 - test erase from the front of the list
	tempInt = e.erase(0); // erase from front of list
	array1[0] = 33;
	e.getListElement(0, 1 - 1, array);
	if (compareArray(array, array1, 1) == true && tempInt == LinkedList<int>::NO_ERROR)
		std::cout << "Test Case " << testCount << " Passed" << std::endl;
	else
		std::cout << "Test Case " << testCount << " Failed" << std::endl;
	testCount++;

	// Test Case 14 - test erasing the last element so the list is empty
	tempInt = e.erase(0); // erase the last element
	if (tempInt == LinkedList<int>::NO_ERROR)
		std::cout << "Test Case " << testCount << " Passed" << std::endl;
	else
		std::cout << "Test Case " << testCount << " Failed" << std::endl;
	testCount++;

	// Test Case 15 - copy constructor - test if the lists are equal
	LinkedList<int> f;  // list a used for testing
	f.insert(33, 0); // insert at first position
	f.insert(11, 0); // insert at first position
	f.insert(44, 2); // insert at last position
	f.insert(22, 1); // insert at middle position
	LinkedList<int> g(f); // use copy constructor
	int array2[] = { 11, 22, 33, 44 };
	g.getListElement(0, 4 - 1, array);
	temp = compareArray(array, array2, 4);
	if (temp == true)
		std::cout << "Test Case " << testCount << " Passed" << std::endl;
	else
		std::cout << "Test Case " << testCount << " Failed" << std::endl;
	testCount++;

	// Test Case 16 - copy constructor - test shallow copy
	g.insert(99,1);
	f.getListElement(1, 1, array);
	temp8 = array[0];
	if (temp8 == 22)
		std::cout << "Test Case " << testCount << " Passed" << std::endl;
	else
		std::cout << "Test Case " << testCount << " Failed" << std::endl;
	testCount++;

	// Test Case 17 - assignment operator - test that the lists are equal
	LinkedList<int> h;  // list a used for testing
	h = f; // use assignment operator
	tempInt = h.getListElement(0, 4 - 1, array);
	temp = compareArray(array, array2, 4);
	if ((temp == true) && (tempInt == LinkedList<int>::NO_ERROR))
		std::cout << "Test Case " << testCount << " Passed" << std::endl;
	else
		std::cout << "Test Case " << testCount << " Failed" << std::endl;
	testCount++;

	// Test Case 18 - assignment operator - shallow copy test
	h.insert(99, 1);
	tempInt = f.getListElement(1, 1, array);
	temp8 = array[0];
	if ((temp8 == 22) && (tempInt == LinkedList<int>::NO_ERROR))
		std::cout << "Test Case " << testCount << " Passed" << std::endl;
	else
		std::cout << "Test Case " << testCount << " Failed" << std::endl;
	testCount++;

	// Test Case 19 - assignment operator - self assignment
	f = f; // use assignment operator
	tempInt = f.getListElement(0, 4 - 1, array);
	temp = compareArray(array, array2, 4);
	if ((temp == true) && (tempInt == LinkedList<int>::NO_ERROR))
		std::cout << "Test Case " << testCount << " Passed" << std::endl;
	else
		std::cout << "Test Case " << testCount << " Failed" << std::endl;
	testCount++;

	// Test Case 20 - test getListElement() for illegal positions
	tempInt = empty1.getListElement(-1, 1, array);
	if (tempInt == LinkedList<int>::ILLEGAL_LIST_POSITION)
		std::cout << "Test Case " << testCount << " Passed" << std::endl;
	else
		std::cout << "Test Case " << testCount << " Failed" << std::endl;
	testCount++;

	// Test Case 21 - test getListElement() for illegal positions
	tempInt = empty1.getListElement(1, 0, array);
	if (tempInt == LinkedList<int>::ILLEGAL_LIST_POSITION)
		std::cout << "Test Case " << testCount << " Passed" << std::endl;
	else
		std::cout << "Test Case " << testCount << " Failed" << std::endl;
	testCount++;

	// Test Case 22 - test getListElement() for illegal positions
	LinkedList<int> m;  // list a used for testing
	m.insert(44, 0);
	m.insert(11, 1);
	m.insert(22, 2);
	m.insert(33, 3);
	m.insert(33, 4);
	tempInt = m.getListElement(1, 5, array); // m has 5 elements now
	if (tempInt == LinkedList<int>::ILLEGAL_LIST_POSITION)
		std::cout << "Test Case " << testCount << " Passed" << std::endl;
	else
		std::cout << "Test Case " << testCount << " Failed" << std::endl;
	testCount++;
}

bool compareArray(int array1[], int array2[], int count)
{
	bool rv = true;
	for (int i = 0; i < count; i++)
	{
		if (array1[i] != array2[i])
			rv = false;
	}
	return rv;
}
