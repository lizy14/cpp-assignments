
// helloMFCView.cpp : ChelloMFCView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &ChelloMFCView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// ChelloMFCView ����/����

ChelloMFCView::ChelloMFCView()
{
	// TODO: �ڴ˴���ӹ������

}

ChelloMFCView::~ChelloMFCView()
{
}

BOOL ChelloMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// ChelloMFCView ����

void ChelloMFCView::OnDraw(CDC* pDC)
{
	ChelloMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	Wave wave;
	wave.draw(pDC, 0,0,500,100,0.05);
	Heart heart;
	heart.draw(pDC, 0,100,500,500);
	Circles circles;
	circles.draw(pDC, 500,0,500,500);
}


// ChelloMFCView ��ӡ


void ChelloMFCView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL ChelloMFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void ChelloMFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void ChelloMFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
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


// ChelloMFCView ���

#ifdef _DEBUG
void ChelloMFCView::AssertValid() const
{
	CView::AssertValid();
}

void ChelloMFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

ChelloMFCDoc* ChelloMFCView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(ChelloMFCDoc)));
	return (ChelloMFCDoc*)m_pDocument;
}
#endif //_DEBUG


// ChelloMFCView ��Ϣ�������
