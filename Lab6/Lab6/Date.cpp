#include "Date.h"
#include <iostream>

//Constructors
namespace lab6 {
	Date::Date() {
		this->day = 1;
		this->month = 1;
		this->year = 1;
	}
	Date::Date(int day, int month, int year) :day(day), month(month), year(year) {}

	//Methods
	void Date::setData(int day, int month, int year) {
		this->day = day;
		this->month = month;
		this->year = year;
	}
	//operators
	bool operator<(Date& left, Date& right) {
		if (left.getYear() < right.getYear()) {
			return true;
		}
		else if (left.getYear() == right.getYear()) {
			if (left.getMonth() < right.getMonth())
				return true;
			else if (left.getMonth() == right.getMonth()) {
				if (left.getDay() < right.getDay())
					return true;
			}
		}
		return false;
	}
	bool operator>(Date& left, Date& right) {
		if (left.getYear() > right.getYear()) {
			return true;
		}
		else if (left.getYear() == right.getYear()) {
			if (left.getMonth() > right.getMonth())
				return true;
			else if (left.getMonth() == right.getMonth()) {
				if (left.getDay() > right.getDay())
					return true;
			}
		}
		return false;
	}
	std::ostream& operator<<(std::ostream& os, Date& date) {
		os << date.getDay() << "d:" << date.getMonth() << "m:" << date.getYear() << "y";
		return os;
	}

	//getter and setter
	int Date::getDay() { return day; }
	int Date::getMonth() { return month; }
	int Date::getYear() { return year; }
	void Date::setDay(int day) { this->day = day; }
	void Date::setMonth(int month) { this->month = month; }
	void Date::setYear(int year) { this->year = year; }
}