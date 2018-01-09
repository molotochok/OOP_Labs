#pragma once
#include<string>
#include<stack>
#include<iostream>
#include<sstream>
using namespace std;
namespace lab4 {
	class Algebraic_expressions {
	private:
		string expression;

		//Private Methods
		//From infix to postfix helpful methods
		int isRightAssociative(char op);
		int getOperatorWeight(char op);
		int hasHigherPrecedence(char op1, char op2);

		//Evaluate postfix
		bool IsNumericDigit(char C);
		int PerformOperation(char operation, int operand1, int operand2);
		string ReplaceX(int x, string expression);

	public:
		//Constructor
		Algebraic_expressions(string expression);
		Algebraic_expressions();

		//Methods
		bool isOperand(char c);
		bool isOperator(char c);
		bool isBrackets(char c);
		string InfixToPostfix(string expression);
		int EvaluatePostfix(int x, string expression);
		string getExpressionToShow();

		//operators
		Algebraic_expressions operator-();
		Algebraic_expressions operator+(const Algebraic_expressions& ae);
		Algebraic_expressions operator-(Algebraic_expressions ae);
		//getters and setters
		string getExpression();
		void setExpression(string expression);
	};
}