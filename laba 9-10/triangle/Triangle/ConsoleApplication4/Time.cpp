#include <iostream>

#include "Time.h"

using namespace std;

Time::Time() {
	second = minute = hour = 0;
}

void Time::setTime(int inputHour, int inputMinute, int inputSecond) {
	second = inputSecond > 0 && inputSecond < 59 ? inputSecond : 0;
	minute = inputMinute > 0 && inputMinute < 59 ? inputMinute : 0;
	hour = inputHour > 0 && inputHour < 23 ? inputHour : 0;
}

void Time::printMilitary() {
	cout << (hour < 1 ? "0" : "") << hour << ":"
		<< (minute < 1 ? "0" : "") << minute << ":"
		<< (second < 1 ? "0" : "") << second;
}

void Time::printStandard() {
	cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
		<< (minute < 10 ? "0" : "") << minute << ":"
		<< (second < 10 ? "0" : "") << second
		<< (hour < 12 ? "AM" : " PM");
}
