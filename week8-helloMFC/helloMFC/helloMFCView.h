
// helloMFCView.h : ChelloMFCView ��Ľӿ�
//

#pragma once


class ChelloMFCView : public CView
{
protected: // �������л�����
	ChelloMFCView();
	DECLARE_DYNCREATE(ChelloMFCView)

// ����
public:
	ChelloMFCDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~ChelloMFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // helloMFCView.cpp �еĵ��԰汾
inline ChelloMFCDoc* ChelloMFCView::GetDocument() const
   { return reinterpret_cast<ChelloMFCDoc*>(m_pDocument); }
#endif

