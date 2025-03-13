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

#include "Dataset.h"

	// Math goes here
// --------- Node members -----------

// Constructor
Dataset::Node::Node()
{
    for (int i = 0; i < ATT; i++)
    {
        mData.mAtt[i] = 0;
    }

    mData.mClass = '\0';
    mData.mDist = -1;
    mNext = nullptr;
}

// Copy constructor
Dataset::Node::Node(DataPoint data)
{
    for (int i = 0; i < ATT; i++)
    {
        mData.mAtt[i] = data.mAtt[i];
    }

    mData.mClass = data.mClass;
    mData.mDist = data.mDist;
    mNext = NULL;
}
 
//  ------ Constructors/Destructors ------

// Constructor
Dataset::Dataset()
{
    mHead = NULL;
    mTail = NULL;
    mCount = 0;
}

// Destructor
Dataset::~Dataset()
{
    Node* tmp;

    while (mHead != NULL)
    {
        tmp = mHead;
        mHead = mHead->mNext;

        tmp->mNext = NULL;
        delete tmp;
    }
    mCount = 0;
    mHead = NULL;
    mTail = NULL;
}

// ------ Getters ------

/* Function:   getCount
*  Purpose:    returns the count of how many nodes there are
*  Pre:        Linked list must be iniciated and populated
*  Post:       The ammount of nodes is returned
****************************************************************/
int Dataset::getCount()
{
    return mCount;
}

/* Function:   getData
*  Purpose:    returns a node's data
*  Pre:        Linked list must be iniciated and populated
*  Post:       data is returned
****************************************************************/
DataPoint Dataset::getData(int index)
{   
    Node* tmp = mHead;

    // Checks if index is valid
    if (index < 0 || index >= mCount)
    {
        cout << "Index out of range.\n";
        exit(2);
    }

    // Iterates through linked list
    for (int i = 0; i < index; i++)
    {
        tmp = tmp->mNext;
    }

    // If class is unknown, places a U instead while the program tries to figure it out
    if (toupper(tmp->mData.mClass) != 'P' || toupper(tmp->mData.mClass) != 'E')
    {
        tmp->mData.mClass = 'U';
    }
    return tmp->mData;
}

// ------- Setters ------

/* Function:   setData
*  Purpose:    changes the data within a node
*  Pre:        Node data must already exist
*  Post:       Node has new data
****************************************************************/
void Dataset::setData(int index, DataPoint data)
{
    Node* tmp = mHead;

    if (index == 0)
    {
        if (mHead == NULL)
        {
            cout << "Linked list is empty\n";
            return;
        }

        mHead->mData = data;
        return;
    }
    // Iterates through liked list
    for (int i = 0; i < index; i++)
    {
        if (tmp == NULL)
        {
            // Makes sure It is bounded
            cout << "Index not found\n";

            // Returns nothing and does not change anything if out of bounds
            return;
        }

        // Checks node
        tmp = tmp->mNext;
    }

    // When node is found, assigns it the value of data
    tmp->mData = data;

    return;
}

// ------- Functions -------

/* Function:   calcDist
*  Purpose:    Calculates the distance between 2 points
*  Pre:        parameters must be initialized
*  Post:       Returns the distance
****************************************************************/
float Dataset::calcDist(DataPoint obj1, DataPoint obj2)
{
    float total = 0;
    for (int i = 0; i < ATT; i++)
    {
        total += pow(obj1.mAtt[i] - obj2.mAtt[i], 2);
    }
    total = sqrt(total);

    return total;
}

/* Function:   compDist
*  Purpose:    computes the distance of all points against an unknown point
*  Pre:        Linked list and DataPoints must be initialized
*  Post:       gives node a distance
****************************************************************/
void Dataset::compDist(DataPoint uk)
{
    Node* tmp;
    tmp = mHead;

    while (tmp != NULL)
    {
        tmp->mData.mDist = calcDist(tmp->mData, uk);
        tmp = tmp->mNext;
    }

    return;
}


/* Function:   insertAtBack
*  Purpose:    adds a node at the back of the list
*  Pre:        Linked list must be iniciated and populated
*  Post:       node is added at back
****************************************************************/
void Dataset::insertAtBack(DataPoint data)
{
    Node* newNode;

    newNode = new Node(data);
    if (newNode == NULL)
    {
        cout << "Returning... newNode is NULL!\n";
        return;
    }

    // check if the list is empty
    if (mCount == 0)  
    {
        mHead = newNode;
        mTail = newNode;
    }
    else
    {
        mTail->mNext = newNode;
        mTail = newNode;
    }

    mCount++;
}

/* Function:   insertAtFront
*  Purpose:    adds a node in the front
*  Pre:        Linked list must be iniciated and populated
*  Post:       node is added at the front
****************************************************************/
void Dataset::insertAtFront(DataPoint data)
{
    Node* newNode;

    newNode = new Node(data);
    if (newNode == NULL)
    {
        cout << "Returning... newNode is NULL!\n";
        return;
    }

    // check if the list is empty
    if (mCount == 0)
    {
        mHead = newNode;
        mTail = newNode;
    }
    else
    {
        newNode->mNext = mHead;
        mHead = newNode;
    }

    mCount++;

    return;
}

/* Function:   isExist
*  Purpose:    Checks to see if a node's value exists
*  Pre:        Linked list must be iniciated and populated
*  Post:       Bool is returned determining weather that vaule exists or not
****************************************************************/               
bool Dataset::isExist(DataPoint searchKey)
{
    Node* tmp;
    tmp = mHead;

    while (tmp != NULL)
    {
        if (tmp->mData == searchKey)
        {   // If searcKey coincides with mData it returns true
            return true;
        }
        // Next iteration
        tmp = tmp->mNext;
    }
    // If no mData matches searchKey the function returns false
    return false;
}

/* Function:   load
*  Purpose:    loads the datapoints from the file into the linked list
*  Pre:        file must have data
*  Post:       data is now in linked list
****************************************************************/
void Dataset::load()
{
    fstream data;
    DataPoint info;

    data.open("data.txt", ios::in);

    // Checks file opens correctly
    if (data.fail())
    {
        cout << "Failed to open 'data.txt'\n";
        exit(1);
    }

    while (!data.eof())
    {
        for (int i = 0; i < ATT; i++)
        {
            data >> info.mAtt[i];
        }
        data >> info.mClass;

        // If linked list is empty add new node
        if (mHead == NULL)
        {
            mHead = new Node(info);
            mTail = mHead;
        }
        else
        {
            insertAtFront(info);
        }

        mCount++;
    }

    data.close();

    return;
}

/* Function:   predict
*   Purpose:   computes a prediction based on the k value and a mushroom's attributes
*       Pre:   Mushrooms must be initialized and linked list populated
*      Post:   writes the predictions into tpredictions.txt
****************************************************************/
char Dataset::predict(int k, DataPoint newShroom)
{
    // get all elements up to K and whichever has more (p or e) will determine what the new mushroom is
    fstream file;
    Node* tmp;
    tmp = mHead;
    float pCount = 0, eCount = 0, dist;

    for (int i = 0; i < k; i++)
    {
        // Checks node is not empty
        if (tmp == NULL)
        {
            break;
        }

        // Calculates the distance between newShroom and all the others
        tmp->mData.mDist = calcDist(newShroom, tmp->mData);

        if (tmp->mData.mClass == 'P' || tmp->mData.mClass == 'p')
        {
            pCount+= tmp->mData.mDist;
        }
        else if (tmp->mData.mClass == 'E' || tmp->mData.mClass == 'e')
        {
            eCount += tmp->mData.mDist;

        }

        // Next iteration
        tmp = tmp->mNext;
    }

    if (eCount > pCount)
    {
        newShroom.mClass = 'e';
    }
    else
    {
        newShroom.mClass = 'p';

    }
    file.open("predictions.txt", ios::app);

    if (file.fail())
    {
        cout << "Error opening 'predictions.txt'" << endl;
        exit(1);
    }

    file << newShroom.mClass;
    file.close();

    return newShroom.mClass;
}

/* Function:   remove
*  Purpose:    Removes a node via its contents
*  Pre:        Linked list must be iniciated and populated
*  Post:       node is removed
****************************************************************/               
DataPoint Dataset::remove(DataPoint searchKey) // search key is value
{
    // Checks list is not empty
    if (mHead == NULL)
    {
        cout << "Linked list is empty!\n";
        exit(2);
    }

    Node* tmp = mHead;
    Node* prev = NULL;
    DataPoint junk;

    // Iterates through liked list
    while (tmp != NULL)
    {
        if (prev == NULL && tmp->mData == searchKey)
        {
            // If searchKey is the first node, set first node to the next node and delete the original first node
            mHead = tmp->mNext;
            junk = tmp->mData;
            delete tmp;

            if (mHead == NULL)
            {
                mTail = NULL;
            }

            mCount--;

            return junk;
        }
        else if (tmp->mNext == NULL && tmp->mData == searchKey)
        {
            // If searchKey is at the end, set tail to prev and delete tmp and set the new last element's mNext to NULL
            mTail = prev;
            junk = tmp->mData;
            prev->mNext = NULL;
            delete tmp;
            mCount--;

            return junk;
        }
        else if ((prev != NULL && tmp->mData == searchKey) && (tmp->mNext != NULL))
        {
            // If searchKey is in the middle, set prev pointer to node after tmp and delete tmp
            prev->mNext = tmp->mNext;
            junk = tmp->mData;
            delete tmp;
            mCount--;

            return junk;
        }

        // Iterate to next node
        prev = tmp;
        tmp = tmp->mNext;
    }
    cout << "Index not found\n";
    return DataPoint();
}

/* Function:   store
*  Purpose:    stores the datapoints from the linked into the file
*  Pre:        linked list must have data
*  Post:       data is now in linked list
****************************************************************/
void Dataset::store()
{
    fstream userFile, predictionsFile;
    string fileName;

    Node* tmp = mHead;

    // Open predictions file
    predictionsFile.open("predictions.txt", ios::out);

    if (predictionsFile.fail()) 
    {
        cout << "Could not open 'predictions.txt'\n";
        exit(1);
    }

    // Iterate through linked list to store predictions
    while (tmp != NULL) 
    {
        predictionsFile << tmp->mData.mClass << endl;
        tmp = tmp->mNext;
    }

    predictionsFile.close();

    return;
}

void Dataset::userStore(int k)
{
    fstream userFile;
    string fileName;

    Node* tmp = mHead;

    // Prompts user for file name
    cout << "Please enter file name: ";
    cin >> fileName;

    userFile.open(fileName, ios::app);

    if (userFile.fail())
    {
        cout << "'" << fileName << "' could not be opened or does not exist.\n";
        exit(1);
    }
    else
    {
        cout << "'" << fileName << "' was opened successfully!\n";
    }

    // Store attributes and k value in user created file
    userFile << k << endl;

    // Iterate through linked list to store attributes
    for (int i = 0; i < k; i++)
    {
        for (int i = 0; i < ATT; i++)
        {
            userFile << tmp->mData.mAtt[i];
        }
        userFile << endl;
        tmp = tmp->mNext;
    }

    userFile.close();

    return;
}