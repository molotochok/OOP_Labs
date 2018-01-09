#pragma once
#include "Point.h"
namespace lab2 {
	class SectionC : public Point {
	protected:
		float length;
	public:
		SectionC(float, float, float, float);

		float GetLength() { return length; }
	};
}