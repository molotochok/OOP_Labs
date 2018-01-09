#include<iostream>
#include "HanoiTower.h"
using namespace std;

HanoiTower::HanoiTower(HanoiTower& ht) : n(ht.n), t1(ht.t1), t2(ht.t2), t3(ht.t3) {};
HanoiTower::HanoiTower(int n) {
	for (int i = n; i >= 1; i--)
	{
		t1.push(i);
	}
}

void HanoiTower::outputStack(stack<int> t, char indexOfT)
{
	cout << endl;
	cout << "Tower " << indexOfT << " -> ";
	while (!t.empty())
	{
		cout << t.top() << " ";
		t.pop();
	}
	cout << endl;
}

int HanoiTower::isEqualNull(stack<int> t) {
	if (t.empty()) {
		return 999;
	}
	return t.top();
}

void HanoiTower::toh(int n, stack<int> &t1, stack<int> &t2, stack<int> &t3)
{
	int i, x, a, b;
	for (i = 0; i < (pow(2, n)); i++)
	{
		outputStack(t1, '1');
		outputStack(t2, '2');
		outputStack(t3, '3');
		cout << "-----------------------------------------";

		if (!t1.empty() && t1.top() == 1) {
			x = 1;
		}
		else if (!t2.empty() && t2.top() == 1) {
			x = 2;
		}
		else if (!t3.empty() && t3.top()) {
			x = 3;
		}

		if (i % 2 == 0)
		{
			if (x == 1)
			{
				t3.push(isEqualNull(t1));
				t1.pop();
			}
			else if (x == 2)
			{
				t1.push(isEqualNull(t2));
				t2.pop();
			}
			else if (x == 3)
			{
				t2.push(isEqualNull(t3));
				t3.pop();
			}
		}
		else
		{
			if (x == 1)
			{
				if (!t2.empty()) {
					a = t2.top();
					t2.pop();
				}
				else {
					a = 999;
				}
				if (!t3.empty()) {
					b = t3.top();
					t3.pop();
				}
				else {
					b = 999;
				}
				if (a < b && b != 999)
				{
					t3.push(b);
					t3.push(a);
				}
				else if (a > b && a != 999)
				{
					t2.push(a);
					t2.push(b);
				}
				else if (b == 999)
				{
					t3.push(a);
				}
				else if (a == 999)
				{
					t2.push(b);
				}
			}
			else if (x == 2)
			{
				if (!t1.empty()) {
					a = t1.top();
					t1.pop();
				}
				else {
					a = 999;
				}
				if (!t3.empty()) {
					b = t3.top();
					t3.pop();
				}
				else {
					b = 999;
				}
				if (a < b && b != 999)
				{
					t3.push(b);
					t3.push(a);
				}
				else if (a > b && a != 999)
				{
					t1.push(a);
					t1.push(b);
				}
				else if (b == 999)
				{
					t3.push(a);
				}
				else if (a == 999)
				{
					t1.push(b);
				}
			}
			else if (x == 3)
			{
				if (!t1.empty()) {
					a = t1.top();
					t1.pop();
				}
				else {
					a = 999;
				}
				if (!t2.empty()) {
					b = t2.top();
					t2.pop();
				}
				else {
					b = 999;
				}
				if (a < b && b != 999)
				{
					t2.push(b);
					t2.push(a);
				}
				else if (a > b && a != 999)
				{
					t1.push(a);
					t1.push(b);
				}
				else if (b == 999)
				{
					t2.push(a);
				}
				else if (a == 999)
				{
					t1.push(b);
				}
			}
		}
	}
	if (n % 2 == 0) {
		while (!t3.empty()) {
			t3.pop();
		}
	}
	else {
		while (!t2.empty()) {
			t2.pop();

		}
	}
}
//getter
stack<int> HanoiTower::getT1() {
	return t1;
}
stack<int> HanoiTower::getT2() {
	return t2;
}
stack<int> HanoiTower::getT3() {
	return t3;
}

//setter
void HanoiTower::setT1(stack<int> t1) {
	this->t1 = t1;
}
void HanoiTower::setT2(stack<int> t2) {
	this->t2 = t2;
}
void HanoiTower::setT3(stack<int> t3) {
	this->t3 = t3;
}