//zabezpieczenie przed podwojnym w³¹czeniem pliku do maina
#ifndef NODE_H
#define NODE_H

class OneWayNode {
private:
    int value;
    OneWayNode* next_node;
public:
    OneWayNode(int i_value);

    int getValue() const; //metoda nie zmienia stanu obiektu

    void setValue(int i_value);

    OneWayNode* getNextNode() const; //metoda nie zmienia stanu obiektu

    void setNextNode(OneWayNode* nextNode);
};

#endif // NODE_H
