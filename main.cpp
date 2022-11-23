// CMPR 131 Fall 2022 Assignment 12 Searches and Hashing
// Date: 11-22-2022
// By: Victor Huerta


#include <iostream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "input.h"

int menuOption();
void challenge1();
void challenge2();
void challenge3();
string* createRandomArray(int);
void addElement(int&);
void printArray(int);
void serialSearch(string, int);
void selectionSort(string*, int);
int binarySearchString(string* arr, string x, int n);
bool is_number(const std::string& s);
void selectionSort(string* array, int NUM_NAMES);
string* ptr = nullptr;

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

// add selection sort function and swap function for challenge 2
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
	int sizeOfArray = 0;
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
		option = inputInteger("\n\tOption: ", 0, 5);
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
			sizeOfArray = inputInteger("\n\tEnter the size of the dynamic array: ",1, 10000);
			ptr = createRandomArray(sizeOfArray);
			system("pause");
			break;
		}
		case 2: {
			addElement(sizeOfArray);
			break;
		}
		case 3: {
			printArray(sizeOfArray);
			break;
		}
		case 4: {
			string searchValue = inputString("\n\tEnter a value to search for in the array: ", false);

			serialSearch(searchValue, sizeOfArray);
			break;
		}
		case 5:{
			if (sizeOfArray > 0) {
				delete[] ptr;
				ptr = nullptr;
				cout << "\n\tElements from the array have been cleared/deleted.";
			}
			else {
				cout << "\n\tThe array is empty.";
			}
			sizeOfArray = 0;
		    break;
		}
		default: break;
		}
	} while (flag);
}

string* createRandomArray(int size) {
	string* arrPtr = new string[size];
	const int MAX_VALUE = 100;
	const int MIN_VALUE = 0;
	unsigned seed = time(0);
	srand(seed);
	int randNum;
	for (int i = 0; i < size; i++) {
		randNum = (rand() % (MAX_VALUE - (MIN_VALUE + 1) + MIN_VALUE));
		arrPtr[i] = to_string(randNum);
	}

	for (int i = 0; i < size; i++) {
		cout << "\n" << arrPtr[i];
	}

	return arrPtr;
}

void addElement(int &size) {
	int num;
	if (size == 0) {
		num = inputInteger("\n\tEnter a number to add to the dynamic array: ", 0, 100);
		ptr = new string[1];
		ptr[0] = to_string(num);
		size = 1;
	}
	else {
		size += 1;
		string* temp = new string[size];

		for (int i = 0; i < size - 1; i++) {
			temp[i] = ptr[i];
		}	
		num = inputInteger("\n\tEnter a number to add to the dynamic array: ", 0, 100);
		temp[size - 1] = to_string(num);

		delete[] ptr;
		ptr = temp;
		temp = nullptr;
	}
}

void printArray(int size) {
	if (size == 0) {
		cout << "\n\tThe array is empty.";
	}
	else {
		cout << "\n\tArray values:";
		for (int i = 0; i < size; i++) {
		      cout << "\n\t" << ptr[i];
		}
	}
}

void serialSearch(string val, int size) {
	int index = -1;
	if (size == 0) {
		cout << "\n\tThe array is empty.";
		return;
	}
	for (int i = 0; i < size; i++) {
		if (ptr[i] == val) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		cout << "\n\tCould not locate " << val << " in array.";
	}
	else {
		cout << "\n\tValue " << val << " found at index " << index << ".";
	}
}
void challenge2() {
	int option;
	bool flag = true;
	int sizeOfArray = 0;
	do {
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
		int option = inputInteger("\n\tOption: ", 0, 5);
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
			sizeOfArray = inputInteger("\n\tEnter the size of the dynamic array: ", 1, 10000);
			ptr = createRandomArray(sizeOfArray);
			selectionSort(ptr,sizeOfArray);
			system("pause");
			break;
		}
		case 2: {
			addElement(sizeOfArray);
			selectionSort(ptr, sizeOfArray);
			break;
		}
		case 3: {
			printArray(sizeOfArray);
			break;
		}
		case 4: {
			string searchValue = inputString("\n\tEnter a value to search for in the array: ", false);
			if (sizeOfArray > 0) {
				serialSearch(searchValue, sizeOfArray);
			}
			else {
				cout << "\n\tThe array is empty";
			}
			break;
		}
		case 5: {
			if (sizeOfArray > 0) {
				delete[] ptr;
				ptr = nullptr;
				cout << "\n\tElements from the array have been cleared/deleted.";
			}
			else {
				cout << "\n\tThe array is empty.";
			}
			sizeOfArray = 0;
			break;
		}
		default: break;
		}
	} while (flag);
}


bool is_number(const std::string& s)
{
	return !s.empty() && std::find_if(s.begin(),
		s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

void selectionSort(string* array, int NUM_NAMES)
{
	int startScan, minIndex;
	string minValue;

	for (startScan = 0; startScan < (NUM_NAMES - 1); startScan++)
	{

		minIndex = startScan;
		minValue = array[startScan];
		for (int index = startScan + 1; index < NUM_NAMES; index++)
		{
			if (is_number(array[index]) && is_number(minValue)) {
				if (stoi(array[index]) < stoi(minValue))
				{
					minValue = array[index];
					minIndex = index;
				}
			}
			else
			{
				minValue = array[index];
				minIndex = index;
			}
		}
		array[minIndex] = array[startScan];
		array[startScan] = minValue;
	}
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