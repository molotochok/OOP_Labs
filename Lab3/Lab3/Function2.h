#pragma once
#include"Function.h"
namespace lab3 {
	class Function2 :public Function {
	protected:
		float y, z;
	public:
		Function2(float x, float y, float z);
		float calculate();
		void output(float);
	};
}