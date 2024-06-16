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

void CyclicOneWayLinkedList::addNodeAtBeginning(int i_value) {
    OneWayNode* node = new OneWayNode(i_value);

    if (head == nullptr) {
        head = node;
        head->setNextNode(head);
    } else {
        OneWayNode* current = head;
        while (current->getNextNode() != head) {
            current = current->getNextNode();
        }
        node->setNextNode(head);
        head = node;
        current->setNextNode(head);
    }
    size++;
}

void CyclicOneWayLinkedList::addNodeAtEnd(int i_value) {
    OneWayNode* node = new OneWayNode(i_value);

    if (head == nullptr) {
        head = node;
        head->setNextNode(head);
    } else {
        OneWayNode* current = head;
        while (current->getNextNode() != head) {
            current = current->getNextNode();
        }
        current->setNextNode(node);
        node->setNextNode(head);
    }
    size++;
}

void CyclicOneWayLinkedList::addNodeAtRandomPosition(int i_value, int node_index) {
    if (node_index > size) {
        cout << "Indeks poza zakresem listy." << endl;
        return;
    } else if (node_index == 0) { // dodawanie na poczatku listy
        addNodeAtBeginning(i_value);
        return;
    } else if (node_index == size) { // dodawanie na koncu listy
        addNodeAtEnd(i_value);
        return;
    } else {
        OneWayNode* node = new OneWayNode(i_value);
        OneWayNode* current_node = head;
        int counter = 0;

        while (counter < node_index - 1) {
            current_node = current_node->getNextNode();
            counter++;
        }

        node->setNextNode(current_node->getNextNode());
        current_node->setNextNode(node);
        size++;
    }
}

void CyclicOneWayLinkedList::removeNodeAtBeginning() {
    if (head == nullptr) { // lista jest pusta
        cout << "Lista jest pusta" << endl;
        return;
    }
    if (head->getNextNode() == head) { // lista zawiera tylko jeden element
        delete head;
        head = nullptr;
    } else {
        OneWayNode* current = head;
        while (current->getNextNode() != head) {
            current = current->getNextNode();
        }
        OneWayNode* temp = head;
        head = head->getNextNode();
        current->setNextNode(head);
        delete temp;
    }
    size--;
}

void CyclicOneWayLinkedList::removeNodeAtEnd() {
    if (head == nullptr) { // lista jest pusta
        cout << "Lista jest pusta" << endl;
        return;
    }
    if (head->getNextNode() == head) { // lista zawiera tylko jeden element
        delete head;
        head = nullptr;
    } else {
        OneWayNode* previous_node = head;
        OneWayNode* current_node = head->getNextNode();

        while (current_node->getNextNode() != head) {
            previous_node = current_node;
            current_node = current_node->getNextNode();
        }
        previous_node->setNextNode(head);
        delete current_node;
    }
    size--;
}

void CyclicOneWayLinkedList::removeNodeAtRandomPosition(int node_index) {
    if (node_index >= size) {
        cout << "Indeks poza zakresem listy." << endl;
        return;
    } else if (node_index == 0) { // usuwanie na początku listy
        removeNodeAtBeginning();
        return;
    } else if (node_index == size - 1) { // usuwanie na koncu listy
        removeNodeAtEnd();
        return;
    } else {
        OneWayNode* previous_node = head;
        OneWayNode* current_node = head->getNextNode();
        int counter = 1;

        while (counter < node_index) {
            previous_node = previous_node->getNextNode();
            current_node = current_node->getNextNode();
            counter++;
        }
        previous_node->setNextNode(current_node->getNextNode());
        delete current_node;
        size--;
    }
}

void CyclicOneWayLinkedList::findNode(int node_index) {
    if (node_index >= size) {
        cout << "Indeks poza zakresem listy." << endl;
        return;
    }
    OneWayNode* current_node = head;
    int counter = 0;

    while (counter < node_index) {
        current_node = current_node->getNextNode();
        counter++;
    }
    cout << current_node->getValue() << endl;
}

void CyclicOneWayLinkedList::displayList() {
    if (head == nullptr) {
        cout << "Lista jest pusta" << endl;
        return;
    }
    OneWayNode* current_node = head;
    do {
        cout << current_node->getValue() << " ";
        current_node = current_node->getNextNode();
    } while (current_node != head);
    cout << endl;
}
