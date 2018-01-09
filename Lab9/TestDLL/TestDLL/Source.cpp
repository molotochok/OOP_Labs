#include<iostream>
#include<vector>
#include<windows.h>
#include"Matrix.h"

int main() {
	std::cout << "Created by Markiian Karpa IP-63" << std::endl;
	bool exit2 = false;
	do {
		char decision;
		bool exit1 = false;

		//----------------Main program------------------
		try {
			int m, n;
			char isRandomDecision;
			bool isRandom;
			std::cout << "Generate randomly?(Y/N) "; std::cin >> isRandomDecision;
			if (isRandomDecision == 'Y' || isRandomDecision == 'y')
				isRandom = true;
			else if (isRandomDecision == 'N' || isRandomDecision == 'n')
				isRandom = false;
			else
				throw 1;

			std::cout << "m= "; std::cin >> m;
			std::cout << "n= "; std::cin >> n;
			//Dynamic dll open
			using createMatrixPtr = matrix::Matrix*(*)(int, int, bool);
			using destroyMatrixPtr = void(*)(matrix::Matrix*);

			HINSTANCE hDllInstance = LoadLibrary(L"Matrix.dll");
			if (!hDllInstance) {
				throw 4;
			} 
			createMatrixPtr createMatrix = (createMatrixPtr)GetProcAddress(hDllInstance, "createMatrix");
			destroyMatrixPtr destroyMatrix = (destroyMatrixPtr)GetProcAddress(hDllInstance, "destroyMatrix");
			if (!createMatrix) {
				throw 2;
			}
			if (!destroyMatrix) {
				throw 3;
			}

			auto matrix = createMatrix(m, n, isRandom);
			matrix->outputMatrix();
			std::vector<int> vector = matrix->getSumInRows();
			matrix->outputVector(vector);
			destroyMatrix(matrix);
			FreeLibrary(hDllInstance);
			//Dynamic dll close
		}
		catch (int a) {
			if (a == 1) {
				std::cout << "You should write y or n!!!\n";
				continue;
			}
			else if (a == 2) {
				std::cout << "Can't load createMatrix\n";
				continue;
			}
			else if (a == 3) {
				std::cout << "Can't load destroyMatrix\n";
				continue;
			}
			else if (a == 4) {
				std::cout << "Can't load hDllInstance\n";
				continue;
			}
		}
		//----------------------------------------------
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