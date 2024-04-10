#include <iostream>
#include <chrono>

#include "dynamicArray.h"
#include "OneWayLinkedListH.h"
#include "OneWayLinkedListHT.h"
#include "TwoWayLinkedList.h"

using namespace std;
using namespace std::chrono;

void displayMainMenu(dynamicArray& array, OneWayLinkedListH& listH, OneWayLinkedListHT& listHT, TwoWayLinkedList& list, int& choice, int& number, int& element);

void displayTwoWayLinkedList(TwoWayLinkedList& list, int& choice, int& number, int& element) {
    cout << "========twoWayLinkedListMENU=======" << endl;
    cout << "1. Dodaj dane na poczatek listy" << endl;
    cout << "2. Dodaj dane na koniec listy" << endl;
    cout << "3. Dodaj dane randomowo do listy" << endl;
    cout << "4. Usun dane z poczatku listy" << endl;
    cout << "5. Usun dane z konca listy" << endl;
    cout << "6. Usun dane randomowo z listy" << endl;
    cout << "7. Wyszukaj w liscie" << endl;
    cout << "8. Wyjscie" << endl;
    cin >> choice;
    switch (choice) {
    case 1: {
        auto start = high_resolution_clock::now();
        list.addNodeAtBeginning(element);
        auto stop = high_resolution_clock::now();
        duration<double, milli> duration = stop - start;

        cout << "Czas wykonania operacji: " << duration.count() << " milisekund" << endl;
        displayTwoWayLinkedList(list, choice, number, element);
        break;
    }
    case 2: {
        auto start = high_resolution_clock::now();
        list.addNodeAtEnd(element);
        auto stop = high_resolution_clock::now();
        duration<double, milli> duration = stop - start;

        cout << "Czas wykonania operacji: " << duration.count() << " milisekund" << endl;
        displayTwoWayLinkedList(list, choice, number, element);
        break;
    }
    case 3: {
        auto start = high_resolution_clock::now();
        list.addNodeAtRandomPosition(element, 10);
        auto stop = high_resolution_clock::now();
        duration<double, milli> duration = stop - start;

        cout << "Czas wykonania operacji: " << duration.count() << " milisekund" << endl;
        displayTwoWayLinkedList(list, choice, number, element);
        break;
    }
    case 4: {
        auto start = high_resolution_clock::now();
        list.removeNodeAtBeginning();
        auto stop = high_resolution_clock::now();
        duration<double, milli> duration = stop - start;

        cout << "Czas wykonania operacji: " << duration.count() << " milisekund" << endl;
        displayTwoWayLinkedList(list, choice, number, element);
        break;
    }
    case 5: {
        auto start = high_resolution_clock::now();
        list.removeNodeAtEnd();
        auto stop = high_resolution_clock::now();
        duration<double, milli> duration = stop - start;

        cout << "Czas wykonania operacji: " << duration.count() << " milisekund" << endl;
        displayTwoWayLinkedList(list, choice, number, element);
        break;
    }
    case 6: {
        auto start = high_resolution_clock::now();
        list.removeNodeAtRandomPosition(10);
        auto stop = high_resolution_clock::now();

        duration<double, milli> duration = stop - start;
        cout << "Czas wykonania operacji: " << duration.count() << " milisekund" << endl;
        displayTwoWayLinkedList(list, choice, number, element);
        break;
    }
    case 7: {
        int index = rand() % 1000;
        auto start = high_resolution_clock::now();
        list.findNode(index);
        auto stop = high_resolution_clock::now();
        duration<double, milli> duration = stop - start;

        cout << "Czas wykonania operacji: " << duration.count() << " milisekund" << endl;
        displayTwoWayLinkedList(list, choice, number, element);
        break;
    }
    case 8: {
        break;
    }
    default:
        cout << "Nieprawidlowa opcja. Wybierz ponownie" << endl;
    }
}


void displayOneWayLinkedList(OneWayLinkedListH& listH, OneWayLinkedListHT& listHT, int& choice, int& number, int& element) {
    cout << "========oneWayLinkedListMENU=======" << endl;
    cout << "1. Dodaj dane na poczatek listy head" << endl;
    cout << "2. Dodaj dane na koniec listy head" << endl;
    cout << "3. Dodaj dane randomowo do listy head" << endl;
    cout << "4. Usun dane z poczatku listy head" << endl;
    cout << "5. Usun dane z konca listy head" << endl;
    cout << "6. Usun dane randomowo z listy head" << endl;
    cout << "7. Wyszukaj w liscie head" << endl;
    cout << "----------------------------------" << endl;
    cout << "8. Dodaj dane na poczatek listy head-tail" << endl;
    cout << "9. Dodaj dane na koniec listy head-tail" << endl;
    cout << "10. Dodaj dane randomowo do listy head-tail" << endl;
    cout << "11. Usun dane z poczatku listy head-tail" << endl;
    cout << "12. Usun dane z konca listy head-tail" << endl;
    cout << "13. Usun dane randomowo z listy head-tail" << endl;
    cout << "14. Wyszukaj w liscie head-tail" << endl;
    cout << "15. Wyjscie" << endl;
    cin >> choice;
    switch (choice) {
    case 1: {
        auto start = high_resolution_clock::now();
        listH.addNodeAtBeginning(element);
        auto stop = high_resolution_clock::now();
        duration<double, milli> duration = stop - start;

        cout << "Czas wykonania operacji: " << duration.count() << " milisekund" << endl;
        displayOneWayLinkedList(listH, listHT, choice, number, element);
        break;
    }
    case 2: {
        auto start = high_resolution_clock::now();
        listH.addNodeAtEnd(element);
        auto stop = high_resolution_clock::now();
        duration<double, milli> duration = stop - start;

        cout << "Czas wykonania operacji: " << duration.count() << " milisekund" << endl;
        displayOneWayLinkedList(listH, listHT, choice, number, element);
        break;
    }
    case 3: {
        auto start = high_resolution_clock::now();
        listH.addNodeAtRandomPosition(element, 10);
        auto stop = high_resolution_clock::now();
        duration<double, milli> duration = stop - start;

        cout << "Czas wykonania operacji: " << duration.count() << " milisekund" << endl;
        displayOneWayLinkedList(listH, listHT, choice, number, element);
        break;
    }
    case 4: {
        auto start = high_resolution_clock::now();
        listH.removeNodeAtBeginning();
        auto stop = high_resolution_clock::now();
        duration<double, milli> duration = stop - start;

        cout << "Czas wykonania operacji: " << duration.count() << " milisekund" << endl;
        displayOneWayLinkedList(listH, listHT, choice, number, element);
        break;
    }
    case 5: {
        auto start = high_resolution_clock::now();
        listH.removeNodeAtEnd();
        auto stop = high_resolution_clock::now();
        duration<double, milli> duration = stop - start;

        cout << "Czas wykonania operacji: " << duration.count() << " milisekund" << endl;
        displayOneWayLinkedList(listH, listHT, choice, number, element);
        break;
    }
    case 6: {
        auto start = high_resolution_clock::now();
        listH.removeNodeAtRandomPosition(10);
        auto stop = high_resolution_clock::now();

        duration<double, milli> duration = stop - start;
        cout << "Czas wykonania operacji: " << duration.count() << " milisekund" << endl;
        displayOneWayLinkedList(listH, listHT, choice, number, element);
        break;
    }
    case 7: {
        int index = rand() % 1000;
        auto start = high_resolution_clock::now();
        listH.findNode(index);
        auto stop = high_resolution_clock::now();
        duration<double, milli> duration = stop - start;

        cout << "Czas wykonania operacji: " << duration.count() << " milisekund" << endl;
        displayOneWayLinkedList(listH, listHT, choice, number, element);
        break;
    }
    case 8: {
        auto start = high_resolution_clock::now();
        listHT.addNodeAtBeginning(element);
        auto stop = high_resolution_clock::now();
        duration<double, milli> duration = stop - start;

        cout << "Czas wykonania operacji: " << duration.count() << " milisekund" << endl;
        displayOneWayLinkedList(listH, listHT, choice, number, element);
        break;
    }
    case 9: {
        auto start = high_resolution_clock::now();
        listHT.addNodeAtEnd(element);
        auto stop = high_resolution_clock::now();
        duration<double, milli> duration = stop - start;

        cout << "Czas wykonania operacji: " << duration.count() << " milisekund" << endl;
        displayOneWayLinkedList(listH, listHT, choice, number, element);
        break;
    }
    case 10: {
        auto start = high_resolution_clock::now();
        listHT.addNodeAtRandomPosition(element, 10);
        auto stop = high_resolution_clock::now();
        duration<double, milli> duration = stop - start;

        cout << "Czas wykonania operacji: " << duration.count() << " milisekund" << endl;
        displayOneWayLinkedList(listH, listHT, choice, number, element);
        break;
    }
    case 11: {
        auto start = high_resolution_clock::now();
        listHT.removeNodeAtBeginning();
        auto stop = high_resolution_clock::now();
        duration<double, milli> duration = stop - start;

        cout << "Czas wykonania operacji: " << duration.count() << " milisekund" << endl;
        displayOneWayLinkedList(listH, listHT, choice, number, element);
        break;
    }
    case 12: {
        auto start = high_resolution_clock::now();
        listHT.removeNodeAtEnd();
        auto stop = high_resolution_clock::now();
        duration<double, milli> duration = stop - start;

        cout << "Czas wykonania operacji: " << duration.count() << " milisekund" << endl;
        displayOneWayLinkedList(listH, listHT, choice, number, element);
        break;
    }
    case 13: {
        auto start = high_resolution_clock::now();
        listHT.removeNodeAtRandomPosition(10);
        auto stop = high_resolution_clock::now();
        duration<double, milli> duration = stop - start;

        cout << "Czas wykonania operacji: " << duration.count() << " milisekund" << endl;
        displayOneWayLinkedList(listH, listHT, choice, number, element);
        break;
    }
    case 14: {
        int index = rand() % 1000;
        auto start = high_resolution_clock::now();
        listHT.findNode(index);
        auto stop = high_resolution_clock::now();
        duration<double, milli> duration = stop - start;

        cout << "Czas wykonania operacji: " << duration.count() << " milisekund" << endl;
        displayOneWayLinkedList(listH, listHT, choice, number, element);
        break;
    }
    case 15: {
        
        break;
    }
    default:
        cout << "Nieprawidlowa opcja. Wybierz ponownie" << endl;
    }
}

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
    cout << "9. Wyjscie" << endl;
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
        displayOneWayLinkedList(listH, listHT, choice, number, element);
        break;
    case 3:
        displayTwoWayLinkedList(list, choice, number, element);
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
    for (int i = 0; i < number; i++) {
        randomNumber = rand();
        array.addFront(randomNumber);
        listH.addNodeAtEnd(randomNumber);
        listHT.addNodeAtEnd(randomNumber);
        list.addNodeAtEnd(randomNumber);
    }
    

    
    
    
    



    displayMainMenu(array, listH, listHT, list, choice, number, element);


}

