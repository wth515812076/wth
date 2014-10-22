// ListCtrlEx.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CListCtrlEx.h"
#include "ListCtrlEx.h"


// CListCtrlEx

IMPLEMENT_DYNAMIC(CListCtrlEx, CListCtrl)

CListCtrlEx::CListCtrlEx()
{

}

CListCtrlEx::~CListCtrlEx()
{
}


BEGIN_MESSAGE_MAP(CListCtrlEx, CListCtrl)
	ON_NOTIFY_REFLECT(NM_CUSTOMDRAW, &CListCtrlEx::OnNMCustomdraw)
END_MESSAGE_MAP()



// CListCtrlEx ��Ϣ�������




void CListCtrlEx::OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

    if ( CDDS_PREPAINT == pNMCD->dwDrawStage )
    {
        *pResult = CDRF_NOTIFYITEMDRAW;
    }
    else if ( CDDS_ITEMPREPAINT == pNMCD->dwDrawStage )
    {
        COLORREF crText,crBk;
		//��ż�ж�
        if ( (pNMCD->dwItemSpec % 2) == 0 ){
            crText = RGB(0,0,0);//RGB(32,32,255);
            crBk =RGB(229,232,239);
        }
        else if ( (pNMCD->dwItemSpec % 2) == 1 ){
            crText = RGB(0,0,0);
            crBk = RGB(240,247,249);
        }
        else{
            crText = RGB(0,0,0);
            crBk = RGB(0,0,126);
        }
        
        // Store the color back in the NMLVCUSTOMDRAW struct.
		SetTextColor(crText);
		SetBkColor(crBk);
        //pNMCD->clrTextBk = crBk;
        //����ѡ�������ɫ
		if( this->GetItemState(pNMCD->dwItemSpec, CDIS_SELECTED) ){
			crBk =RGB(75, 149, 229);//itunes//RGB(10, 36, 106);//RGB(0, 0, 64);
			crText = RGB(255,255,255);
			SetTextColor(crText);
			SetBkColor(crBk);
			*pResult = CDRF_NEWFONT;
		}
		if(LVIS_SELECTED == this->GetItemState(pNMCD->dwItemSpec,LVIS_SELECTED))
		{
			//���ѡ��״̬�����������Ļ������ǻ���ʾ����ɫ�ĸ�����
			BOOL b = this->SetItemState(pNMCD->dwItemSpec,0,LVIS_SELECTED); 
			SetTextColor(crText);
			SetBkColor(crBk);
			*pResult = CDRF_NEWFONT;
            return;
        }
        *pResult = CDRF_NEWFONT;
        //*pResult = CDRF_DODEFAULT;
    }
}
