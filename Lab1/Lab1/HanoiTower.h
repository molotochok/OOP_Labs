#pragma once
#include <stack>
using namespace std;

class HanoiTower {
private:
	int n;
	std::stack<int> t1;
	std::stack<int> t2;
	std::stack<int> t3;

	//Methods
	int isEqualNull(stack<int> t);

public:
	HanoiTower(int);
	HanoiTower(HanoiTower&);
	//~HanoiTower();
	void toh(int, stack<int>&, stack<int>&, stack<int>&);
	void outputStack(stack<int>, char);

	//Getter
	stack<int> getT1();
	stack<int> getT2();
	stack<int> getT3();
	//Setter
	void setT1(stack<int>);
	void setT2(stack<int>);
	void setT3(stack<int>);

};