#include "iostream"
#include "OneWayLinkedListHT.h"

using namespace std;

// bezpoœredni¹ inicjalizacjê zmiennych sk³adowych w momencie tworzenia obiektu
OneWayLinkedListHT::OneWayLinkedListHT() : head(nullptr), tail(nullptr), size(0) {}

OneWayLinkedListHT ::~OneWayLinkedListHT() {
    OneWayNode* current = head;

    while (current != nullptr) {
        OneWayNode* next = current->getNextNode();
        delete current;
        current = next;
    }
}

void OneWayLinkedListHT::addNodeAtBeginning(int i_value) {
    OneWayNode* node = new OneWayNode(i_value);

    if (head == nullptr) { // pusta lista
        head = node;
        tail = node;
        size++;
        return;
    }
    node->setNextNode(head);
    head = node;
    size++;
}

void OneWayLinkedListHT::addNodeAtEnd(int i_value) {
    OneWayNode* node = new OneWayNode(i_value);

    if (head == nullptr) { // pusta lista
        head = node;
        tail = node;
        size++;
        return;
    }
    tail->setNextNode(node);
    tail = node;
    size++;
}

void OneWayLinkedListHT::addNodeAtRandomPosition(int i_value, int node_index) {
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
        OneWayNode* node = new OneWayNode(i_value);
        OneWayNode* current_node = head;
        int counter = 0;

        //szukamy wezla poprzedzaj¹cego wêze³ o podanym indeksie
        while (counter < node_index - 1) {
            current_node = current_node->getNextNode();
            counter++;
        }
        node->setNextNode(current_node->getNextNode());
        current_node->setNextNode(node);
        size++;
    }
}

void OneWayLinkedListHT::removeNodeAtBeginning() {
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
    OneWayNode* current_node = head->getNextNode();
    delete head;
    head = current_node;
    size--;
}

void OneWayLinkedListHT::removeNodeAtEnd() {
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
    OneWayNode* previous_node = head;
    OneWayNode* current_node = previous_node->getNextNode();

    // szukamy ostatniego wêz³a sprawdzaj¹c, czy nastêpny wêze³ od bie¿¹cego wêz³a istnieje
    while (current_node->getNextNode() != nullptr) {
        previous_node = current_node;
        current_node = current_node->getNextNode();
    }
    delete current_node;
    previous_node->setNextNode(nullptr);
    tail = previous_node;
    size--;
}

void OneWayLinkedListHT::removeNodeAtRandomPosition(int node_index) {
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
        OneWayNode* previous_node = head;
        OneWayNode* current_node = head->getNextNode();
        int counter = 1;

        // szukamy wêz³a o podanym indeksie oraz wêz³a bezpoœrednio poprzedzaj¹cego ten wêze³
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

void OneWayLinkedListHT::findNode(int node_index) {
    OneWayNode* current_node = head;
    OneWayNode* last_node = tail;
    if (node_index + 1 > size) {
        cout << "Indeks poza zakresem listy." << endl;
        return;
    }
    else if (node_index == 0) { // pierwszy element
        cout << current_node->getValue() << endl;
        return;
    }
    else if (node_index == size) { // ostatni element
        cout << last_node->getValue() << endl;
        return;
    }
    else {
        int counter = 0;

        //szukamy wezla o podanym indeksie
        while (counter < node_index) {
            current_node = current_node->getNextNode();
            counter++;
        }
        cout << current_node->getValue();
    }
}

void OneWayLinkedListHT::displayList() {
    if (head == nullptr) {
        cout << "Lista jest pusta" << endl;
        return;
    }
    OneWayNode* current_node = head;

    while (current_node != nullptr) {
        cout << current_node->getValue() << "  ";
        current_node = current_node->getNextNode();
    }
}


