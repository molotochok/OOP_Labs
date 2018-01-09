#pragma once
#include<vector>

namespace matrix {
	class Matrix {
	private:
		std::vector<std::vector<int>> matrix;
		int m;
		int n;
	public:
		Matrix(int m, int n, bool isRandom = false);
		virtual std::vector<int> getSumInRows();
		virtual void outputMatrix();
		virtual void outputVector(std::vector<int> vect);
		//getter and setter
		virtual std::vector<std::vector<int>> getMatrix();
		virtual void setMatrix(int m, int n, bool isRandom);
	};
}
extern "C" {
	_declspec(dllexport) matrix::Matrix* createMatrix(int m, int n, bool isRandom);
	_declspec(dllexport) void	destroyMatrix(matrix::Matrix* matrix);
}