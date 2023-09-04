#ifndef DOWNWARDLIST_HPP
#define DOWNWARDLIST_HPP

#include "Node.hpp"
/** 
* @file DownwardList.hpp
* @description: burasi da fonksyorin govdesi mevcut.
* @course 1.A grubu
* @assignment 1.Odev
* @date 19/7/2023   last update 27/11/2022
* @author Ehsanullah Shahriary
*/

class DownwardList {
private:
    Node* head;

public:
    DownwardList();
    ~DownwardList();

    void add(int value);
    void printList() const;
    void swapIndexes(int indexA, int indexB);
	
	// Calculating the average of elements in the list
	double calculateAverage() const; 
	// Getting the head of the upward list
    Node* getHead() const;
};

#endif // DOWNWARDLIST_HPP
