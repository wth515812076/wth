
// CListCtrlExDlg.h : ͷ�ļ�
//

#pragma once
#include "listctrlex.h"


// CCListCtrlExDlg �Ի���
class CCListCtrlExDlg : public CDialogEx
{
// ����
public:
	CCListCtrlExDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CLISTCTRLEX_DIALOG };

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
	CListCtrlEx m_List;
};
