#pragma once
namespace lab3 {
	class Function {
	protected:
		float x;
	public:
		Function(float);
		virtual float calculate() = 0;
		virtual void output(float) = 0;
	};
}