#include "pch.h"
#include "CCircle.h"
CCircle::CCircle():m_Radius(0)
{
	

}
CCircle::CCircle(CPoint p)
{
	m_StartPoint = p;

}
CCircle::~CCircle()
{
}

void CCircle::Draw(CDC* pDC)
{
	pDC->Ellipse(m_StartPoint.x- m_Radius, m_StartPoint.y- m_Radius, 
		m_StartPoint.x + m_Radius, m_StartPoint.y + m_Radius );
}

void CCircle::Set1Point(CPoint p)
{
	m_StartPoint = p;
}

void CCircle::Set2Point(CPoint p)
{
	int a = p.x - m_StartPoint.x;
	int b = p.y - m_StartPoint.y;
	m_Radius = sqrt(a * a + b * b);
}
