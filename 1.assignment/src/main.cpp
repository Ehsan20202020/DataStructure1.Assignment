#include "linkedList.hpp"
#include "UpwardList.hpp"
#include "DownwardList.hpp"
#include <iostream>
#include <string>
/** 
* @file main.cpp
* @description: burasi da fonksyorin govdesi bulunmakta.
* @course 1.A grubu
* @assignment 1.Odev
* @date 19/7/2023   last update 27/11/2022
* @author Ehsanullah Shahriary
*/

using namespace std;
int main() {
    LinkedList lists;

    // Replace "veriler.txt" with the name of the file you want to read from
    lists.readFile("veriler.txt");

    cout << "Original lists:" << std::endl;
    lists.printLists();

    int positionA, positionB;
    cout << "Enter Position A: ";
    cin >> positionA;

    cout << "Enter Position B: ";
    cin >> positionB;

    lists.swapLists(positionA, positionB);

    cout << "\nAfter swapping lists:" << endl;
    lists.printLists();

    // Calculate the average of every upward list for each row separately
    double totalUpwardAverage = 0.0;
    for (int i = 0; i < lists.getNumRows(); i++) {
        double upwardAverage = lists.getAverageOfUpwardList(i);
        cout << "Row " << i << " Upward List Average: " << upwardAverage << endl;
        totalUpwardAverage += upwardAverage;
    }

    // Calculate the average of every downward list for each row separately
    double totalDownwardAverage = 0.0;
    for (int i = 0; i < lists.getNumRows(); i++) {
        double downwardAverage = lists.getAverageOfDownwardList(i);
        cout << "Row " << i << " Downward List Average: " << downwardAverage << endl;
        totalDownwardAverage += downwardAverage;
    }

    // Calculate the sum of the average of all upward lists in all rows using the function
    double sumOfAllUpwardAverages = lists.getAverageOfAllUpwardLists();
    cout << "\n Sum of Average of All Upward Lists: " << sumOfAllUpwardAverages << endl;
	
	// Calculate the sum of the average of all downward lists in all rows using the existing function
    double sumOfAllDownwardAverages = lists.getAverageOfAllDownwardLists();
    cout << "\n Sum of Average of All Downward Lists: " << sumOfAllDownwardAverages << endl;

    return 0;
}



