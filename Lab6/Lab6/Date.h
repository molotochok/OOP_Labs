#pragma once
#include<iostream>
namespace lab6 {
	class Date {
	private:
		int day;
		int month;
		int year;
	public:
		//Constructors
		Date();
		Date(int day, int month, int year);

		//Methods
		void setData(int day, int month, int year);

		//operators
		friend bool operator<(Date& left, Date& right);
		friend bool operator>(Date& left, Date& right);
		friend std::ostream& operator<<(std::ostream& os, Date& date);

		//getter and setter
		int  getDay();
		int  getMonth();
		int  getYear();
		void setDay(int day);
		void setMonth(int month);
		void setYear(int year);
	};
}