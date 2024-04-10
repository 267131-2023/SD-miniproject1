#pragma once
#include <cstdlib>


class dynamicArray
{
private:
	int* array;
	int size;
	int capacity;

	void resize();

public:
	dynamicArray();

	~dynamicArray();

	void addEnd(int value);

	void addFront(int value);

	void addRandom(int value);

	void search(int index);

	void removeEnd();

	void removeFront();

	void removeRandom();

	void display();

	int getSize();

	int getValue(int index);
};

