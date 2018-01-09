#pragma once
#include<iostream>
namespace lab6 {
	class Time {
	private:
		int second;
		int minute;
		int hour;
	public:
		//Constructors
		Time();
		Time(int second, int minute, int hour);

		//Methods
		void setData(int second, int minute, int hour);

		//operators
		friend bool operator<(Time& left, Time& right);
		friend bool operator>(Time& left, Time& right);
		friend std::ostream& operator<<(std::ostream& os, Time& time);

		//getter and setter
		int  getSecond();
		int  getMinute();
		int  getHour();
		void setSecond(int second);
		void setMinute(int minute);
		void setHour(int hour);
	};
}