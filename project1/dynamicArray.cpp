#include "dynamicArray.h"
#include <iostream>

using namespace std;

dynamicArray::dynamicArray() : array(new int[2]), size(0), capacity(2) {}

dynamicArray::~dynamicArray() {
	delete[] array;
}

void dynamicArray::resize() {
	capacity *= 2;

	int* newArray = new int[capacity];

	for (int i = 0; i < size; i++) {
		newArray[i] = array[i];
	}

	delete[] array;
	array = newArray;

}


void dynamicArray::addEnd(int value) {

	if (size >= capacity) {
		resize();
	}

	array[size++] = value;
}

void dynamicArray::addFront(int value) {

	if (size >= capacity) {
		resize();
	}

	for (int i = size; i > 0; i--) {
		array[i] = array[i - 1];
	}

	array[0] = value;
	size++;
}

void dynamicArray::addRandom(int value) {

	if (size >= capacity) {
		resize();
	}

	int index = rand() % (size + 1);

	for (int i = size; i > index; i--) {
		array[i] = array[i - 1];
	}

	array[index] = value;
	size++;
}

void dynamicArray::search(int index) {

	
	if (size == 0) {
		cout << "Tablica jest pusta" << endl;
	}
	else {
		cout << "Wartosc przypisana do indexu " << index << " to " << array[index] << endl;
	}
}

void dynamicArray::removeEnd() {

	if (size > 0) {
		size--;
	}
	else {
		cout << "Tablica jest pusta." << endl;
	}
}

void dynamicArray::removeFront() {

	if (size > 0) {

		for (int i = 0; i < size; i++) {
			array[i] = array[i + 1];
		}

		size--;
	}
	else {
		cout << "Tablica jest pusta." << endl;
	}
}

void dynamicArray::removeRandom() {

	if (size > 0) {

		int index = rand() % size;

		for (int i = index; i < size - 1; i++) {
			array[i] = array[i + 1];
		}

		size--;
	}
	else {
		cout << "Tablica jest pusta." << endl;
	}
}

void dynamicArray::display() {
	
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

int dynamicArray::getSize() {
	return size;
}

int dynamicArray::getValue(int index) {
	return array[index];
}