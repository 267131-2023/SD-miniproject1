#pragma once
#include "TwoWayNode.h"

class TwoWayLinkedList {
private:
    TwoWayNode* head;
    TwoWayNode* tail;
    int size;
public:
    TwoWayLinkedList();
    ~TwoWayLinkedList();
    void addNodeAtBeginning(int i_value);
    void addNodeAtEnd(int i_value);
    void addNodeAtRandomPosition(int i_value, int node_index);
    void removeNodeAtBeginning();
    void removeNodeAtRandomPosition(int node_index);
    void removeNodeAtEnd();
    void findNode(int node_index);
    void displayList();

};