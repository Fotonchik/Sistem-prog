#include <afxwin.h>
// ����� ��������� ����
class CMainWin : public CFrameWnd {
public:
    CMainWin();
    // ������� ��������� ���������
    afx_msg void OnChar(UINT ch, UINT count, UINT flags);
    afx_msg void OnPaint();
    afx_msg void OnLButtonDown(UINT flags, CPoint Loc);
    afx_msg void OnRButtonDown(UINT flags, CPoint Loc);
    
    DECLARE_MESSAGE_MAP()
};
// ����� ����������
class CApp : public CWinApp {
public:
    BOOL InitInstance();
};