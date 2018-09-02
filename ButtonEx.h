#if !defined(AFX_BUTTONEX_H__94D225B8_F95B_4B32_95CB_209C21221807__INCLUDED_)
#define AFX_BUTTONEX_H__94D225B8_F95B_4B32_95CB_209C21221807__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ButtonEx.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ButtonEx window

class ButtonEx : public CWnd
{
// Construction
public:
	ButtonEx();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ButtonEx)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~ButtonEx();
	void SetRect(CRect rc);
	void Draw(CPaintDC* pDC);
		int MouseMove(CPoint pt);	//鼠标移动
	int LeftDown(CPoint pt);	//左键按下
	int LeftUp(CPoint pt);	//左键弹起
private:
	CRect m_rc; //位置大小
	COLORREF m_rgb; //背景颜色
	// Generated message map functions
protected:
	//{{AFX_MSG(ButtonEx)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BUTTONEX_H__94D225B8_F95B_4B32_95CB_209C21221807__INCLUDED_)
