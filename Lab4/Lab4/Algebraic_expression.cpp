#include "Algebraic_expressions.h"
using namespace std;
namespace lab4 {
	bool Algebraic_expressions::isOperand(char c) {
		if (c >= '0' && c <= '9') return true;
		if (c == 'X' || c == 'x') return true;

		return false;
	}
	bool Algebraic_expressions::isOperator(char c) {
		if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
			return true;
		}
		return false;
	}
	bool Algebraic_expressions::isBrackets(char c) {
		return (c == '(' || c == ')') ? true : false;
	}
	int Algebraic_expressions::isRightAssociative(char op) {
		return (op == '^') ? true : false;
	}
	int Algebraic_expressions::getOperatorWeight(char op) {
		int weight = -1;
		switch (op) {
		case '+':
		case '-':
			weight = 1; break;
		case '*':
		case '/':
			weight = 2; break;
		case '^':
			weight = 3; break;
		}
		return weight;
	}
	int Algebraic_expressions::hasHigherPrecedence(char op1, char op2) {
		int op1Weight = getOperatorWeight(op1);
		int op2weight = getOperatorWeight(op2);

		if (op1Weight == op2weight) {
			if (isRightAssociative(op1))
				return false;
			else
				return true;
		}
		return op1Weight > op2weight ? true : false;
	}

	//Evaluate postfix
	bool Algebraic_expressions::IsNumericDigit(char C)
	{
		if (C >= '0' && C <= '9') return true;
		return false;
	}
	int Algebraic_expressions::PerformOperation(char operation, int operand1, int operand2)
	{
		try {
			if (operation == '+') return operand1 + operand2;
			else if (operation == '-') return operand1 - operand2;
			else if (operation == '*') return operand1 * operand2;
			else if (operation == '/') {
				try {
					if (operand2 == 0) {
						throw 1;
					}
					else {
						return operand1 / operand2;
					}
				}
				catch (int a) {
					cout << "You can't divide by zero\n";
					system("pause");
					exit(1);
				}
			}
			else if (operation == '^') {
				return pow(operand1, operand2);
			}
			else {
				throw 2;
			}
		}
		catch (...) {
			cout << "There are some problems with operands!!!\n";
			system("pause");
			exit(1);
		}
		return -1;
	}
	string Algebraic_expressions::ReplaceX(int x, string expression) {
		string result = "";
		for (int i = 0; i < expression.length(); i++) {
			if (expression[i] == 'x') {
				result += to_string(x);
			}
			else {
				result += expression[i];
			}
		}

		return result;
	}
	//Constructor
	Algebraic_expressions::Algebraic_expressions(string expression) :expression(expression) {};
	Algebraic_expressions::Algebraic_expressions() {
		expression = "";
	}

	//Methods
	string Algebraic_expressions::InfixToPostfix(string expression) { // To transfer from infix form to postfix
		stack<char> s;
		string postfix;
		for (int i = 0; i < expression.length(); i++) {
			if (expression[i] == ' ' || expression[i] == ',') continue;
			else if (isOperator(expression[i])) {
				while (!s.empty() && s.top() != '(' && hasHigherPrecedence(s.top(), expression[i])) {
					postfix += s.top();
					s.pop();
				}
				s.push(expression[i]);
			}
			else if (isOperand(expression[i])) {
				postfix += expression[i];
			}
			else if (expression[i] == '(') {
				s.push(expression[i]);
			}
			else if (expression[i] == ')') {
				while (!s.empty() && s.top() != '(') {
					postfix += s.top();
					s.pop();
				}
				s.pop();
			}
		}
		while (!s.empty()) {
			postfix += s.top();
			s.pop();
		}
		return postfix;
	}
	int Algebraic_expressions::EvaluatePostfix(int x, string expression)
	{
		stack<int> s;
		int i = 0;
		char ch;
		int val = expression[0] - '0';
		expression = ReplaceX(x, expression);
		while (i < expression.length()) {
			ch = expression[i];
			if (isdigit(ch)) {
				s.push(ch - '0');
			}
			else {
				int op1 = s.top();
				s.pop();
				int op2 = s.top();
				s.pop();
				val = PerformOperation(ch, op2, op1);
				s.push(val);
			}
			i++;
		}
		return val;
	}
	string Algebraic_expressions::getExpressionToShow() {
		string result = "";
		if (expression[0] != '0')
			result = expression;
		else {
			for (int i = 1; i < expression.length(); i++) {
				result += expression[i];
			}
		}
		return result;
	}

	//operators
	Algebraic_expressions Algebraic_expressions::operator-() {
		string expression;
		expression = "0-(" + this->expression + ")";
		Algebraic_expressions temp(expression);
		return temp;
	}
	Algebraic_expressions Algebraic_expressions::operator+(const Algebraic_expressions& ae) {
		Algebraic_expressions result;
		if (ae.expression[0] != '-')
			result.expression = this->expression + '+' + ae.expression;

		return result;
	}
	Algebraic_expressions Algebraic_expressions::operator-(Algebraic_expressions ae) {
		Algebraic_expressions result;
		Algebraic_expressions temp;
		temp = -ae;
		if (temp.expression[0] != '0') {
			result.expression = this->expression + '+' + temp.expression;
		}
		else {
			if (temp.expression[0] == '0') {
				string tempStr = "";
				for (int i = 1; i < temp.getExpression().length(); i++) {
					tempStr += temp.getExpression()[i];
				}
				result.expression = this->expression + tempStr;
			}
		}
		return result;
	}

	//getters and setters
	string Algebraic_expressions::getExpression() {
		return expression;
	}
	void Algebraic_expressions::setExpression(string expression) {
		this->expression = expression;
	}
}