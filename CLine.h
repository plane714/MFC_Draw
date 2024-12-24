#pragma once
#include "CShape.h"
class CLine:public CShape
{
public:
	CLine();
	~CLine();
	void Set1Point(CPoint p);
	void Set2Point(CPoint p);
	void Draw(CDC* pDC);
	CPoint m_StartPoint;
	CPoint m_EndPoint;
};

