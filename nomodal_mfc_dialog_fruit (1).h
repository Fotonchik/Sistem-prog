#include "afxwin.h" 


//  ласс главного окна 
class CMainWin : public CFrameWnd {
public:
	//  онструктор немного изменен. 
	// Title Ч заголовок окна, HowShow Ч код показа окна 
	CMainWin();
	afx_msg void OnDialog();
	afx_msg void OnExit();
	afx_msg void OnHelp();

	DECLARE_MESSAGE_MAP()
};

//  ласс приложени€ 
class CApp : public CWinApp {
public:
	BOOL InitInstance();
};
//  ласс диалогового окна 
class CSampleDialog : public CDialog {
public:
	// DialogName Ч идентификатор диалога в ресурсах, 
	// Owner Ч окно-владелец (если NULL, то главное окно) 
	CSampleDialog(char* DialogName, CWnd* Owner) :
		CDialog(DialogName, Owner) {}
	BOOL OnInitDialog();
	afx_msg void OnRed();
	afx_msg void OnGreen();
	afx_msg void OnSelect();
	afx_msg void OnEditOK();
	DECLARE_MESSAGE_MAP()
};