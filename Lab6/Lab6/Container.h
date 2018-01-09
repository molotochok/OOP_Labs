#pragma once
#include<vector>
namespace lab6 {
	template<class T>
	class Container {
	private:
		std::vector<T> container;
		int size;
	public:
		Container(int size);

		//Methods
		T	 getElement(int index);
		void addElement(T newElement);
		void quickSort(int left, int right);
		void outputContainer(char* text);

		//getter and setter
		int getSize();
	};
}