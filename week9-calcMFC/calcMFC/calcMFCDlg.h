
// calcMFCDlg.h : ͷ�ļ�
//

#pragma once


// CcalcMFCDlg �Ի���
class CcalcMFCDlg : public CDialogEx
{
// ����
public:
	CcalcMFCDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CALCMFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	double x;
	double y;
	double r;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};
