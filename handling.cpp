#define _AFXDLL
#include <afxwin.h>
#include <string.h>
#include "handing.h"

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
    this->Create(0, "Обработка сообщений");
    // Инициализировать переменные объекта
    strcpy_s(str, "");
    strcpy_s(pszMouseStr, "");
    nMouseX = nMouseY = nOldMouseX = nOldMouseY = 0;
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

afx_msg void CMainWin::OnChar(UINT ch, UINT, UINT)
{
    sprintf_s(str, "%c", ch);
    // Посылаем сообщение WM_PAINT
    // с необходимостью стереть и обновить все окно
    this->InvalidateRect(0);
}

afx_msg void CMainWin::OnPaint()
{
    // Создадим контекст устройства для обработки WM_PAINT
    CPaintDC dc(this);
    // Затираем текст и снова выводим (возможно уже другой текст)
    dc.TextOut(nOldMouseX, nOldMouseY,
        " ", 0);
    dc.TextOut(nMouseX, nMouseY, pszMouseStr);
    dc.TextOut(1, 1, " ");
    dc.TextOut(1, 1, str);
}

afx_msg void CMainWin::OnLButtonDown(UINT, CPoint loc)
{
    // Запоминаем в переменных класса координаты
    // мыши и текст.

    // Затем посылаем сообщение WM_PAINT - его
    // обработчик выведет все на экран.

    nOldMouseX = nMouseX; nOldMouseY = nMouseY;
    strcpy_s(pszMouseStr, "Нажата левая кнопка");
    nMouseX = loc.x; nMouseY = loc.y;
    this->InvalidateRect(0);
}

afx_msg void CMainWin::OnRButtonDown(UINT, CPoint loc)
{

    // Запоминаем в переменных класса координаты
    // мыши и текст.

    // Затем посылаем сообщение WM_PAINT - его
    // обработчик выведет все на экран.

    nOldMouseX = nMouseX; nOldMouseY = nMouseY;
    strcpy_s(pszMouseStr, "Нажата правая кнопка");
    nMouseX = loc.x; nMouseY = loc.y;
    this->InvalidateRect(0);
}
CApp App; // Единственный экземпляр приложения