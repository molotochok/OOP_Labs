#pragma once
#include "Point.h"
namespace lab2 {
	class SectionA : public Point {
	protected:
		float length;
	public:
		SectionA(float, float, float, float);

		float GetLength() { return length; }
	};
}