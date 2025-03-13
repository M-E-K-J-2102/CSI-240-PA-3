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


#ifndef _DATASET_H
#define _DATASET_H

#include <cmath>
#include "dataPoint.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class Dataset
{
    struct Node
    {
        DataPoint mData;
        Node* mNext;

        Node();
        Node(DataPoint data);
    };

private:
    Node* mHead, * mTail;
    int  mCount;

public:
    // Constructor/Destructor
    Dataset();
    ~Dataset();

    // Getters
    int  getCount();
    DataPoint getData(int index);

    // Setters
    void setData(int index, DataPoint data);

    // Functions
    float calcDist(DataPoint, DataPoint);
    void compDist(DataPoint);
    void insertAtBack(DataPoint data);
    void insertAtFront(DataPoint data);
    bool isExist(DataPoint searchKey);
    void load();
    char predict(int, DataPoint);
    DataPoint remove(DataPoint searchKey);
    void store();
    void userStore(int);
};
#endif
