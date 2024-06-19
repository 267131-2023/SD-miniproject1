#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

class SkipListNode {
public:
    int value;
    vector<SkipListNode*> forward;

    SkipListNode(int level, int value);
};

class SkipList {
private:
    int maxLevel;
    int currentLevel;
    SkipListNode* header;
    float probability;

    int randomLevel();
public:
    SkipList(int maxLevel, float probability);
    ~SkipList();

    void addFront(int value);
    void addEnd(int value);
    void addRandom(int value, int position);
    void removeFront();
    void removeEnd();
    void removeRandom(int position);
    void search(int position);
    void displayList();
};

