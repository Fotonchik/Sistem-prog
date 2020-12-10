#include "afxwin.h" 


// ����� �������� ���� 
class CMainWin : public CFrameWnd {
public:
	// ����������� ������� �������. 
	// Title � ��������� ����, HowShow � ��� ������ ���� 
	CMainWin();
	afx_msg void OnDialog();
	afx_msg void OnExit();
	afx_msg void OnHelp();

	DECLARE_MESSAGE_MAP()
};

// ����� ���������� 
class CApp : public CWinApp {
public:
	BOOL InitInstance();
};
// ����� ����������� ���� 
class CSampleDialog : public CDialog {
public:
	// DialogName � ������������� ������� � ��������, 
	// Owner � ����-�������� (���� NULL, �� ������� ����) 
	CSampleDialog(char* DialogName, CWnd* Owner) :
		CDialog(DialogName, Owner) {}
	afx_msg void OnRed();
	afx_msg void OnGreen();
	DECLARE_MESSAGE_MAP()
};