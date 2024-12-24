#include "pch.h"
#include "CRectangle.h"

CRectangle::CRectangle()
{
	m_LeftTop.x = 0;
	m_LeftTop.y = 0;
	m_RightBot.x = 0;
	m_RightBot.y = 0;//ÉèÖÃ³õÊ¼µã

}

CRectangle::CRectangle(CPoint p)
{
	m_LeftTop.x = 0;
	m_LeftTop.y = 0;
	m_RightBot.x = 0;
	m_RightBot.y = 0;
	m_LeftTop = p;
}

CRectangle::~CRectangle()
{
}

void CRectangle::Set1Point(CPoint p)
{
	m_LeftTop = p;
}

void CRectangle::Set2Point(CPoint p)
{
	m_RightBot = p;
}

void CRectangle::Draw(CDC* pDC)
{
	pDC->Rectangle(m_LeftTop.x, m_LeftTop.y, m_RightBot.x, m_RightBot.y);
}
