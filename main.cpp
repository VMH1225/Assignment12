// CMPR 131 Fall 2022 Assignment 12 Searches and Hashing
// Date: 11-22-2022
// By: Victor Huerta


#include <iostream>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "input.h"

int menuOption();
void challenge1();
void challenge2();
void challenge3();
int* createRandomArray(int);
int* ptr = nullptr;

int main() {

		// move ptr from challenge1 and create the ptr here that is visible for the first 2 challenges and release the
		// dynamically allocated memory after each program uses it. 
	do {
		switch (menuOption()) {
		case 0: exit(0);
		case 1: system("cls"); challenge1();  break;
		case 2: system("cls"); challenge2(); break;
		case 3: system("cls"); challenge3(); break;
		default: break;
		}
	} while (true);
}

int menuOption() {	

	cout << "\n\tCMPR131 Chapter 12: Searches and hashing by Victor Huerta (11/22/22)\n\t";
	cout << string(75, 205);
	cout << "\n\t1> Searching from an unsorted dynamic array";
	cout << "\n\t2> Searching from a sorted dynamic array";
	cout << "\n\t3> Application using hashing\n\t";
	cout << string(75, 196);	
	cout << "\n\t0> Exit\n\t";
	cout << string(75, 205);
	int option = inputInteger("\n\tOption: ", 0, 3);
	return option;
}

void challenge1() {	
	int option;
	bool flag = true;
	
	do {
		cout << "\n\t1> Searching unsorted dynamic arrays\n\t";
		cout << string(75, 205);
		cout << "\n\t1> Read data file and store into the array";
		cout << "\n\t2> Add an element to the dynamic array";
		cout << "\n\t3> Display elements from the array";
		cout << "\n\t4> Search for an element from the array";
		cout << "\n\t5> Clear the array\n\t";
		cout << string(75, 196);
		cout << "\n\t0> return\n\t";
		cout << string(75, 205);
		option = inputInteger("\n\tOption: ", 0, 4);
		flag = true;
		switch (option) {
		case 0: {
			delete[] ptr;
			ptr = nullptr;
			flag = false;
			break;
		}
		case 1: {
			delete[] ptr;
			system("cls"); 
			int num = inputInteger("\n\tEnter the size of the dynamic array: ",1, 10000);
			ptr = createRandomArray(num);
			system("pause");
			break;
		}
		case 2: {
			cout << "\nhi";
		}
		default: break;
		}
	} while (flag);
}

int* createRandomArray(int size) {
	int* arrPtr = new int[size];
	const int MAX_VALUE = 100;
	const int MIN_VALUE = 0;
	unsigned seed = time(0);
	srand(seed);
	int randNum;
	for (int i = 0; i < size; i++) {
		randNum = (rand() % (MAX_VALUE - (MIN_VALUE + 1) + MIN_VALUE));
		arrPtr[i] = randNum;
	}

	for (int i = 0; i < size; i++) {
		cout << "\n" << arrPtr[i];
	}

	return arrPtr;
}

void challenge2() {
	cout << "\n\t2> Searching sorted dynamic arrays\n\t";
	cout << string(75, 205);
	cout << "\n\t1> Read data file and store into the array";
	cout << "\n\t2> Add an element to the dynamic array";
	cout << "\n\t3> Display elements from the array";
	cout << "\n\t4> Search for an element from the array";
	cout << "\n\t5> Clear the array\n\t";
	cout << string(75, 196);
	cout << "\n\t0> return\n\t";
	cout << string(75, 205);
	int option = inputInteger("\n\tOption: ", 0, 4);
}

void challenge3() {
	cout << "\n\t3> Application using hashing\n\t";
	cout << string(75, 205);
	cout << "\n\t1> Read data file, hash and insert into the dynamic array";
	cout << "\n\t2> Search for an element from the array";
	cout << "\n\t3> Insert an element into the dynamic array";
	cout << "\n\t4> Remove an element from the dynamic array";
	cout << "\n\t5> Display all records from the array\n\t";
	cout << string(75, 196);
	cout << "\n\t0> return\n\t";
	cout << string(75, 205);
	int option = inputInteger("\n\tOption: ", 0, 4);
}