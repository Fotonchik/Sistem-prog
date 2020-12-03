#include <afxwin.h>
// Класс основного окна
class CMainWin : public CFrameWnd {
public:
    CMainWin();
    // Функции обработки сообщений
    afx_msg void OnPaint();
    afx_msg void OnDestroy();
    afx_msg void OnTimer(UINT ID);
    char str[50];
    DECLARE_MESSAGE_MAP()
};
// Класс приложения
class CApp : public CWinApp {
public:
    BOOL InitInstance();
};