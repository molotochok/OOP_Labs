#include "Time.h"
#include <iostream>

namespace lab6 {
	//Constructors
	Time::Time() {
		this->second = 0;
		this->minute = 0;
		this->hour = 0;
	}
	Time::Time(int second, int minute, int hour) :second(second), minute(minute), hour(hour) {}

	//Methods
	void Time::setData(int second, int minute, int hour) {
		this->second = second;
		this->minute = minute;
		this->hour = hour;
	}

	//operators
	bool operator<(Time& left, Time& right) {
		if (left.getHour() < right.getHour()) {
			return true;
		}
		else if (left.getHour() == right.getHour()) {
			if (left.getMinute() < right.getMinute())
				return true;
			else if (left.getMinute() == right.getMinute()) {
				if (left.getSecond() < right.getSecond())
					return true;
			}
		}
		return false;
	}
	bool operator>(Time& left, Time& right) {
		if (left.getHour() > right.getHour()) {
			return true;
		}
		else if (left.getHour() == right.getHour()) {
			if (left.getMinute() > right.getMinute())
				return true;
			else if (left.getMinute() == right.getMinute()) {
				if (left.getSecond() > right.getSecond())
					return true;
			}
		}
		return false;
	}
	std::ostream& operator<<(std::ostream& os, Time& time) {
		os << time.getSecond() << "s:" << time.getMinute() << "m:" << time.getHour() << "h";
		return os;
	}
	//getter and setter
	int Time::getSecond() { return second; }
	int Time::getMinute() { return minute; }
	int Time::getHour() { return hour; }
	void Time::setSecond(int second) { this->second = second; }
	void Time::setMinute(int minute) { this->minute = minute; }
	void Time::setHour(int hour) { this->hour = hour; }
}