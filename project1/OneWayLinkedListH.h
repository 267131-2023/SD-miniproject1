#pragma once
#include "OneWayNode.h"

class OneWayLinkedListH {
private:
    OneWayNode* head;
    int size;

public:
    OneWayLinkedListH();
    ~OneWayLinkedListH();
    void addNodeAtBeginning(int i_value);
    void addNodeAtEnd(int i_value);
    void addNodeAtRandomPosition(int i_value, int node_index);
    void removeNodeAtBeginning();
    void removeNodeAtEnd();
    void removeNodeAtRandomPosition(int node_index);
    void findNode(int node_index);
    void displayList();
};

