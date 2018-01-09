#pragma once
#include "Point.h"
namespace lab2 {
	class SectionB : public Point {
	protected:
		float length;
	public:
		SectionB(float, float, float, float);

		float GetLength() { return length; }

	};
}