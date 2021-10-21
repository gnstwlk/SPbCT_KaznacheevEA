#define _CRT_SECURE_NO_WARNINGS
#ifndef TRIANGLE_H 
#define TRIANGLE_H
#include "Point.h"

class Triangle
{
public:
	Triangle(Point, Point, Point, const char*); // конструктор
	Triangle(const char*); // конструктор пустого (нулевого) треугольника
	~Triangle(); // деструктор
	Triangle(const Triangle&); // конструктор копирования 
	Triangle& operator =(const Triangle&);
	Point Get_vl() const
	{
		return vl;
	} // Получить значение vl
	Point Get_v2() const
	{
		return v2;
	} // Получить значение v2
	Point Get_v3() const
	{
		return v3;
	} // Получить значение v3
	char* GetName() const
	{
		return name;
	} // Получить имя объекта
	void Show() const; // Показать объект
	void ShowSideAndArea() const; // Показать стороны и площадь объекта
	void Move(Point);
	bool operator >(const Triangle tria) const;
	friend bool TriaInTria(Triangle, Triangle); // Определить, входит ли один треугольник во второй

public:
	static int count; // кол-во созданных объектов
private:
	char* objID; // идентификатор объекта
	char* name; // наименование треугольника
	Point vl, v2, v3; // вершины
	double a; // сторона, соединяющая vl и v2
	double b; // сторона, соединяющая v2 и v3
	double c; // сторона, соединяющая vl и v3
};
#endif //TRIANGLE_H
