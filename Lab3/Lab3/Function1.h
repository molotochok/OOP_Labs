#pragma once
#include"Function.h"
namespace lab3 {
	class Function1 :public Function {
	protected:
		float y;
	public:
		Function1(float x, float y);
		float calculate();
		void output(float);
	};
}