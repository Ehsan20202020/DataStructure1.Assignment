#include "linkedList.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

/** 
* @file linkedList.cpp
* @description: burasi da fonksyorin govdesi mevcut.
* @course 1.A grubu
* @assignment 1.Odev
* @date 19/7/2023   last update 27/11/2022
* @author Ehsanullah Shahriary
*/

LinkedList::LinkedList() : headUp(nullptr), headDown(nullptr), numRows(0) {}

LinkedList::~LinkedList() {
    deleteLists();
}

void LinkedList::deleteLists() {
    if (headUp) {
        for (int i = 0; i < numRows; i++) {
            delete headUp[i];
        }
        delete[] headUp;
    }

    if (headDown) {
        for (int i = 0; i < numRows; i++) {
            delete headDown[i];
        }
        delete[] headDown;
    }
}

void LinkedList::readFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    // Delete any existing lists before reading a new file...
    deleteLists();

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        int num;
		// Create a new upward list for each row...
        UpwardList* currentUpList = new UpwardList(); 
		// Creating a new downward list for each row
        DownwardList* currentDownList = new DownwardList(); 
		
        while (ss >> num) {
			// Add tens digit to the upward list...
            currentUpList->add(num / 10); 
			// Add ones digit to the downward list...
            currentDownList->add(num % 10); 
        }
        // Add the each row's lists to the array...
        if (!headUp) {
            headUp = new UpwardList*[1]();
            headDown = new DownwardList*[1]();
        } else if (numRows >= 1) {
            UpwardList** newHeadUp = new UpwardList*[numRows + 1]();
            DownwardList** newHeadDown = new DownwardList*[numRows + 1]();
            for (int i = 0; i < numRows; i++) {
                newHeadUp[i] = headUp[i];
                newHeadDown[i] = headDown[i];
            }
            delete[] headUp;
            delete[] headDown;
            headUp = newHeadUp;
            headDown = newHeadDown;
        }
        headUp[numRows] = currentUpList;
        headDown[numRows] = currentDownList;
        numRows++; // Increse the row count...
    }

    file.close();
}

void LinkedList::printLists() const {
    for (int i = 0; i < numRows; i++) {
        cout << "Row " << i << " Upward list: ";
        headUp[i]->printList();
        cout << "Row " << i << " Downward list: ";
        headDown[i]->printList();
        cout << endl;
    }
}

void LinkedList::swapLists(int positionA, int positionB) {
    if (positionA >= numRows || positionB >= numRows) {
        cerr << "Error: Invalid positions. Please enter valid positions within the row count." << std::endl;
        return;
    }

    // Swap the upward list at positionA and positionB
    UpwardList* tempUp = headUp[positionA];
    headUp[positionA] = reinterpret_cast<UpwardList*>(headDown[positionB]); 
    headDown[positionB] = reinterpret_cast<DownwardList*>(tempUp); 
}


int LinkedList::getNumRows() const {
    return numRows;
}

double LinkedList::getAverageOfUpwardList(int row) const {
    if (row < 0 || row >= numRows) {
        cerr << "Error: Invalid row index." << endl;
        return 0.0;
    }

    UpwardList* currentUpList = headUp[row];
    if (!currentUpList) {
        return 0.0; // Empty list...
    }
	
	// Access head using the getter method...
    Node* currentNode = currentUpList->getHead(); 
	
    int sum = 0;
    int count = 0;
    while (currentNode) {
        sum += currentNode->data;
        count++;
        currentNode = currentNode->next;
    }

    if (count > 0) {
        return static_cast<double>(sum) / count;
    } else {
        return 0.0; // Empty list...
    }
}

double LinkedList::getAverageOfAllUpwardLists() const {
    int totalRows = getNumRows();
    if (totalRows == 0) {
        return 0.0; // Empty list...
    }

    double sum = 0.0;
    int count = 0;

    for (int i = 0; i < totalRows; i++) {
		// Calculatint the average of the current upward list...
        double rowAverage = headUp[i]->calculateAverage(); 
        sum += rowAverage;
        count++;
    }

    if (count > 0) {
        return sum;
    } else {
        return 0.0; // Empty list...
    }
}


double LinkedList::getAverageOfDownwardList(int row) const {
    if (row < 0 || row >= numRows) {
        cerr << "Error: Invalid row index." << endl;
        return 0.0;
    }

    UpwardList* currentUpList = headUp[row];
    if (!currentUpList) {
        return 0.0; // Empty list...
    }
	
	// Access head using the getter method...
    Node* currentNode = currentUpList->getHead(); 
	
    int sum = 0;
    int count = 0;
    while (currentNode) {
        sum += currentNode->data;
        count++;
        currentNode = currentNode->next;
    }

    if (count > 0) {
        return static_cast<double>(sum) / count;
    } else {
        return 0.0; // Empty list...
    }
}

double LinkedList::getAverageOfAllDownwardLists() const {
    int totalRows = getNumRows();
    if (totalRows == 0) {
        return 0.0; // Empty list...
    }

    double sum = 0.0;
    int count = 0;

    for (int i = 0; i < totalRows; i++) {
		// Calculate the average of the current downward list...
        double rowAverage = headDown[i]->calculateAverage(); 
        sum += rowAverage;
        count++;
    }

    if (count > 0) {
        return sum;
    } else {
        return 0.0; // Empty list...
    }
}