#include "Triangle.h"
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

// Конструктор
Triangle::Triangle(Point _v1, Point _v2, Point _v3, const char* ident) : vl(_v1), v2(_v2), v3(_v3)
{
	char buf[16];
	objID = new char[strlen(ident) + 1];
	strcpy(objID, ident);
	count++;
	sprintf(buf, "Треугольник %d", count);
	name = new char[strlen(buf) + 1];
	strcpy(name, buf);
	a = sqrt((vl.x - v2.x) * (vl.x - v2.x) + (vl.y - v2.y) * (vl.y - v2.y));
	b = sqrt((v2.x - v3.x) * (v2.x - v3.x) + (v2.y - v3.y) * (v2.y - v3.y));
	c = sqrt((vl.x - v3.x) * (vl.x - v3.x) + (vl.y - v3.y) * (vl.y - v3.y));
	cout << "Constructor_1 for: " << objID << " (" << name << ")" << endl; 
}

// Конструктор пустого (нулевого) треугольника Triangle::Triangle(const char* ident)
Triangle::Triangle(const char* ident)
{
	char buf[16];
	objID = new char[strlen(ident) + 1];
	strcpy(objID, ident);
	count++;
	sprintf(buf, " %d", count);
	name = new char[strlen(buf) + 1];
	strcpy(name, buf);
	a = b = c = 0;
	cout << "Constructor_2 for: " << objID << " (" << name << ")" << endl; 
}

// Деструктор
Triangle::~Triangle()
{
	cout << "Destructor for: " << objID << endl;
	//delete[] objID;
	delete[] name;
}

// Показать объект
void Triangle::Show() const
{
	cout << name << ":";
	vl.Show();
	v2.Show();
	v3.Show();
	cout << endl;
}

// Показать стороны и площадь объекта
void Triangle::ShowSideAndArea() const
{
	double p = (a + b + c) / 2;
	double s = sqrt(p * (p - a) * (p - b) * (p - c));
	cout << " " << endl;
	cout << name << ":";
	cout.precision(4);
	cout << " a= " << setw(5) << a;
	cout << ", b= " << setw(5) << b;
	cout << ", c= " << setw(5) << c;
	cout << ":\ts= " << s << endl;
}
// Переместить объект на величину (dp.x. dp.у) 
void Triangle::Move(Point dp)
{
	vl += dp;
	v2 += dp;
	v3 += dp;
}

bool Triangle::operator>(const Triangle tria) const
{
	double p = (a + b + c) / 2;
	double s = sqrt(p * (p - a) * (p - b) * (p - c));
	double p1 = (tria.a + tria.b + tria.c) / 2;
	double s1 = sqrt(p1 * (p1 - tria.a) * (p1 - tria.b) * (p1 - tria.c));
	if (s > s1) return true;
	else
		return false;
}

Triangle::Triangle(const Triangle& tria) : vl(tria.vl), v2(tria.v2),
v3(tria.v3)
{
	cout << "Copy constructor for: " << tria.objID << endl;
	objID = new char[strlen(tria.objID) + strlen("копия") + 1];
	strcpy(objID, tria.objID);
	strcat(objID, "(копия)");
	name = new char[strlen(tria.name) + 1];
	strcpy(name, tria.name);
	a = tria.a;
	b = tria.b;
	c = tria.c;
}

Triangle& Triangle::operator =(const Triangle& tria)
{
	cout << "Assign operator: " << objID << " = " << tria.objID << endl; 
	if (&tria == this) return *this;
	delete[] name;
	name = new char[strlen(tria.name) + 1];
	strcpy(name, tria.name);
	a = tria.a; b = tria.b; c = tria.c;
	return *this;
}

// Определить, входит ли треугольник trial в треугольник tria2

bool TriaInTria(Triangle trial, Triangle tria2)
{
	Point vl = trial.Get_vl();
	Point v2 = trial.Get_v2();
	Point v3 = trial.Get_v3();
	return (vl.InTriangle(tria2) && v2.InTriangle(tria2) && v3.InTriangle(tria2));
	return true;
}