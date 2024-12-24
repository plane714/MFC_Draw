
// MFCApplication10View.cpp: CMFCApplication10View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication10.h"
#endif

#include "MFCApplication10Doc.h"
#include "MFCApplication10View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include"CFactor.h"


// CMFCApplication10View

IMPLEMENT_DYNCREATE(CMFCApplication10View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication10View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplication10View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(IDM_Circle, &CMFCApplication10View::OnCircle)
	ON_COMMAND(IDM_Line, &CMFCApplication10View::OnLine)
	ON_COMMAND(IDM_Rectangle, &CMFCApplication10View::OnRectangle)
	ON_COMMAND(IDM_Triangle, &CMFCApplication10View::OnTriangle)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()

// CMFCApplication10View 构造/析构

CMFCApplication10View::CMFCApplication10View() noexcept
{
	// TODO: 在此处添加构造代码
	m_Type = -1;
	pShape = nullptr;
	Is1Check = false;
	IsDraw = false;
	m_pMainFrame = nullptr;
}

CMFCApplication10View::~CMFCApplication10View()
{
}

BOOL CMFCApplication10View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication10View 绘图

void CMFCApplication10View::OnDraw(CDC* pDC)
{
	CMFCApplication10Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	int s = m_List.Size();
	if (s < 1)
	{
		return;
	}
	CBrush* pOldBrush = pDC->SelectObject(CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH)));
	for (int i = 1; i <= s; i++)
	{
		Node* pnode = m_List.Locat(i);
		if (pnode)
		{
			pnode->pShape->Draw(pDC);
		}
	}
	pDC->SelectObject(pOldBrush);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCApplication10View 打印


void CMFCApplication10View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplication10View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCApplication10View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCApplication10View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CMFCApplication10View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication10View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication10View 诊断

#ifdef _DEBUG
void CMFCApplication10View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication10View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication10Doc* CMFCApplication10View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication10Doc)));
	return (CMFCApplication10Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication10View 消息处理程序


void CMFCApplication10View::OnCircle()
{
	// TODO: 在此添加命令处理程序代码
	m_Type = 0;
}


void CMFCApplication10View::OnLine()
{
	// TODO: 在此添加命令处理程序代码
	m_Type = 1;
}


void CMFCApplication10View::OnRectangle()
{
	// TODO: 在此添加命令处理程序代码
	m_Type = 2;
}


void CMFCApplication10View::OnTriangle()
{
	// TODO: 在此添加命令处理程序代码
	m_Type = 3;
}


void CMFCApplication10View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (m_Type > -1)
	{
		CFactor mfactor;
		pShape = mfactor.GetShape(m_Type);
		if (pShape)
		{
			pShape->Set1Point(point);
			Is1Check = true;
		}

	}
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication10View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (Is1Check && pShape && IsDraw)
	{
		Node m_Node;
		m_Node.pShape = pShape;
		m_List.PushHead(m_Node);

		Is1Check = false;
		IsDraw = false;
	}
	CView::OnLButtonUp(nFlags, point);
}


void CMFCApplication10View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (Is1Check)
	{
		CDC* pDC = GetDC();
		pDC->SetROP2(R2_NOT);
		CBrush* p0ldBrush = pDC->SelectObject(CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH)));

		if (IsDraw)
		{
			pShape->Draw(pDC);
		}

		IsDraw = true;
		pShape->Set2Point(point);
		pShape->Draw(pDC);
		pDC->SelectObject(p0ldBrush);
		ReleaseDC(pDC);
	}
	CView::OnMouseMove(nFlags, point);
}


BOOL CMFCApplication10View::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (m_Type > -1);
	{

		HCURSOR hCursor = ::LoadCursor(NULL, IDC_CROSS);
		if (hCursor)
		{
			::SetCursor(hCursor);
			return TRUE;
		}
		return CView::OnSetCursor(pWnd, nHitTest, message);
	}
}
