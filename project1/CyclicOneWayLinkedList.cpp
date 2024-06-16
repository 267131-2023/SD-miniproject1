#include <iostream>
#include "OneWayLinkedListH.h"

using namespace std;

OneWayLinkedListH::OneWayLinkedListH() : head(nullptr), size(0) {}

OneWayLinkedListH::~OneWayLinkedListH() {
    if (head != nullptr) {
        OneWayNode* current = head;
        do {
            OneWayNode* next = current->getNextNode();
            delete current;
            current = next;
        } while (current != head);
    }
}
