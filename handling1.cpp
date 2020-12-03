#define _AFXDLL
#include <afxwin.h>
#include <string.h>
#include "handing1.h"
// Вспомогательные член-данные
char str[80] ="Sample Output";
int X = 1, Y = 1;
// Декларирование карты откликов на сообщения
//#define _CRT_SECURE_NO_WARNINGS

// Реализация
BOOL CApp::InitInstance()
{
    m_pMainWnd = new CMainWin;
    m_pMainWnd->ShowWindow(SW_RESTORE);
    m_pMainWnd->UpdateWindow();
    return TRUE;
}
CMainWin::CMainWin()
{
    // Создать основное окно
    Create(0, "Обработка сообщений");
    
}
// Реализация карты сообщений главного окна
BEGIN_MESSAGE_MAP(CMainWin /* класс */,
    CFrameWnd /* базовый класс */)
    ON_WM_CHAR()
    ON_WM_PAINT()
    ON_WM_LBUTTONDOWN()
    ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()
// Реализация функций отклика на сообщения

afx_msg void CMainWin::OnChar(UINT ch, UINT count, UINT flags)
{
    X = Y = 1;
    
    wsprintf(str, "%c", ch);
    InvalidateRect(0);
}

afx_msg void CMainWin::OnPaint()
{
    // Создадим контекст устройства для обработки WM_PAINT
    CPaintDC dc(this);
    // Затираем текст и снова выводим (возможно уже другой текст)
    dc.TextOut(X, Y,   str,strlen(str));
   
}

afx_msg void CMainWin::OnLButtonDown(UINT flags, CPoint loc)
{
    // Запоминаем в переменных класса координаты
    // мыши и текст.

    // Затем посылаем сообщение WM_PAINT - его
    // обработчик выведет все на экран.

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
CApp App; // Единственный экземпляр приложения