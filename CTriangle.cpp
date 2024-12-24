#include "pch.h"
#include "CTriangle.h"

CTriangle::CTriangle()
{
	Point1.x = 0;
	Point1.y = 0;
	Point2.x = 0;
	Point2.y = 0;
	Point3.x = 0;
	Point3.y = 0;
}

CTriangle::CTriangle(CPoint p)
{
	Point1.x = 0;
	Point1.y = 0;
	Point2.x = 0;
	Point2.y = 0;
	Point3.x = 0;
	Point3.y = 0;
	Point1 = p;
}

CTriangle::~CTriangle()
{
}

void CTriangle::Draw(CDC* pDC)
{
	pDC->MoveTo(Point1);
	pDC->LineTo(Point2);
	pDC->LineTo(Point3);
	pDC->LineTo(Point1);

}

void CTriangle::Set1Point(CPoint p)
{
	Point1 = p;
}

void CTriangle::Set2Point(CPoint p)
{
	Point2 = p;
	Point3 = Set3Point(Point1, Point2);
}

void CTriangle::Set3Point()
{
}

double CTriangle::angle(CPoint Point1, CPoint Point2)
{
	double dx = Point2.x - Point1.x;
	double dy = Point2.y - Point1.y;
	return atan2(dy, dx);

}

CPoint CTriangle::Set3Point(CPoint Point1, CPoint Point2)
{
	int a = Point2.x - Point1.x;
	int b = Point2.y - Point1.y;
	double len = sqrt(a * a + b * b);
	double alpha = angle(Point1, Point2);
	double x = Point1.x + len * cos(alpha + 60 * 3.14159 / 180);
	double y = Point1.y + len * sin(alpha + 60 * 3.14159 / 180);
	CPoint P3(x, y);
	return P3;
}
