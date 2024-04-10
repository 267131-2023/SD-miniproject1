#include <iostream>
#include <chrono>

#include "dynamicArray.h"
#include "OneWayLinkedListH.h"
#include "OneWayLinkedListHT.h"
#include "TwoWayLinkedList.h"

using namespace std;
using namespace std::chrono;

void displayMainMenu(dynamicArray& array, OneWayLinkedListH& listH, OneWayLinkedListHT& listHT, TwoWayLinkedList& list, int& choice, int& number, int& element);


void displayArrayMenu(dynamicArray& array, int& choice, int& number, int& element) {
    cout << "========arrayMENU=======" << endl;
    cout << "1. Dodaj dane na poczatek tablicy" << endl;
    cout << "2. Dodaj dane na koniec tablicy" << endl;
    cout << "3. Dodaj dane randomowo" << endl;
    cout << "4. Usun dane z poczatku tablicy" << endl;
    cout << "5. Usun dane z konca tablicy" << endl;
    cout << "6. Usun dane randomowo" << endl;
    cout << "7. Wyszukaj w tablicy" << endl;
    cout << "8. Wyswietl tablice" << endl;
    cout << "9. Powrot" << endl;
    cin >> choice;
    switch (choice) {
    case 1: {
        auto start = high_resolution_clock::now();
            array.addFront(element);
        auto stop = high_resolution_clock::now();
        duration<double, milli> duration = stop - start;

        cout << "Czas wykonania operacji: " << duration.count() << " milisekund" << endl;
        displayArrayMenu(array, choice, number, element);
        break;
    }
    case 2: {
        auto start = high_resolution_clock::now();
            array.addEnd(element);
        auto stop = high_resolution_clock::now();
        duration<double, milli> duration = stop - start;

        cout << "Czas wykonania operacji: " << duration.count() << " milisekund" << endl;
        displayArrayMenu(array, choice, number, element);
        break;
    }
    case 3: {
        auto start = high_resolution_clock::now();
            array.addRandom(element);
        auto stop = high_resolution_clock::now();
        duration<double, milli> duration = stop - start;

        cout << "Czas wykonania operacji: " << duration.count() << " milisekund" << endl;
        displayArrayMenu(array, choice, number, element);
        break;
    }
    case 4: {
        auto start = high_resolution_clock::now();
            array.removeFront();
        auto stop = high_resolution_clock::now();
        duration<double, milli> duration = stop - start;

        cout << "Czas wykonania operacji: " << duration.count() << " milisekund" << endl;
        displayArrayMenu(array, choice, number, element);
        break;
    }
    case 5: {
        auto start = high_resolution_clock::now();
            array.removeEnd();
        auto stop = high_resolution_clock::now();
        duration<double, milli> duration = stop - start;

        cout << "Czas wykonania operacji: " << duration.count() << " milisekund" << endl;
        displayArrayMenu(array, choice, number, element);
        break;
    }
    case 6: {
        auto start = high_resolution_clock::now();
            array.removeRandom();
        auto stop = high_resolution_clock::now();

        duration<double, milli> duration = stop - start;
        cout << "Czas wykonania operacji: " << duration.count() << " milisekund" << endl;
        displayArrayMenu(array, choice, number, element);
        break;
    }
    case 7: {
        int size = array.getSize();
        int index = rand() % size;
        auto start = high_resolution_clock::now();
        array.search(index);
        auto stop = high_resolution_clock::now();
        duration<double, milli> duration = stop - start;

        cout << "Czas wykonania operacji: " << duration.count() << " milisekund" << endl;
        displayArrayMenu(array, choice, number, element);
        break;
    }
    case 8:
        array.display();
        displayArrayMenu(array, choice, number, element);
        break;
    case 9:
  
        break;
    default:
        cout << "Nieprawidlowa opcja. Wybierz ponownie" << endl;
    }
}

void displayMainMenu(dynamicArray& array, OneWayLinkedListH& listH, OneWayLinkedListHT& listHT, TwoWayLinkedList& list, int& choice, int& number, int& element) {
    int randomNumber;
    for (int i = 0; i < number; i++) {
        randomNumber = rand();
        array.addFront(randomNumber);
        //listH.addNodeAtEnd(randomNumber);
        //listHT.addNodeAtEnd(randomNumber);
        //list.addNodeAtEnd(randomNumber);
    }
    cout << "==========MENU==========" << endl;
    cout << "1. Tablica dynamiczna" << endl;
    cout << "2. Lista jednokierunkowa" << endl;
    cout << "3. Lista dwukierunkowa" << endl; 
    cout << "4. Wyjscie" << endl;
    cout << "========================" << endl;
    cin >> choice;
    switch (choice) {
    case 1:
        displayArrayMenu(array, choice, number, element);
        break;
    case 2:

        break;
    case 3:

        break;
    case 4:
        cout << "Koniec programu" << endl;
        break;
    default:
        cout << "Nieprawidlowa opcja. Wybierz ponownie" << endl;
    }
}

int main()
{
    OneWayLinkedListH listH = OneWayLinkedListH();
    OneWayLinkedListHT listHT = OneWayLinkedListHT();
    TwoWayLinkedList list = TwoWayLinkedList();
    dynamicArray array;
    int choice;
    int number = 10000; //liczba elementów zbioru
    int element = 1;

    //ziarno generatora
    unsigned int seed = 3007;

    srand(seed);

    int randomNumber;
    

    
    
    
    



    //displayMainMenu(array, listH, listHT, list, choice, number, element);


}

