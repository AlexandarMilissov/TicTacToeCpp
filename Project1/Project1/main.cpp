#include <d2d1_1.h>
#include <stdlib.h>
#include <Windows.h>
#include "Game.h"

using namespace std;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
<<<<<<< HEAD
	Game game(hInstance);
=======
    const auto pClassName = "Tic Tac Toe";

    WNDCLASSEX wc;
    wc.cbSize = sizeof(wc);
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = nullptr;
    wc.hCursor = nullptr;
    wc.hbrBackground = nullptr;
    wc.lpszMenuName = nullptr;
    wc.lpszClassName = pClassName;
    wc.hIconSm = nullptr;

    RegisterClassEx(&wc);
    int windowsSize = min(GetSystemMetrics(SM_CYSCREEN), GetSystemMetrics(SM_CXSCREEN)) * 0.4;
    const int buttonSize = (windowsSize - 40) / 3;

    HWND hWnd = CreateWindowEx( 0, pClassName, "Tic Tac Toe", WS_CAPTION | WS_MINIMIZEBOX | WS_BORDER | WS_SYSMENU, 0, 0, windowsSize, windowsSize, nullptr,nullptr, hInstance, nullptr);
    ShowWindow(hWnd,SW_SHOW);

    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            hwndButtons[(x * 3 + y)] = CreateWindowEx(0, "BUTTON", "", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10 + (y * (buttonSize + 10)), 10 + (x * (buttonSize + 10)), 0 + windowsSize/3, 0 + windowsSize/3, hWnd, (HMENU)(x*3 + y), (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);
        }
    }
    MSG msg;
    BOOL gResult;
    while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    if (gResult == -1)
    {
        return -1;
    }
    else
    {
        msg.wParam;
    }
>>>>>>> parent of 9f21629... buttons scale properly
}

