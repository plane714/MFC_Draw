#pragma once
#include"CCircle.h"
#include"CLine.h"
#include"CRectangle.h"
#include"CTriangle.h"
class CFactor
{
public:
	CShape* GetShape(int type);
};

