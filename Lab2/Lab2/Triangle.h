#pragma once
#include"SectionA.h"
#include"SectionB.h"
#include"SectionC.h"
namespace lab2 {
	class Triangle : public SectionA, public SectionB, public SectionC {
	private:
		float square = 0;
	public:
		Triangle(float, float, float, float, float, float);

		void CalculateSquare(float, float, float);
	};
}