#include"SectionA.h"
#include<iostream>
namespace lab2 {
	SectionA::SectionA(float x1, float y1, float x2, float y2) : Point(x1, y1), length(sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2))) {};
}