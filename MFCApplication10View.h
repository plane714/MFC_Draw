
// MFCApplication10View.h: CMFCApplication10View 类的接口
//

#pragma once
#include"Mainfrm.h"
#include"CCircle.h"
#include"CLine.h"
#include"CRectangle.h"
#include"CTriangle.h"
#include"C2300402317List.h"
#include"CShape.h"

class CMFCApplication10View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication10View() noexcept;
	DECLARE_DYNCREATE(CMFCApplication10View)

// 特性
public:
	CMFCApplication10Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMFCApplication10View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
private:
	int m_Type;
	C2300402317List m_List;
	CShape* pShape;
	bool Is1Check;
	bool IsDraw;
	CMainFrame* m_pMainFrame;

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCircle();
	afx_msg void OnLine();
	afx_msg void OnRectangle();
	afx_msg void OnTriangle();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
};

#ifndef _DEBUG  // MFCApplication10View.cpp 中的调试版本
inline CMFCApplication10Doc* CMFCApplication10View::GetDocument() const
   { return reinterpret_cast<CMFCApplication10Doc*>(m_pDocument); }
#endif

