// Module:	ListClass.cpp
// Author:	Miguel Antonio Logarta
// Date:	March 8, 2020
// Purpose:	Implementation file for ListClass

#include "CIS023_S2020_HW12.h"

int ListClass::Count(string A[], int iSize)
{
	// Count the number of elements in the array

	int iCount{ 0 };								// The count starts at 0

	for (int i{ 0 }; i < iSize; i++)				// Loop through array of strings
	{
		if (A[i].length() > 0)						// If there is something in the array
		{
			iCount++;								// Increment count
		}
	}

	return iCount;									// Return the total number
}

int ListClass::Largest(string A[], int iSize, string& strLargest)
{
	int iPos{ -1 };									// Location of the largest string
	//strLargest = "";								// Set string to blank at start

	for (int i{ 0 }; i < iSize; i++)				// Loop through array of strings
	{
		if (A[i].length() >= strLargest.length())	// >= just in case of a string with the same length
		{
			strLargest = A[i];						// Change strLargest to that value
			iPos = i;
		}
	}

	return iPos;									// Return position of largest string in array
}

int ListClass::Shortest(string A[], int iSize, string& strShortest)
{
	int iPos{ -1 };											// Location of the shortest string
	//strShortest = A[0];										// Set string to the first string in array
															// If it was "" then output would still be "" since it is the shortest
		
	for (int i{ 0 }; i < iSize; i++)						// Loop through array of strings
	{
		if ((A[i].length()) > 0 &&							// Check if not empty
			(A[i].length() <= strShortest.length()))		// <= just in case of a string with the same length
		{
			strShortest = A[i];								// Change strShortest to that value
			iPos = i;
		}
	}

	return iPos;											// Return position of shortest string in array
}
