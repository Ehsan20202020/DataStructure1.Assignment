#ifndef UPWARDLIST_HPP
#define UPWARDLIST_HPP

#include "Node.hpp"

/** 
* @file Upward.cpp
* @description: burasi da fonksyorin adi mevcut.
* @course 1.A grubu
* @assignment 1.Odev
* @date 19/7/2023   last update 27/11/2022
* @author Ehsanullah Shahriary
*/

class UpwardList {
private:
    Node* head;

public:
    UpwardList();
    ~UpwardList();

    void add(int value);
    void printList() const;
    void swapIndexes(int indexA, int indexB);
	
	// Calculating the average of elements in the list
	double calculateAverage() const; 
	Node* getHead() const;
};

#endif // UPWARDLIST_HPP
