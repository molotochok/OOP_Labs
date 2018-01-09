#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <random>
#include "Container.h"
#include "Date.h"
#include "Time.h"
#include <ctime>
#include <algorithm>

namespace lab6 {
	//Constructors
	template<class T>
	Container<T>::Container(int size = 100) {
		this->size = size;
	}

	//Methods
	template<class T>
	void Container<T>::addElement(T newElement) {
		container.push_back(newElement);
	}
	template<class T>
	T Container<T>::getElement(int index) {
		return container[index];
	}
	template<class T>
	void Container<T>::outputContainer(char* text) {
		std::cout << text;
		for (int i = 0; i < size; i++) {
			std::cout << container[i] << std::endl;
		}
		std::cout << std::endl;
	}

	template<class T>
	void Container<T>::quickSort(int left, int right) {
		int i = left, j = right;
		T temp;
		T pivot = container[(left + right) / 2];

		//partition
		while (i <= j) {
			while (container[i] < pivot)
				i++;
			while (container[j] > pivot)
				j--;
			if (i <= j) {
				temp = container[i];
				container[i] = container[j];
				container[j] = temp;
				i++;
				j--;
			}
		}

		if (left < j) {
			quickSort(left, j);
		}
		if (i < right) {
			quickSort(i, right);
		}
	}
	template<> void Container<char *>::quickSort(int left, int right) {
		int i = left, j = right;
		char* temp;
		std::string pivot = container[(left + right) / 2];

		//partition
		while (i <= j) {
			while (container[i] < pivot)
				i++;
			while (container[j] > pivot)
				j--;
			if (i <= j) {
				temp = container[i];
				container[i] = container[j];
				container[j] = temp;
				i++;
				j--;
			}
		}

		if (left < j) {
			quickSort(left, j);
		}
		if (i < right) {
			quickSort(i, right);
		}
	}

	//getter and setter
	template<class T>
	int Container<T>::getSize() {
		return size;
	}

	//-------------------------------------------
	template Container<int>;
	template Container<char *>;
	template Container<Date>;
	template Container<Time>;
}