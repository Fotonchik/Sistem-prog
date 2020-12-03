#define _AFXDLL
#include <afxwin.h>
#include <string.h>
#include "handing1.h"
// ��������������� ����-������
char str[80] ="Sample Output";
int X = 1, Y = 1;
// �������������� ����� �������� �� ���������
//#define _CRT_SECURE_NO_WARNINGS

// ����������
BOOL CApp::InitInstance()
{
    m_pMainWnd = new CMainWin;
    m_pMainWnd->ShowWindow(SW_RESTORE);
    m_pMainWnd->UpdateWindow();
    return TRUE;
}
CMainWin::CMainWin()
{
    // ������� �������� ����
    Create(0, "��������� ���������");
    
}
// ���������� ����� ��������� �������� ����
BEGIN_MESSAGE_MAP(CMainWin /* ����� */,
    CFrameWnd /* ������� ����� */)
    ON_WM_CHAR()
    ON_WM_PAINT()
    ON_WM_LBUTTONDOWN()
    ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()
// ���������� ������� ������� �� ���������

afx_msg void CMainWin::OnChar(UINT ch, UINT count, UINT flags)
{
    X = Y = 1;
    
    wsprintf(str, "%c", ch);
    InvalidateRect(0);
}

afx_msg void CMainWin::OnPaint()
{
    // �������� �������� ���������� ��� ��������� WM_PAINT
    CPaintDC dc(this);
    // �������� ����� � ����� ������� (�������� ��� ������ �����)
    dc.TextOut(X, Y,   str,strlen(str));
   
}

afx_msg void CMainWin::OnLButtonDown(UINT flags, CPoint loc)
{
    // ���������� � ���������� ������ ����������
    // ���� � �����.

    // ����� �������� ��������� WM_PAINT - ���
    // ���������� ������� ��� �� �����.

    wsprintf(str, "Left");
    X = loc.x;
    Y = loc.y;
    InvalidateRect(0);
}

afx_msg void CMainWin::OnRButtonDown(UINT flags, CPoint loc)
{
    wsprintf(str, "right");
    X = loc.x;
    Y = loc.y;
    InvalidateRect(0);
}
CApp App; // ������������ ��������� ����������