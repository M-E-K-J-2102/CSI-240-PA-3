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
consequences of plagiarism and		 acknowledge that the assessor of this assignment
may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic staff;
and/or
- Communicate a copy of this assignment to a plagiarism checking service (which may
then retain a copy of this assignment on its database for the purpose of future
plagiarism checking)
-----------------------------------------------------------------------------------------
Sources:
*/

#ifndef _DATAPOINT_H
#define _DATAPOINT_H

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

const int ATT = 22;

struct DataPoint
{
	int mAtt[ATT];
	char mClass;
	float mDist;
	static int k;

	DataPoint();
	DataPoint(int arr[], float distance);

	bool operator==(const DataPoint& rhs);
	bool operator<(const DataPoint& rhs);
	bool operator>(const DataPoint& rhs);
	DataPoint& operator=(const DataPoint& rhs);
	friend ostream& operator<<(ostream& lhs, const DataPoint& rhs);
	friend istream& operator>>(istream& lhs, DataPoint& rhs);
};
#endif