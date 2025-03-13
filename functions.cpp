/*
Author:           Matthew Kane
Class:            CSI-240-04
Assignment:       PA 3
Date Assigned:    22/3/2024
Due Date:         92/3/2024 @ 1:00 PM

Description:
A program that uses the knn algorithm with a mushroom attribute database

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given
fully-documented references to the work of others. I understand the definition and
consequences of plagiarism and acknowledge that the assessor of this assignment
may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic staff;
and/or
- Communicate a copy of this assignment to a plagiarism checking service (which may
then retain a copy of this assignment on its database for the purpose of future
plagiarism checking)
-----------------------------------------------------------------------------------------
Sources:
*/

#include "header.h"

/* Function:   isValid
*   Purpose:   Checks user input to see if it is valid or not
*       Pre:   user input must not be empty
*      Post:   returns true or false depending if the input is a char or not
****************************************************************/
bool isValid(char in)
{
	if (!isalpha(in) || cin.peek() != '\n')
	{
		cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return false;
	}

	return true;
}

/* Function:   isValid
*   Purpose:   Checks user input to see if it is valid or not
*       Pre:   user input must not be empty
*      Post:   returns true or false depending if the input is a number or not
****************************************************************/
bool isValid(float in)
{
	if (cin.fail() || isalpha(cin.peek()))
	{
		cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return false;
	}
	return true;
}

/* Function:   isValid
*   Purpose:   Checks user input to see if it is valid or not
*       Pre:   user input must not be empty
*      Post:   returns true or false depending if the input is a number or not
****************************************************************/
bool isValid(int in)
{
	if (cin.fail() || isalpha(cin.peek()))
	{
		cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return false;
	}
	return true;
}

/* Function:   newMushroom
*   Purpose:   prompts the user for info and creates a new DataPoint object
*       Pre:   none
*      Post:   creates a DataPoint object using the attributes the user provided
****************************************************************/
DataPoint newMushroom()
{
	char classification;
	float dist;
	int attribute;
	int arr[ATT];
	// Prompts user to enter each attribute of the mushroom
	cout << "please enter the values for your mushroom below:\n";
	for (int i = 0; i < ATT; i++)
	{
		// Keep letting user enter an answer untill they enter valid answer
		cout << "Attribute " << i + 1 << ": ";
		do {
			cin >> attribute;
		} while (!isValid(attribute));

		arr[i] = attribute;
	}

	// Prompts user for Distance (can be ignored by entering 0)
	// Keep letting user enter an answer untill they enter valid answer
	cout << "Distance (0 for unknown):";
	do {
		cin >> dist;
	} while (!isValid(dist));

	DataPoint mushroom(arr, dist);

	return mushroom;
}

