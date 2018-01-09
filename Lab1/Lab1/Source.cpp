#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stack>
#include"HanoiTower.h"
using namespace std;

int main()
{
	int n;
	cout << "Enter the number of disks: ";
	cin >> n;

	HanoiTower hanoiTower(n);

	stack<int> t1, t2, t3;
	t1 = hanoiTower.getT1();
	t2 = hanoiTower.getT2();
	t3 = hanoiTower.getT3();

	
	hanoiTower.toh(n, t1, t2, t3);

	hanoiTower.setT1(t1);
	hanoiTower.setT2(t2);
	hanoiTower.setT3(t3);

	HanoiTower hanoiTowerCopy(hanoiTower);
	
	cout << "\nhanoiTower:\n";
	hanoiTower.outputStack(hanoiTower.getT1(),'1');
	hanoiTower.outputStack(hanoiTower.getT2(), '2');
	hanoiTower.outputStack(hanoiTower.getT3(), '3');
	cout << "\nhanoiTowerCopy:\n";
	hanoiTowerCopy.outputStack(hanoiTowerCopy.getT1(), '1');
	hanoiTowerCopy.outputStack(hanoiTowerCopy.getT2(), '2');
	hanoiTowerCopy.outputStack(hanoiTowerCopy.getT3(), '3');

	system("pause");
	return 0;
}