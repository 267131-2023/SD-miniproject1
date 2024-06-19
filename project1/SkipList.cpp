#include "SkipList.h"

SkipListNode::SkipListNode(int level, int value) : value(value), forward(level + 1, nullptr) {}

SkipList::SkipList(int maxLevel, float probability)
    : maxLevel(maxLevel), currentLevel(0), probability(probability) {
    header = new SkipListNode(maxLevel, -1);
}

SkipList::~SkipList() {
    SkipListNode* node = header->forward[0];
    while (node != nullptr) {
        SkipListNode* next = node->forward[0];
        delete node;
        node = next;
    }
    delete header;
}

int SkipList::randomLevel() {
    int level = 0;
    while (static_cast<float>(rand()) / RAND_MAX < probability && level < maxLevel) {
        level++;
    }
    return level;
}

void SkipList::addFront(int value) {
    addRandom(value, 0);
}

void SkipList::addEnd(int value) {
    addRandom(value, currentLevel);
}

void SkipList::addRandom(int value, int position) {
    std::vector<SkipListNode*> update(maxLevel + 1);
    SkipListNode* node = header;

    for (int i = currentLevel; i >= 0; i--) {
        while (node->forward[i] != nullptr && node->forward[i]->value < value) {
            node = node->forward[i];
        }
        update[i] = node;
    }
    node = node->forward[0];

    if (node == nullptr || node->value != value) {
        int level = randomLevel();
        if (level > currentLevel) {
            for (int i = currentLevel + 1; i <= level; i++) {
                update[i] = header;
            }
            currentLevel = level;
        }
        node = new SkipListNode(level, value);
        for (int i = 0; i <= level; i++) {
            node->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = node;
        }
    }
}

void SkipList::removeFront() {
    if (header->forward[0] != nullptr) {
        SkipListNode* node = header->forward[0];
        for (int i = 0; i <= currentLevel; i++) {
            if (header->forward[i] == node) {
                header->forward[i] = node->forward[i];
            }
        }
        delete node;
        while (currentLevel > 0 && header->forward[currentLevel] == nullptr) {
            currentLevel--;
        }
    }
}

void SkipList::removeEnd() {
    if (header->forward[0] == nullptr) return;

    SkipListNode* node = header;
    for (int i = currentLevel; i >= 0; i--) {
        while (node->forward[i] != nullptr && node->forward[i]->forward[i] != nullptr) {
            node = node->forward[i];
        }
    }
    removeRandom(node->forward[0]->value);
}

void SkipList::removeRandom(int position) {
    std::vector<SkipListNode*> update(maxLevel + 1);
    SkipListNode* node = header;

    for (int i = currentLevel; i >= 0; i--) {
        while (node->forward[i] != nullptr && node->forward[i]->value < position) {
            node = node->forward[i];
        }
        update[i] = node;
    }
    node = node->forward[0];

    if (node != nullptr && node->value == position) {
        for (int i = 0; i <= currentLevel; i++) {
            if (update[i]->forward[i] == node) {
                update[i]->forward[i] = node->forward[i];
            }
        }
        delete node;
        while (currentLevel > 0 && header->forward[currentLevel] == nullptr) {
            currentLevel--;
        }
    }
}

void SkipList::search(int position) {
    SkipListNode* node = header;
    for (int i = currentLevel; i >= 0; i--) {
        while (node->forward[i] != nullptr && node->forward[i]->value < position) {
            node = node->forward[i];
        }
    }
    node = node->forward[0];

    if (node != nullptr && node->value == position) {
        //cout << node->value << std::endl;
    }
    else {
        cout << "Node not found" << std::endl;
    }
}

void SkipList::displayList() {
    for (int i = currentLevel; i >= 0; i--) {
        SkipListNode* node = header->forward[i];
        cout << "Level " << i << ": ";
        while (node != nullptr) {
            cout << node->value << " ";
            node = node->forward[i];
        }
        cout << std::endl;
    }
}