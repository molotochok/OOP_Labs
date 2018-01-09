#include"Function1.h"
#include<iostream>
namespace lab3 {
	Function1::Function1(float x, float y) : Function(x), y(y) {};
	float Function1::calculate() {
		float temp = 3 * y*x;
		if (3 * y*x < 0) {
			throw std::runtime_error("Warning!!! Negative number under sqrt");
		}
		return (7 * pow(x, 4) + sqrt(3 * y*x));
	}
	void Function1::output(float f) {
		std::cout << "f1 = " << f << "\n";
	}
}