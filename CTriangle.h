#pragma once
#include"CShape.h"
class CTriangle:public CShape
{
public:
	CTriangle();
	CTriangle(CPoint p);
	~CTriangle();
	void Draw(CDC* pDC);
	void Set1Point(CPoint p);
	void Set2Point(CPoint p);
private:
	void Set3Point();
	double angle(CPoint Point1, CPoint Point2);
	CPoint Set3Point(CPoint Point1, CPoint Point2);
	CPoint Point1;
	CPoint Point2;
	CPoint Point3;

};

