// Laba20.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "MathFuncsDll.h"

#define P 3.14159

using namespace std;

int main()
{
	double d, s, p;
	cout << "d = ";
	cin >> d;
	d /= 2;
	s = P * MathFuncs::MyMathFuncs::Pow(d, 2);
	p = 2 * P * d;
	cout << "S = " << s << endl;
	cout << "P = " << p << endl;
}
