// Module:	ListClass.h
// Author:	Miguel Antonio Logarta
// Date:	March 8, 2020
// Purpose:	Class of virtual functions
//			Counts names, finds largest and shortest strings

#pragma once
class ListClass
{
public:

	// Find total number of names in the array 
	static int Count(string A[], int);

	// Find largest name in the array (array, size of array, largest string found)
	// Returns the position of the string in the array where it was found
	static int Largest(string A[], int, string&);

	// Find shortest name in the array (array, size of array, shortest string found)
	// Returns the position of the string in the array where it was found
	static int Shortest(string A[], int, string&);
};

