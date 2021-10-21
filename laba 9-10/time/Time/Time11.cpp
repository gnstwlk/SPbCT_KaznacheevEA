
#include <iostream>
#include "Time11.h"

using namespace std;
Time::Time()
{
	second = minute = hour = 0;
}
void Time::setTime(int inputHour, int inputMinute, int inputSecond)
{
	second = inputSecond > 0 && inputSecond < 59 ? inputSecond : 0;
	minute = inputMinute > 0 && inputMinute < 59 ? inputMinute : 0;
	hour = inputHour > 0 && inputHour < 23 ? inputHour : 0;
}
void Time::printMilitary()
{
	cout << (hour < 1 ? "0" : "") << hour << ":" << (minute < 1 ? "0" : "") << minute << ":" << (second < 1 ? "0" : "") << second;
}
void Time::printStandart()
{
	cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":" << (minute < 10 ? "0" : "") << minute<<":" << (second < 10 ? "0" : "") << second << (hour < 12 ? "AM" : "PM");
}
int main()
{
    setlocale(LC_ALL, "russian");
    Time t;
    cout << "начальное значение военного времени равно ";
    t.printMilitary();
    cout << endl << "начальное значение стандартного времени равно ";
    t.printStandart();
    t.setTime(13, 27, 6);
    cout << endl << endl << "военное время после settime равно ";
    t.printMilitary();
    cout << endl << "стандартное время после settime равно ";
    t.printStandart();
    t.setTime(99, 99, 99);
    cout << endl << endl << "после попытки неправильной установки: " << endl <<
        "военное время: ";
    t.printMilitary();
    cout << endl << "стандартное время: ";
    t.printStandart();
    cout << endl;
    return 0;
}