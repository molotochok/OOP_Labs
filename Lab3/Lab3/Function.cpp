#include"Function.h"
#include<iostream>
namespace lab3 {
	Function::Function(float x) :x(x) {};
	void Function::output(float f) {
		std::cout << "f = " << f << "\n";
	}
}