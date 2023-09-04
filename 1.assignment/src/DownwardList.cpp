#include "DownwardList.hpp"
#include "Node.hpp"
#include <iostream>

using namespace std;

/** 
* @file Downward.cpp
* @description: burasi da fonksyorin govdesi mevcut.
* @course 1.A grubu
* @assignment 1.Odev
* @date 19/7/2023   last update 27/11/2022
* @author Ehsanullah Shahriary
*/

DownwardList::DownwardList() : head(nullptr) {}

DownwardList::~DownwardList() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void DownwardList::add(int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void DownwardList::printList() const {
    cout << "Downward list: ";
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void DownwardList::swapIndexes(int indexA, int indexB) {
    if (indexA == indexB || !head) {
        return; // No need to swap
    }

    Node* prevA = nullptr;
    Node* nodeA = head;
    int idxA = 0;
    while (nodeA && idxA < indexA) {
        prevA = nodeA;
        nodeA = nodeA->next;
        idxA++;
    }

    Node* prevB = nullptr;
    Node* nodeB = head;
    int idxB = 0;
    while (nodeB && idxB < indexB) {
        prevB = nodeB;
        nodeB = nodeB->next;
        idxB++;
    }

    if (!nodeA || !nodeB) {
        return; // Invalid indexes
    }

    if (prevA) {
        prevA->next = nodeB;
    } else {
        head = nodeB;
    }

    if (prevB) {
        prevB->next = nodeA;
    } else {
        head = nodeA;
    }

    Node* temp = nodeB->next;
    nodeB->next = nodeA->next;
    nodeA->next = temp;
}

// Getter method to access the head of the upward list
Node* DownwardList::getHead() const {
    return head;
}
double DownwardList::calculateAverage() const {
    double sum = 0.0;
    int count = 0;
    Node* currentNode = head;
    while (currentNode) {
        sum += currentNode->data;
        count++;
        currentNode = currentNode->next;
    }
    if (count == 0) {
        return 0.0; // if division by zero
    }
    return sum / count;
}