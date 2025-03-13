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
-https://www.geeksforgeeks.org/string-find-in-cpp/
*/

/*TODO
	-figure out why preditctions.txt has so many entries
	-get prediction function to properly update the class attribute of newShroom
*/

/*Exit codes:
	1: file error/not found
	2: Linked list empty/NULL */

#include "header.h"

int main()
{
	char choice;
	int kVal = -1;
	Dataset mushroom;
	DataPoint newShroom;

	// Loads file data into linked list
	mushroom.load();

	// Keep letting user enter an answer untill they enter valid answer
	do {
		cout << "Enter new mushroom (y/n)?";
		do {
			cin >> choice;
		} while ((toupper(choice) != 'Y' && toupper(choice) != 'N'));

		if (toupper(choice) == 'Y')
		{
			// Creates new mushroom object with all of user's data.
			mushroom.insertAtFront(newMushroom());
			cout << mushroom.getData(0) << endl;
			choice = '\0';
		}
		else
		{
			break;
		}
	} while (toupper(choice) != 'Y');

	// Prompts user for K value
	cout << "K value: ";
	do {
		cin >> kVal;
	} while (!isValid(kVal) || kVal % 2 == 0); // Also ensures value is not even to make computations easier

	// Compares distance of the new object with all the other instances (user created file)

	cout << "The new Mushroom is most likely " << mushroom.predict(kVal, newShroom) << endl;
	mushroom.userStore(kVal);
	//mushroom.store();
	return 0;
}