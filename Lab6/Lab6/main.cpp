#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Container.h"
#include "Date.h"
#include "Time.h"

using namespace std;
using namespace lab6;

template<class T>
void outputContainer();


int main() {
	cout << "Created by Markiian Karpa IP-63" << endl;
	bool exit2 = false;
	do {
		char decision;
		bool exit1 = false;

		//----------------Main program------------------
		char decisionType;
		cout << "Choose: 1 - int, 2 - char*, 3 - Time, 4 - Date\n"; cin >> decisionType;
		switch (decisionType) {
		case '1': outputContainer<int>();    break;
		case '2': outputContainer<char*>();  break;
		case '3': outputContainer<Time>();   break;
		case '4': outputContainer<Date>();   break;
		default:break;
		}
		//----------------------------------------------
		do {
			cout << "Continue? (Y/N) "; cin >> decision;
			if (decision == 'n' || decision == 'N') {
				exit1 = true;
				exit2 = true;
			}
			else if (decision == 'y' || decision == 'Y') {
				exit1 = true;
			}
		} while (!exit1);
	} while (!exit2);
	system("pause");
	return 0;
}

template<class T>
void outputContainer() {
	int size = 0;
	cout << "Input size: "; cin >> size; cin.ignore();
	Container<T> container(size);
	inizializeContainer(container, size);
	cout << "\n\n";
	container.outputContainer("Before sort:\n");
	container.quickSort(0, container.getSize() - 1);
	container.outputContainer("After sort:\n");
	cout << "-------------------------------------------------------\n";
}


//Inizialize container
template<class T>
void inizializeContainer(Container<T> &container, int size) {
	cout << "Input values:\n";
	for (int i = 0; i < size; i++) {
		T temp;
		cout << "element" << i + 1 << ": ";
		cin >> temp;
		container.addElement(temp);
	}
}
template<> void inizializeContainer<char *>(Container<char *> &container, int size) {
	cout << "Input values:\n";
	for (int i = 0; i < size; i++) {
		cout << "element" << i + 1 << ": ";

		string temp;
		getline(cin, temp);
		auto buff = new char[temp.length()];
		strcpy(buff, temp.data());

		container.addElement(buff);
	}
}
template<> void inizializeContainer<Time>(Container<Time>& container,int size) {
	cout << "Input values:\n";
	for (int i = 0; i < size; i++) {
		int second = 0, minute = 0, hour = 0;
		cout << "<--Time" << i + 1 << "-->\n";
		cout << "Second: "; cin >> second;
		cout << "Minute: "; cin >> minute;
		cout << "Hour: ";   cin >> hour;
		Time temp(second, minute, hour);
		container.addElement(temp);
	}
}
template<>void inizializeContainer<Date>(Container<Date>& container, int size) {
	cout << "Input values:\n";
	for (int i = 0; i < size; i++) {
		int day = 0, month = 0, year = 0;
		cout << "<--Date" << i + 1 << "-->\n";
		cout << "Day: ";   cin >> day;
		cout << "Month: "; cin >> month;
		cout << "Year: ";  cin >> year;
		Date temp(day, month, year);
		container.addElement(temp);
	}
}