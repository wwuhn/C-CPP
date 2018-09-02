// AssistantsDlg.h : header file
//
#include "ButtonEx.h"
#if !defined(AFX_ASSISTANTSDLG_H__4EE1FB1B_3D41_48FB_8721_54C75DF67EF8__INCLUDED_)
#define AFX_ASSISTANTSDLG_H__4EE1FB1B_3D41_48FB_8721_54C75DF67EF8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAssistantsDlg dialog

class CAssistantsDlg : public CDialog
{
// Construction
public:
	CAssistantsDlg(CWnd* pParent = NULL);	// standard constructor
	ButtonEx m_btn;
// Dialog Data
	//{{AFX_DATA(CAssistantsDlg)
	enum { IDD = IDD_ASSISTANTS_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAssistantsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAssistantsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
		afx_msg void OnMouseMove(UINT nFlags, CPoint point);

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);

	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ASSISTANTSDLG_H__4EE1FB1B_3D41_48FB_8721_54C75DF67EF8__INCLUDED_)
