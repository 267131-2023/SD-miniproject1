#include "iostream"
#include "TwoWayLinkedList.h"

using namespace std;

// bezpoœredni¹ inicjalizacjê zmiennych sk³adowych w momencie tworzenia obiektu
TwoWayLinkedList::TwoWayLinkedList() : head(nullptr), tail(nullptr), size(0) {}

TwoWayLinkedList ::~TwoWayLinkedList() {
    TwoWayNode* current = head;

    while (current != nullptr) {
        TwoWayNode* next = current->getNextNode();
        delete current;
        current = next;
    }
}

void TwoWayLinkedList::addNodeAtBeginning(int i_value) {
    TwoWayNode* node = new TwoWayNode(i_value);

    if (head == nullptr) { // pusta lista
        head = node;
        tail = node;
        size++;
        return;
    }
    node->setNextNode(head);
    head->setPreviousNode(node);
    head = node;
    size++;
}

void TwoWayLinkedList::addNodeAtEnd(int i_value) {
    TwoWayNode* node = new TwoWayNode(i_value);

    if (head == nullptr) { // pusta lista
        head = node;
        tail = node;
        size++;
        return;
    }
    tail->setNextNode(node);
    node->setPreviousNode(tail);
    tail = node;
    size++;
}

void TwoWayLinkedList::addNodeAtRandomPosition(int i_value, int node_index) {
    if (node_index > size) {
        cout << "Indeks poza zakresem listy." << endl;
        return;
    }
    else if (node_index == 0) { // dodawanie na pocz¹tku listy
        addNodeAtBeginning(i_value);
        return;
    }
    else if (node_index == size) { // dodawanie na koncu listy
        addNodeAtEnd(i_value);
        return;
    }
    else {
        TwoWayNode* node = new TwoWayNode(i_value);

        // sprawdzamy, czy indeks jest bli¿ej pocz¹tku
        if (node_index < size / 2) {
            TwoWayNode* current_node = head;
            int counter = 0;

            //szukamy wezla poprzedzaj¹cego wêze³ o podanym indeksie
            while (counter < node_index - 1) {
                current_node = current_node->getNextNode();
                counter++;
            }
            TwoWayNode* next_node = current_node->getNextNode();
            node->setNextNode(next_node);
            current_node->setNextNode(node);
            next_node->setPreviousNode(node);
            node->setPreviousNode(current_node);
            size++;
            return;
        }
        else {
            // indeks jest bli¿ej konca listy
            TwoWayNode* current_node = tail;
            int counter = size - 1;

            // Szukamy wêz³a o podanym indeksie
            while (counter > node_index) {
                current_node = current_node->getPreviousNode();
                counter--;
            }
            TwoWayNode* previous_node = current_node->getPreviousNode();
            previous_node->setNextNode(node);
            node->setNextNode(current_node);
            current_node->setPreviousNode(node);
            node->setPreviousNode(previous_node);
            size++;
        }
    }
}

void TwoWayLinkedList::removeNodeAtBeginning() {
    if (head == nullptr) { // lista jest pusta
        cout << "Lista jest pusta" << endl;
    }
    if (head->getNextNode() == nullptr) { // lista zawiera tylko jeden element
        delete head;
        head = nullptr;
        tail = nullptr;
        size--;
        return;
    }
    TwoWayNode* current_node = head->getNextNode();
    delete head;
    current_node->setPreviousNode(nullptr);
    head = current_node;
    size--;
}

void TwoWayLinkedList::removeNodeAtEnd() {
    if (head == nullptr) { // Lista jest pusta
        cout << "Lista jest pusta" << endl;
    }
    if (head->getNextNode() == nullptr) { // Lista zawiera tylko jeden element
        delete head;
        head = nullptr;
        tail = nullptr;
        size--;
        return;
    }
    TwoWayNode* last_node = tail->getPreviousNode();
    delete tail;
    last_node->setNextNode(nullptr);
    tail = last_node;
    size--;
}

void TwoWayLinkedList::removeNodeAtRandomPosition(int node_index) {
    if (node_index + 1 > size) {
        cout << "Indeks poza zakresem listy." << endl;
        return;
    }
    else if (node_index == 0) { // usuwanie na pocz¹tku listy
        removeNodeAtBeginning();
        return;
    }
    else if (node_index + 1 == size) { // usuwanie na koncu listy
        removeNodeAtEnd();
        return;
    }
    else {
        // sprawdzamy, czy indeks jest bli¿ej pocz¹tku
        if (node_index < size / 2) {
            TwoWayNode* current_node = head;
            int counter = 0;

            // Szukamy wêz³a o podanym indeksie
            while (counter < node_index) {
                current_node = current_node->getNextNode();
                counter++;
            }
            TwoWayNode* previous_node = current_node->getPreviousNode();
            TwoWayNode* next_node = current_node->getNextNode();
            previous_node->setNextNode(next_node);
            next_node->setPreviousNode(previous_node);
            delete current_node;
            size--;
            return;
        }
        else {
            // indeks jest bli¿ej konca listy
            TwoWayNode* current_node = tail;
            int counter = size - 1;

            // Szukamy wêz³a o podanym indeksie
            while (counter > node_index) {
                current_node = current_node->getPreviousNode();
                counter--;
            }
            TwoWayNode* previous_node = current_node->getPreviousNode();
            TwoWayNode* next_node = current_node->getNextNode();
            previous_node->setNextNode(next_node);
            next_node->setPreviousNode(previous_node);
            delete current_node;
            size--;
        }
    }
}

void TwoWayLinkedList::findNode(int node_index) {
    if (node_index + 1 > size) {
        cout << "Indeks poza zakresem listy." << endl;
        return;
    }
    TwoWayNode* current_node = head;
    TwoWayNode* last_node = tail;

    if (node_index == 0) { // pierwszy element
        cout << current_node->getValue() << endl;
        return;
    }
    else if (node_index == size) { // ostatni element
        cout << last_node->getValue() << endl;
        return;
    }
    else {
        // sprawdzamy, czy indeks jest bli¿ej pocz¹tku
        if (node_index < size / 2) {
            int counter = 0;

            // Szukamy wêz³a o podanym indeksie
            while (counter < node_index) {
                current_node = current_node->getNextNode(); //przechodzimy do nastepnego wezla listy
                counter++;
            }
            cout << current_node->getValue();
            return;
        }
        else {
            // indeks jest bli¿ej konca listy
            int counter = size - 1;

            // Szukamy wêz³a o podanym indeksie
            while (counter > node_index) {
                last_node = last_node->getPreviousNode();
                counter--;
            }
            cout << last_node->getValue();
        }
    }
}

void TwoWayLinkedList::displayList() {
    if (head == nullptr) {
        cout << "Lista jest pusta" << endl;
        return;
    }
    TwoWayNode* current_node = head;

    while (current_node != nullptr) {
        cout << current_node->getValue() << "  ";
        current_node = current_node->getNextNode();
    }
}


