#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "UpwardList.hpp"
#include "DownwardList.hpp"
#include <string> 

/** 
* @file DownwardList.hpp
* @description: burasi da fonksyorin adlari mevcut.
* @course 1.A grubu
* @assignment 1.Odev
* @date 19/7/2023   last update 27/11/2022
* @author Ehsanullah Shahriary
*/

class LinkedList {
private:
    UpwardList** headUp;
    DownwardList** headDown;
    int numRows;

    void deleteLists();

public:
    LinkedList();
    ~LinkedList();
	
	// reade the file...
    void readFile(const std::string& filename);
	// print the list element..
    void printLists() const;
	// replace the rows by index...
    void swapLists(int positionA, int positionB);
	
	// Get average of upward list...
	double getAverageOfUpwardList(int row) const;
	// Sum all average...
	double getAverageOfAllUpwardLists() const;
	
	// Get average of downward list...
    double getAverageOfDownwardList(int row) const;
	// Sum all average...
    double getAverageOfAllDownwardLists() const;
	// Getter for numRows
    int getNumRows() const;
};

#endif // LINKEDLIST_HPP


 
 
