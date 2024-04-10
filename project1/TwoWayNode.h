#pragma once
class TwoWayNode {
private:
    int value;
    TwoWayNode* next_node;
    TwoWayNode* previous_node;
public:
    TwoWayNode(int i_value);

    int getValue() const; //metoda nie zmienia stanu obiektu

    void setValue(int i_value);

    TwoWayNode* getNextNode() const; //metoda nie zmienia stanu obiektu

    void setNextNode(TwoWayNode* nextNode);

    TwoWayNode* getPreviousNode() const; //metoda nie zmienia stanu obiektu

    void setPreviousNode(TwoWayNode* previousNode);
};