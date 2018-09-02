在VC中，通过控件工具箱，可以方便地插入原生控件，实现类、控件变量和方法。而想实现自绘控件及实现响应函数，需要稍微复杂一些。

1 新建工程：Assistants


图片描述(最多50字)
上述对话框确定后，勾选”基于对话框“，确定后生成以下头文件和实现文件：



图片描述(最多50字)
2 新建自绘控制类


图片描述(最多50字)
3 自绘命令按钮控件
3.1 控件属性和大小设置、绘制方法声明

// ButtonEx.h:

class ButtonEx
{
public:
void SetRect(CRect rc);
void Draw(CPaintDC* pDC);
Private:
CRect m_rc; //位置大小
COLORREF m_rgb; //背景颜色
};
3.2 控件大小设置、绘制方法实现

// ButtonEx.cpp:

ButtonEx::ButtonEx()
{
m_rgb = RGB(255,0,0); 
}
void ButtonEx::SetRect(CRect rc)
{
m_rc = rc;
}
void ButtonEx::Draw(CPaintDC* pDC)
{
pDC->FillSolidRect(m_rc, m_rgb);
}
3.3 在主类头文件中包含控件类头文件及控件类实例化

// AssistantsDlg.h : header file

#include "ButtonEx.h"
class CAssistantsDlg : public CDialog
{
public:
CAssistantsDlg(CWnd* pParent = NULL);
ButtonEx m_btn;
};
3.4 在主类实现文件中实现控件大小及绘制控件

// AssistantsDlg.cpp

BOOL CAssistantsDlg::OnInitDialog()
{
CDialog::OnInitDialog();
m_btn.SetRect(CRect(CPoint(100,100),CSize(100,25)));
return TRUE;
}
void CAssistantsDlg::OnPaint()
{
CPaintDC dc(this); // device context for painting
m_btn.Draw(&dc);
}
4 控件类鼠标方法的声明与实现
class ButtonEx
{
public:
……
int MouseMove(CPoint pt);	//鼠标移动
int LeftDown(CPoint pt);	//左键按下
int LeftUp(CPoint pt);	//左键弹起
……
};
// ButtonEx.cpp:

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
5 在主类中实现鼠标事件
// AssistantsDlg.h :

……
virtual BOOL OnInitDialog();
……
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
//}}AFX_MSG
DECLARE_MESSAGE_MAP()
};
// AssistantsDlg.cpp

BEGIN_MESSAGE_MAP(CAssistantsDlg, CDialog)
//{{AFX_MSG_MAP(CAssistantsDlg)
ON_WM_SYSCOMMAND()
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_WM_MOUSEMOVE()
ON_WM_LBUTTONDOWN()
ON_WM_LBUTTONUP()
ON_WM_ERASEBKGND()
//}}AFX_MSG_MAP
END_MESSAGE_MAP()
// AssistantsDlg.cpp :

void CAssistantsDlg::OnMouseMove(UINT nFlags, CPoint point)
{
m_btn.MouseMove(point);
Invalidate();
CDialog::OnMouseMove(nFlags, point);
}
BOOL CAssistantsDlg::OnEraseBkgnd(CDC* pDC)
{
return true;
}
void CAssistantsDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
if(m_btn.LeftDown(point))
{
Invalidate();
return;
}
CDialog::OnLButtonDown(nFlags, point);
}
void CAssistantsDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
if(m_btn.LeftUp(point))
{
Invalidate();
ShellExecute(this->m_hWnd, "open", "C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe", "http://web.chacuo.net/formatc", NULL, SW_SHOW);
//::ShellExecute(0,"open","rundll32.exe","shell32 Control_RunDLL intl.cpl",NULL,SW_SHOW);
return;
}
CDialog::OnLButtonUp(nFlags, point);
}
－End－
