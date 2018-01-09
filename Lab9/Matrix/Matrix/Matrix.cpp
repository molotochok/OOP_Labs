#include"Matrix.h"
#include<iostream>
#include<ctime>
namespace matrix {
	Matrix::Matrix(int m, int n, bool isRandom) : m(m), n(n) {
		setMatrix(m, n, isRandom);
	}

	std::vector<int> Matrix::getSumInRows() {
		std::vector<int> result;
		int sum;
		for (int i = 0; i < m; i++) {
			sum = 0;
			for (int j = 0; j < n; j++) {
				sum += matrix[i][j];
			}
			result.push_back(sum);
		}
		return result;
	}

	void Matrix::outputMatrix() {
		std::cout << "\nMatrix:\n";
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				printf("%5d", matrix[i][j]);
			}
			printf("\n");
		}
	}
	void Matrix::outputVector(std::vector<int> vect) {
		std::cout << "\nVector:\n";
		for (int i = 0; i < m; i++) {
			printf("%5d", vect[i]);
		}
		std::cout << std::endl;
	}
	//getter and setter
	void Matrix::setMatrix(int m, int n, bool isRandom) {
		matrix.resize(m);
		for (int i = 0; i < m; i++) {
			matrix[i].resize(n);
		}
		if (isRandom) {
			srand(time(NULL));
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					int randomValue = rand() % 100 + 1;
					matrix[i][j] = randomValue;
				}
			}
		}
		else {
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					std::cout << "A[" << i + 1 << "]"<<"["<<j+1<<"]="; std::cin >> matrix[i][j];
				}
			}
		}
	}
	std::vector<std::vector<int>> Matrix::getMatrix() {
		return matrix;
	}
}

matrix::Matrix* createMatrix(int m, int n, bool isRandom) {
	return new matrix::Matrix(m, n, isRandom);
}
void	destroyMatrix(matrix::Matrix* matrix) {
	delete matrix;
}