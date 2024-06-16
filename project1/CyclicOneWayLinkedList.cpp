#include <iostream>
#include "CyclicOneWayLinkedList.h"

using namespace std;

CyclicOneWayLinkedList::CyclicOneWayLinkedList() : head(nullptr), size(0) {}

CyclicOneWayLinkedList::~CyclicOneWayLinkedList() {
    if (head != nullptr) {
        OneWayNode* current = head->getNextNode();
        OneWayNode* next = nullptr;

        // Usuwamy wszystkie węzły poza głową
        while (current != head) {
            next = current->getNextNode();
            delete current;
            current = next;
        }

        // Usuwamy głowę
        delete head;
        head = nullptr;
    }
}
