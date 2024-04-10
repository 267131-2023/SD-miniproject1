#include "TwoWayNode.h"

TwoWayNode::TwoWayNode(int i_value) {
    value = i_value;
    next_node = nullptr;
    previous_node = nullptr;
}

int TwoWayNode::getValue() const { //metoda nie zmienia stanu obiektu
    return value;
}

void TwoWayNode::setValue(int i_value) {
    value = i_value;
}

TwoWayNode* TwoWayNode::getNextNode() const { //metoda nie zmienia stanu obiektu
    return next_node;
}

void TwoWayNode::setNextNode(TwoWayNode* nextNode) {
    next_node = nextNode;
}

TwoWayNode* TwoWayNode::getPreviousNode() const { //metoda nie zmienia stanu obiektu
    return previous_node;
}

void TwoWayNode::setPreviousNode(TwoWayNode* nextNode) {
    previous_node = nextNode;
}