#define _AFXDLL

#include <afxwin.h>
#include <string.h>
#include "dialog_mfc.h"
//#include "WinSDKVer.h"
#include "ids.h"
//#define _WIN32_WINNT_MAXVER     0x0601

char name[] = "SAMPLEDIALOG";

//-----------------------------------------------------— 

CMainWin::CMainWin()
{
	Create(NULL, "Demonstrate Dialog Boxes", WS_OVERLAPPEDWINDOW, rectDefault, NULL, "DialogMenu");
	if (!LoadAccelTable("DialogMenu"))
		MessageBox("Cannot Load Accelerators", "Error");
}
BOOL CApp::InitInstance()
{
	m_pMainWnd = new CMainWin;
	m_pMainWnd->ShowWindow(SW_RESTORE);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}
BEGIN_MESSAGE_MAP(CMainWin, CFrameWnd)
	ON_COMMAND(IDM_DIALOG, OnDialog)
	ON_COMMAND(IDM_HELP, OnHelp)
	ON_COMMAND(IDM_EXIT, OnExit)
END_MESSAGE_MAP()
afx_msg void CMainWin::OnDialog()
{
	CSampleDialog diagOb(name, this);
	diagOb.DoModal();
}
afx_msg void CMainWin::OnExit()
{
	int response;
	response = MessageBox("Quit the Program?", "Exit", MB_YESNO);
	if (response == IDYES)
		SendMessage(WM_CLOSE);
}
afx_msg void CMainWin::OnHelp()
{
	MessageBox("Dialog Demo",
		"Help");
}

BEGIN_MESSAGE_MAP(CSampleDialog, CDialog)
	ON_COMMAND(IDD_RED, OnRed)
	ON_COMMAND(IDD_GREEN, OnGreen)
	ON_COMMAND(IDD_SELFRUIT, OnSelect)
	ON_COMMAND(IDD_EDITOK, OnEditOK)
	ON_COMMAND(IDD_LB1, OnSelect)
END_MESSAGE_MAP()
BOOL  CSampleDialog::OnInitDialog()
{
	CDialog::OnInitDialog();
	CListBox* lbptr = (CListBox*)GetDlgItem(IDD_LB1);
	lbptr->AddString("Apple");
	lbptr->AddString("Orange");
	lbptr->AddString("Pear");
	lbptr->AddString("Grape");
	CEdit * ebptr = (CEdit*)GetDlgItem(IDD_EB1);
	ebptr->SetWindowText("Sample Text");
	return TRUE;
}

	afx_msg void CSampleDialog::OnRed()
	{
		MessageBox("Red", "Color Selected");
	}

	afx_msg void CSampleDialog::OnGreen()
	{
		MessageBox("Green", "Color Selected");
	}

	afx_msg void CSampleDialog::OnSelect()
	{
		CListBox* lbptr = (CListBox*)GetDlgItem(IDD_LB1);
		char str1[80], str2[80];
		int i;
		i = lbptr->GetCurSel();
		if (i == LB_ERR) wsprintf(str1,"No Selection");
		else {
			lbptr->GetText(i, str1);
			wsprintf(str2, " at index %d.", i);
			strcat_s(str1, str2);
		}
		MessageBox(str1, "Selection Made");
	}
	afx_msg void CSampleDialog::OnEditOK()
	{
		CEdit* ebptr = (CEdit*)GetDlgItem(IDD_EB1);
		char str[80]; int i;
		i = ebptr->GetWindowText(str, sizeof str -1);
		MessageBox(str, "Edit Box Contains");
	}

CApp App;