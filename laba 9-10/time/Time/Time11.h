#pragma once
class Time {
public:
	Time();
	void setTime(int, int, int);
	void printMilitary();
	void printStandart();
private:
	int hour;
	int minute;
	int second;
};
