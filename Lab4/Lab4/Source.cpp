#define _CRT_SECURE_NO_WARNINGS
#include"Algebraic_expressions.h"
#include<iostream>
using namespace std;

lab4::Algebraic_expressions ae1, ae2, temp;

void output(int x, string expression1, string expression2) {
	ae1.setExpression(expression1);
	ae2.setExpression(expression2);
	cout << "---------------------------------------------------\n";
	cout << "y1 postfix form: " << ae1.InfixToPostfix(ae1.getExpression()) << endl;
	cout << "y2 postfix form: " << ae2.InfixToPostfix(ae2.getExpression()) << endl;
	cout << "y1= " << ae1.EvaluatePostfix(x, ae1.InfixToPostfix(ae1.getExpression())) << endl;
	cout << "y2= " << ae2.EvaluatePostfix(x, ae2.InfixToPostfix(ae2.getExpression())) << endl;

	cout << "---------------------------------------------------\n";
	temp = -ae1;
	cout << "-y1: " << temp.getExpressionToShow() << endl;
	cout << "-y1= " << temp.EvaluatePostfix(x, temp.InfixToPostfix(temp.getExpression())) << endl;
	temp = -ae2;
	cout << "-y2: " << temp.getExpressionToShow() << endl;
	cout << "-y2= " << temp.EvaluatePostfix(x, temp.InfixToPostfix(temp.getExpression())) << endl;
	cout << "---------------------------------------------------\n";

	temp = ae1 + ae2;
	cout << "y1 + y2: " << temp.getExpressionToShow() << endl;
	cout << "y1 + y2= " << temp.EvaluatePostfix(x, temp.InfixToPostfix(temp.getExpression())) << endl;

	temp = ae1 - ae2;
	cout << "y1 - y2: " << temp.getExpressionToShow() << endl;
	cout << "y1 - y2= " << temp.EvaluatePostfix(x, temp.InfixToPostfix(temp.getExpression())) << endl;

	cout << "---------------------------------------------------\n";
}
void checkInput(lab4::Algebraic_expressions ae) {
	for (int i = 0; i < ae.getExpression().length(); i++) {
		if (!ae.isOperand(ae.getExpression()[i])) {
			if (!ae.isOperator(ae.getExpression()[i]))
				if (!ae.isBrackets(ae.getExpression()[i]))
					throw 2;
		}
	}
}

int main() {
	cout << "Created by Markiian Karpa IP-63" << endl;
	string expression1, expression2;
	bool exit2 = false;
	try {
		do {
			cin.ignore(cin.rdbuf()->in_avail(), '\n');
			cout << "y1: "; getline(cin, expression1);
			if (expression1.empty())
				throw 1;
			cout << "y2: "; getline(cin, expression2);
			if (expression2.empty())
				throw 1;

			int x;
			cout << "x= "; cin >> x;
			if (!cin)
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				throw 3;
			}

			output(x, expression1, expression2);

			//Check if inpput is right
			checkInput(ae1);
			checkInput(ae2);

			char decision;
			bool exit1 = false;
			do {
				cout << "Continue? (Y/N) "; cin >> decision;
				if (decision == 'n' || decision == 'N') {
					exit1 = true;
					exit2 = true;
				}
				else if (decision == 'y' || decision == 'Y') {
					exit1 = true;
				}
			} while (!exit1);
		} while (!exit2);
	}
	catch (int a) {
		switch (a) {
			case 1:	 cout << "y" << " can't be empty\n"; break;
			case 2:  cout << "y" << " should contain only: numbers or x and operators\n"; break;
			case 3:	 cout << "x should be a number\n"; break;
			default: cout << "Something wrong!\n"; break;
		}
	}
	system("pause");
	return 0;
}