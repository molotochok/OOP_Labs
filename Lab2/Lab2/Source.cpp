#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Triangle.h"
using namespace lab2;
int main() {
	std::cout << "Creator: Markiian Karpa\nGroup: IP-63\n";
	int points[3][2];
	bool exit2 = false;
	do {
		std::cout << "Input coordinats of points A(x1,y1), B(x2,y2), C(x3,y3):\n";
		for (int i = 0; i < 3; i++) {
			std::cout << "x" << i << " = ";
			std::cin >> points[i][0];

			std::cout << "y" << i << " = ";
			std::cin >> points[i][1];
		}
		Triangle triangle(points[0][0], points[0][1],
			points[1][0], points[1][1],
			points[2][0], points[2][1]
		);
		triangle.CalculateSquare(triangle.SectionA::GetLength(), triangle.SectionB::GetLength(), triangle.SectionC::GetLength());
		char decision;
		bool exit1 = false;
		do {
			std::cout << "Continue? (Y/N) "; std::cin >> decision;
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