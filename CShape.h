#pragma once
class CShape
{
public:
	virtual void Draw(CDC* pDC) = 0;
	virtual void Set1Point(CPoint p)=0;
	virtual void Set2Point(CPoint p)=0;
}; 

