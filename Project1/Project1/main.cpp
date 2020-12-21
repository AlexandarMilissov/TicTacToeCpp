#include <d2d1_1.h>
#include <stdlib.h>
#include <Windows.h>

using namespace std;
#define button1 1

HWND hwndButton;
void test(HWND hWnd)
{
    SetWindowTextA(hWnd,"hello");
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_CLOSE:
        PostQuitMessage(0);
        break;
    case WM_COMMAND:
    {
        if (LOWORD(wParam) == button1)
        {
            test(hwndButton);
        }
    }
    }
    return DefWindowProc(hWnd,msg,wParam,lParam);
}




int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
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
    HWND hWnd = CreateWindowEx( 0, pClassName, "Tic Tac Toe", WS_CAPTION | WS_MINIMIZEBOX | WS_BORDER | WS_SYSMENU, 200, 200, 1024, 720, nullptr,nullptr, hInstance, nullptr);
    ShowWindow(hWnd,SW_SHOW);
    hwndButton = CreateWindowEx(0,"BUTTON","X", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10, 10, 100, 100, hWnd, (HMENU) button1, (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);   

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
}

