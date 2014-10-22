// ListCtrlEx.cpp : 实现文件
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



// CListCtrlEx 消息处理程序




void CListCtrlEx::OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;

    if ( CDDS_PREPAINT == pNMCD->dwDrawStage )
    {
        *pResult = CDRF_NOTIFYITEMDRAW;
    }
    else if ( CDDS_ITEMPREPAINT == pNMCD->dwDrawStage )
    {
        COLORREF crText,crBk;
		//奇偶判断
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
        //设置选择项的颜色
		if( this->GetItemState(pNMCD->dwItemSpec, CDIS_SELECTED) ){
			crBk =RGB(75, 149, 229);//itunes//RGB(10, 36, 106);//RGB(0, 0, 64);
			crText = RGB(255,255,255);
			SetTextColor(crText);
			SetBkColor(crBk);
			*pResult = CDRF_NEWFONT;
		}
		if(LVIS_SELECTED == this->GetItemState(pNMCD->dwItemSpec,LVIS_SELECTED))
		{
			//清除选择状态，如果不清除的话，还是会显示出蓝色的高亮条
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
