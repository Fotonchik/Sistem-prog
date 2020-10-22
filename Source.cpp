#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<tchar.h>
#include<cmath>
#include "menudemo.h"
HBRUSH hBlueBrush, hGreenBrush, hRedBrush, hYellowBrush;
HPEN hBluePen, hRedPen;
int sw;
MSG Msg;
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	HWND hMainWnd;
	TCHAR szClassName[] = _T("menudemo");
	MSG msg;
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(wc));
	wc.cbSize = sizeof(wc);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = _T("menudemo");
	wc.lpszClassName = szClassName;
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	if (!RegisterClassExW(&wc)) {
		MessageBoxW(NULL, _T("Cannot registr class"), _T("Error"), MB_OK);
		return 0;
	}
	hMainWnd = CreateWindow(szClassName, _T("menudemo"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL,
		hInstance, NULL);

	if (!hMainWnd) {
		MessageBox(NULL, _T("Cannot create main window"), _T("Error"), MB_OK);
		return 0;
	}
	ShowWindow(hMainWnd, nCmdShow);
	while (GetMessage(&Msg, NULL, 0, 0)) {
		DispatchMessageW(&Msg);
	}
	return 0;
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	HDC hdc;
	PAINTSTRUCT ps;
	HMENU hPopupMenu;
	TCHAR str0[] = _T("Фон");
	TCHAR str1[] = _T("Синий");
	TCHAR str2[] = _T("Красный");
	TCHAR str3[] = _T("Выход");
	RECT rect;
	switch (uMsg) {
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case MI_BLUE:
			sw = 1;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case MI_RED:
			sw = 2;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case MI_EXIT:
			DestroyWindow(hWnd);
		}
		break;
	case WM_RBUTTONDOWN:
		hBlueBrush = CreateSolidBrush(RGB(100, 100, 255));
		hGreenBrush = CreateSolidBrush(RGB(255, 100, 100));
		hPopupMenu = CreatePopupMenu();
		AppendMenu(hPopupMenu, MF_STRING, MI_BLUE, str1);
		AppendMenu(hPopupMenu, MF_STRING, MI_RED, str2);
		AppendMenu(hPopupMenu, MF_SEPARATOR, 0, NULL);
		AppendMenu(hPopupMenu, MF_STRING, MI_EXIT, str3);
		GetWindowRect(hWnd, &rect);
		TrackPopupMenu(hPopupMenu, TPM_LEFTALIGN | TPM_LEFTBUTTON, Msg.pt.x, Msg.pt.y, 0, hWnd, NULL);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		if (sw == 1)
		{
			FillRect(hdc, &ps.rcPaint, hBlueBrush);
		}
		if (sw == 2)
		{
			FillRect(hdc, &ps.rcPaint, hGreenBrush);
		}

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return 0;

}