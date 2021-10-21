#ifndef POINT_H 
#define POINT_H


enum ORIENT
{
	LEFT, RIGHT, AHEAD, BEHIND, BETWEEN
};

class Triangle;

class Point
{
public:
	Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
	void Show() const;
	void operator +=(const Point&);
	Point operator +(const Point&);
	Point operator -(const Point&);
	double Length() const; 
	ORIENT Classify(const Point&, const Point&)const; 
	bool InTriangle(const Triangle&) const; 
	double x, y;
};
#endif //POINT_H
