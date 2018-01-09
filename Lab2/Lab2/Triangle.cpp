#include"Triangle.h"
#include<iostream>
namespace lab2 {
	Triangle::Triangle(float x1, float y1, float x2, float y2, float x3, float y3) :SectionA(x1, y1, x2, y2),
		SectionB(x2, y2, x3, y3),
		SectionC(x1, y1, x3, y3) {};
	void Triangle::CalculateSquare(float len1, float len2, float len3) {
		if (len1 >= (len2 + len3) || len2 >= (len1 + len3) || len3 >= (len1 + len2)) {
			std::cout << "Triangle can not exist!!!\n";
		}
		else {
			float p = (len1 + len2 + len3) / 2;
			float s = sqrt(p*(p - len1)*(p - len2)*(p - len3));
			std::cout << "Triangle can exist!!!\n" << "Square = " << s << "\n";
		}
	}
}