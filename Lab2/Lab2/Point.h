#pragma once

namespace lab2 {
	class Point {
	protected:
		float x, y;
	public:
		// Inizialization constructor
		Point(float, float);

		float GetX() { return x; }
		float GetY() { return y; }
	};
}