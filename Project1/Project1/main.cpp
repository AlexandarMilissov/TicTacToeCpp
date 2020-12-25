#include <d2d1_1.h>
#include <stdlib.h>
#include <Windows.h>

using namespace std;

HWND hwndButtons[9];

bool player = false;

void test(HWND hWnd)
{
    if (player)
    {
        SetWindowTextA(hWnd, "0");
    }
    else
    {
        SetWindowTextA(hWnd, "X");
    }
    player = !player;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_CLOSE:
        {
            PostQuitMessage(0);
            break;
        }
        case WM_COMMAND:
        {
            int  x = LOWORD(wParam);
            test(hwndButtons[x]);
            break;
        }
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
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
}

