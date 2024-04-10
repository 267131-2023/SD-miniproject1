#include "OneWayNode.h"

OneWayNode::OneWayNode(int i_value) {
    value = i_value;
    next_node = nullptr;
}

int OneWayNode::getValue() const { //metoda nie zmienia stanu obiektu
    return value;
}

void OneWayNode::setValue(int i_value) {
    value = i_value;
}

OneWayNode* OneWayNode::getNextNode() const { //metoda nie zmienia stanu obiektu
    return next_node;
}

void OneWayNode::setNextNode(OneWayNode* nextNode) {
    next_node = nextNode;
}
