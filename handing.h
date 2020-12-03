#include <afxwin.h>
// Класс основного окна
class CMainWin : public CFrameWnd {
public:
    CMainWin();
    // Функции обработки сообщений
    afx_msg void OnChar(UINT ch, UINT, UINT);
    afx_msg void OnPaint();
    afx_msg void OnLButtonDown(UINT flags, CPoint Loc);
    afx_msg void OnRButtonDown(UINT flags, CPoint Loc);
    // Вспомогательные член-данные
    char str[50];
    int nMouseX, nMouseY, nOldMouseX, nOldMouseY;
    char pszMouseStr[50];
    // Декларирование карты откликов на сообщения
    DECLARE_MESSAGE_MAP()
};
// Класс приложения
class CApp : public CWinApp {
public:
    BOOL InitInstance();
};