#include"Function2.h"
#include<iostream>
namespace lab3 {
	Function2::Function2(float x, float y, float z) :Function(x), y(y), z(z) {};
	float Function2::calculate() {
		return (sin(x) + 3 * pow(z, y) - y*z);
	}
	void Function2::output(float f) {
		std::cout << "f2 = " << f << "\n";
	}
}