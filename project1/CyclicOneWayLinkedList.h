#ifndef CYCLICONEWAYLINKEDLIST_H
#define CYCLICONEWAYLINKEDLIST_H

#include "OneWayNode.h"

class CyclicOneWayLinkedList {
private:
    OneWayNode* head;
    int size;

public:
    CyclicOneWayLinkedList();
    ~CyclicOneWayLinkedList();
    void addNodeAtBeginning(int i_value);
    void addNodeAtEnd(int i_value);
    void addNodeAtRandomPosition(int i_value, int node_index);
    void removeNodeAtBeginning();
    void removeNodeAtEnd();
    void removeNodeAtRandomPosition(int node_index);
    void findNode(int node_index);
    void displayList();
};

#endif // CYCLICONEWAYLINKEDLIST_H
