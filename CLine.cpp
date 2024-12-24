#include "pch.h"
#include "CLine.h"

CLine::CLine()
{
	CPoint p(0, 0);
	m_StartPoint = p;
	m_EndPoint = p;
}

CLine::~CLine()
{
}

void CLine::Set1Point(CPoint p)
{
	m_StartPoint = p;
}

void CLine::Set2Point(CPoint p)
{
	m_EndPoint = p;
}

void CLine::Draw(CDC* pDC)
{
	pDC->MoveTo(m_StartPoint);
	pDC->LineTo(m_EndPoint);
}
