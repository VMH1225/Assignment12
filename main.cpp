// CMPR 131 Fall 2022 Assignment 12 Searches and Hashing
// Date: 11-22-2022
// By: Victor Huerta


#include <iostream>
#include <iostream>
using namespace std;
#include "input.h"

int menuOption();
void challenge1();
void challenge2();
void challenge3();

int main() {

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
	int option = inputInteger("\n\tOption: ", 0, 4);
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
