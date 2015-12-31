
// helloMFCView.cpp : ChelloMFCView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "helloMFC.h"
#endif

#include "helloMFCDoc.h"
#include "helloMFCView.h"

#include "Plot2D.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ChelloMFCView

IMPLEMENT_DYNCREATE(ChelloMFCView, CView)

BEGIN_MESSAGE_MAP(ChelloMFCView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &ChelloMFCView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// ChelloMFCView 构造/析构

ChelloMFCView::ChelloMFCView()
{
	// TODO: 在此处添加构造代码

}

ChelloMFCView::~ChelloMFCView()
{
}

BOOL ChelloMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// ChelloMFCView 绘制

void ChelloMFCView::OnDraw(CDC* pDC)
{
	ChelloMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	Wave wave;
	wave.draw(pDC, 0,0,500,100,0.05);
	Heart heart;
	heart.draw(pDC, 0,100,500,500);
	Circles circles;
	circles.draw(pDC, 500,0,500,500);
}


// ChelloMFCView 打印


void ChelloMFCView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL ChelloMFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void ChelloMFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void ChelloMFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void ChelloMFCView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void ChelloMFCView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// ChelloMFCView 诊断

#ifdef _DEBUG
void ChelloMFCView::AssertValid() const
{
	CView::AssertValid();
}

void ChelloMFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

ChelloMFCDoc* ChelloMFCView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(ChelloMFCDoc)));
	return (ChelloMFCDoc*)m_pDocument;
}
#endif //_DEBUG


// ChelloMFCView 消息处理程序
