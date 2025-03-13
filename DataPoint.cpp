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

#include "dataPoint.h"

/*Pre:     None
*Post:     The Object is initialized
*Purpose:  Constructor for dataPoint
******************************************************/
DataPoint::DataPoint()
{
	for (int i = 0; i < ATT; i++)
	{
		mAtt[i] = 0;
	}
	mClass = '\0';
	mDist = 0.0;
}

/*Pre:     None
*Post:     The Object is initialized with values
*Purpose:  Copy constructor for dataPoint
******************************************************/
DataPoint::DataPoint(int arr[], float distance)
{
	for (int i = 0; i < ATT; i++)
	{
		mAtt[i] = arr[i];
	}
	mDist = distance;
}

/*Pre:     Objects must be initialized
*Post:     returns true or false weather all of both objects attributes match
*Purpose:  compares 2 objects
******************************************************/
bool DataPoint::operator==(const DataPoint& rhs)
{
	for (int i = 0; i < ATT; i++)
	{
		// Makes sure all elements in mAtt are equal returns false if different
		if (mAtt[i] != rhs.mAtt[i])
		{
			return false;
		}
	}

	if ((mClass == rhs.mClass) && (mDist == rhs.mDist))
	{
		return true;
	}
	return false;
}

/*Pre:     Objects must be initialized
*Post:     rhs is the same as memberPoint
*Purpose:  Assigns rhs's info into dataPoint
******************************************************/
DataPoint& DataPoint::operator=(const DataPoint& rhs)
{
	for (int i = 0; i < ATT; i++)
	{
		mAtt[i] = rhs.mAtt[i];
	}

	mClass = rhs.mClass;
	mDist = rhs.mDist;

	return *this;
}

/*Pre:     Objects must be initialized
*Post:     returns true or false depending on what object has a greater distance
*Purpose:  Compares wether rhs's distance is greater than the struct
******************************************************/
bool DataPoint::operator<(const DataPoint& rhs)
{
	if (mDist < rhs.mDist)
	{
		return true;
	}

	return false;
}

/*Pre:     Objects must be initialized
*Post:     returns true or false depending on what object has a greater distance
*Purpose:  Compares wether rhs's distance is less than the struct
******************************************************/
bool DataPoint::operator>(const DataPoint& rhs)
{
	if (mDist > rhs.mDist)
	{
		return true;
	}

	return false;
}
/*Pre:     Objects must be initialized
*Post:     Object's attributes are printed
*Purpose:  Prints the object's attributes to the console
******************************************************/
 ostream& operator<<(ostream& lhs, const DataPoint& rhs)
{
	for (int i = 0; i < ATT; i++)
	{
		lhs << rhs.mAtt[i] << " ";
	}
	cout << endl;
	lhs << rhs.mClass << endl;
	lhs << rhs.mDist << endl;
	return lhs;
}

/*Pre:     Objects must be initialized
*Post:     Object's attributes are exctracted
*Purpose:  takes in the attributes and adds them to the desired object
******************************************************/
istream& operator>>(istream& lhs, DataPoint& rhs)
{
	for (int i = 0; i < ATT; i++)
	{
		lhs >> rhs.mAtt[i];
	}
	lhs >> rhs.mClass;
	lhs >> rhs.mDist;
	return lhs;
}