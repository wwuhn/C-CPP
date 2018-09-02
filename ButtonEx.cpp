// ButtonEx.cpp : implementation file
//

#include "stdafx.h"
#include "Assistants.h"
#include "ButtonEx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ButtonEx

ButtonEx::ButtonEx()
{
	m_rgb = RGB(255,0,0);  //red
}

ButtonEx::~ButtonEx()
{

}
void ButtonEx::SetRect(CRect rc)
{
	m_rc = rc;
}
void ButtonEx::Draw(CPaintDC* pDC)
{
	pDC->FillSolidRect(m_rc, m_rgb);
}


BEGIN_MESSAGE_MAP(ButtonEx, CWnd)
	//{{AFX_MSG_MAP(ButtonEx)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// ButtonEx message handlers
int ButtonEx::MouseMove(CPoint pt)
{
	if(m_rc.PtInRect(pt))
	{
		m_rgb = RGB(0,0,255);
	}
	else
	{
		m_rgb = RGB(255,0,0);	
	}
	return 1;
}

int ButtonEx::LeftDown(CPoint pt)
{
	if(m_rc.PtInRect(pt))
	{
		m_rgb = RGB(0,255,0);
		return 1;
	}
	return 0;

}
int ButtonEx::LeftUp(CPoint pt)
{
	if(m_rc.PtInRect(pt))
	{
		m_rgb = RGB(255,0,0);
		return 1;
	}
	return 0;
}
