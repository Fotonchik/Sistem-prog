const int SPAN = 10;
#include<Windows.h>
#include<tchar.h>
#include<math.h>
#include "resource.h"


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
TCHAR WinName[] = _T("MainFrame");
HINSTANCE hInst;
int APIENTRY _tWinMain(HINSTANCE This, //���������� �������� ����������
	HINSTANCE Prev, //� ����������� �������� ������ 0
	LPTSTR cmd, //��������� ������
	int mode) //����� ����������� ����

{
	HWND hWnd; //���������� �������� ���� ���������
	MSG msg; //��������� ��� �������� ���������
	hInst = This;
	WNDCLASS wc;//����� ����
	//����������� ������ ����
	wc.hInstance = This;
	wc.lpszClassName = WinName; //��� ������ ����
	wc.lpfnWndProc = WndProc; //��� ������ ����
	wc.style = CS_HREDRAW | CS_VREDRAW; //����� ����
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); //����������� ������
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); //����������� ������

	wc.lpszMenuName = _T("menudemo"); //��� ����
	wc.cbClsExtra = 0; //��� �������������� ������ ������
	wc.cbWndExtra = 0; //��� �������������� ������ ����
	//���������� ���� ����� ������
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	if (!RegisterClass(&wc)) return 0;//����������� ������ ����
	//�������� ����
	hWnd = CreateWindow(WinName,//��� ������ ����
		_T("������ Windows-����������"),//��������� ����
		WS_OVERLAPPEDWINDOW, //����� ����
		CW_USEDEFAULT,//x
		CW_USEDEFAULT,//y ������� ����
		CW_USEDEFAULT,//Width
		CW_USEDEFAULT,//Height
		HWND_DESKTOP,//���������� ������������ ���������� ���
		NULL,//��� ����
		This,//���������� ����������
		NULL);//�������������� ���������� ���
	ShowWindow(hWnd, mode);//�������� ����

	UpdateWindow(hWnd);
	//���� ��������� ���������
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);//������� ���������� ����� ������� �������
		DispatchMessage(&msg);//�������� ��������� ������� WndProc()
	}
	return 0;

}


	LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		PAINTSTRUCT ps;
		HDC hdc;
		int mx, my;
		static double mod,vx,vy,xt,yt;
		static HDC memDC;
		static int x,y,cx,cy,scrx,scry;
		static HBITMAP hCircle;
		static bool play;
		static HPEN hPen;
		switch (message)
		{
		case WM_CREATE:
			hPen = CreatePen(PS_SOLID,4,RGB(255,0,0));
			hCircle = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP1));
			hdc = GetDC(hWnd);
			memDC = CreateCompatibleDC(hdc);

			SelectObject(memDC, hCircle);
			ReleaseDC(hWnd, hdc);
			break;
		
		case WM_SIZE:
			scrx = LOWORD(lParam);
			scry = HIWORD(lParam);
			x = (cx = scrx / 2) - 16;
			y = (cy = scry / 2) - 16;


			break;
		case WM_LBUTTONDOWN:
			if (!play)
			{

				mx = LOWORD(lParam);
				my = HIWORD(lParam);
				vx = mx - cx;
				vy = my - cy;
				mod = sqrt(vx * vx + vy * vy);

				vx = vx / mod;
				vy = vy / mod;

				hdc = GetDC(hWnd);
				SelectObject(hdc, hPen);
				MoveToEx(hdc, cx, cy, 0);
				LineTo(hdc, mx, my);
				LineTo(hdc, mx-(vx -vy)* SPAN, my-(vx + vy)* SPAN);
				MoveToEx(hdc, mx-(vx+vy)* SPAN, my-(vx -vy)* SPAN, 0);

				LineTo(hdc, mx, my);
				ReleaseDC(hWnd, hdc);
				play = true;
			}

			break;
		case WM_TIMER:

			hdc = GetDC(hWnd);
			BitBlt(hdc, x, y, 32, 32, NULL, 0, 0, PATCOPY);
			if (x + 31 > scrx || x < 1) vx = -vx;
			if (y + 31 > scry || y < 1) vy = -vy;
			xt += vx * 10;
			yt += vy * 10;
			x = int(xt + 0.5);
			y = int(yt + 0.5);
			BitBlt(hdc, x, y, 32, 32, memDC, 0, 0, SRCCOPY);

			ReleaseDC(hWnd, hdc);

			break;
		case WM_COMMAND:
			switch (LOWORD(wParam))
			{
				case ID_PLAY_BEGIN:
					SetTimer(hWnd,1,(int)(sqrt(double (cx*cx+cy*cy))/mod)*10,NULL);
					x = cx - 16;
					y = cy - 16;
					InvalidateRect(hWnd,NULL,TRUE);
					play = false;

					break;
				case IDM_EXIT:	DestroyWindow(hWnd); break;
				default: return DefWindowProc(hWnd, message, wParam, lParam);
			}
			break;


		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);

			BitBlt(hdc, x, y, 32, 32, memDC, 0, 0, SRCCOPY);
			EndPaint(hWnd, &ps);
			break;
		case WM_DESTROY:

			KillTimer(hWnd, 1);
			DeleteDC(memDC);
			DeleteObject(hPen);
			PostQuitMessage(0); break;
		default: return DefWindowProc(hWnd, message, wParam, lParam);
		}
		return 0;
	}