
// CListCtrlEx.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCListCtrlExApp:
// �йش����ʵ�֣������ CListCtrlEx.cpp
//

class CCListCtrlExApp : public CWinApp
{
public:
	CCListCtrlExApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCListCtrlExApp theApp;