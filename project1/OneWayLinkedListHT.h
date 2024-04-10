#pragma once
#include "OneWayNode.h"

class OneWayLinkedListHT {
private:
    OneWayNode* head;
    OneWayNode* tail;
    int size;
public:
    OneWayLinkedListHT();
    ~OneWayLinkedListHT();
    void addNodeAtBeginning(int i_value);
    void addNodeAtEnd(int i_value);
    void addNodeAtRandomPosition(int i_value, int node_index);
    void removeNodeAtBeginning();
    void removeNodeAtRandomPosition(int node_index);
    void removeNodeAtEnd();
    void findNode(int node_index);
    void displayList();

};

