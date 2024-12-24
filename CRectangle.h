#pragma once
#include"CShape.h"
class CRectangle:public CShape
{
public:
	CRectangle();
	CRectangle(CPoint p);
	~CRectangle();
	void Set1Point(CPoint p);
	void Set2Point(CPoint p);
	void Draw(CDC* pDC);
private:
	CPoint m_LeftTop;
	CPoint m_RightBot;
};

