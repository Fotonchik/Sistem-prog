#include<Windows.h>

LRESULT CALLBACK MainWinProc(HWND, UINT, WPARAM, LPARAM);
#define ID_MYBUTTON 1

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE,
	LPSTR , int ss)
{
	
	WNDCLASS ws;
	ws.style = 0;
	ws.lpfnWndProc = MainWinProc;
	ws.cbClsExtra = 0;
	ws.cbWndExtra = 0;
	ws.hInstance = hInst;
	ws.hIcon = NULL;
	ws.hCursor = NULL;
	ws.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	ws.lpszMenuName = NULL;
	ws.lpszClassName = "Exemple 4 MainWnd Class";
	if(!RegisterClass(&ws)) return FALSE;
	HWND hMainWnd = CreateWindow("Exemple 4 MainWnd Class", "EXAMPLE 4", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInst, NULL);
	if(!hMainWnd) return FALSE;
	ShowWindow(hMainWnd, ss);
	UpdateWindow(hMainWnd);
	MSG msg;
	while (GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
LRESULT CALLBACK MainWinProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	
	switch (msg) {
	case WM_CREATE:
		CreateWindow("button", "My button", WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
			5, 5, 100, 20, hwnd, (HMENU)ID_MYBUTTON, NULL, NULL);

		return 0;
	case WM_COMMAND:
		if ((HIWORD(wParam) == 0) && (LOWORD(wParam) == ID_MYBUTTON))
			MessageBox(hwnd, "You pressed my button", "MessageBox", MB_OK | MB_ICONWARNING);

		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);

}
