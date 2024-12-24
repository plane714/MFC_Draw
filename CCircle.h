#pragma once
#include "CShape.h"
class CCircle:public CShape
{
public:
	CCircle();
	CCircle(CPoint p);
	~CCircle();
	void Draw(CDC* pDC);
	void Set1Point(CPoint p);
	void Set2Point(CPoint p);
private:
	CPoint m_StartPoint;
	CPoint m_EndPoint;
	double m_Radius;

};

