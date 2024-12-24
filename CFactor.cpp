#include "pch.h"
#include "CFactor.h"


CShape* CFactor::GetShape(int type)
{
    CShape* pShape = nullptr;
    if (type == 0) 
    {
        pShape = new CCircle;
    }
    else if(type == 1)
    {
        pShape = new CLine;
    }
    else if (type == 2)
    {
        pShape = new CRectangle;
    }
    else if (type == 3)
    {
        pShape = new CTriangle;
    }
    return pShape;
}
