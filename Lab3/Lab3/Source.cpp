#include<iostream>
#include"Function1.h"
#include"Function2.h"
using namespace lab3;
int main() {
	std::cout << "Creator: Markiian Karpa\nGroup: IP-63\n";
	float x1, y1, x2, y2, z2;
	bool exit2 = false;
	do{
		std::cout << "First formual:\n" << "x= "; std::cin >> x1;
		std::cout << "y= ";						std::cin >> y1;
		Function* f1 = new Function1(x1, y1);
		
		try {
			f1->output(f1->calculate());
		}
		catch (std::runtime_error error) {
			std::cout << error.what();
		}
		std::cout << "Second formual:\n" << "x= "; std::cin >> x2;
		std::cout << "y= ";						std::cin >> y2;
		std::cout << "z= ";						std::cin >> z2;
		Function* f2 = new Function2(x2, y2, z2);
		f2->output(f2->calculate());

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