#include <d2d1_1.h>
#include <stdlib.h>
#include <Windows.h>

using namespace std;
#define button1 1

HWND hwndButtons[9];
char states[3][3];

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

        int code = LOWORD(wParam);
        test(hwndButtons[code]);
        int i = code / 3;
        int j = code % 3;


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
    wc.hbrBackground = CreateSolidBrush(RGB(255, 255, 255));;
    wc.lpszMenuName = nullptr;
    wc.lpszClassName = pClassName;
    wc.hIconSm = nullptr;

    int windowSize = min(GetSystemMetrics( SM_CXSCREEN ), GetSystemMetrics(SM_CYSCREEN))*0.4;
    int buttonSize = (windowSize - 55) / 3;

    RegisterClassEx(&wc);
    HWND hWnd = CreateWindowEx( 0, pClassName, "Tic Tac Toe", WS_CAPTION | WS_MINIMIZEBOX | WS_BORDER | WS_SYSMENU, 200, 200, windowSize, windowSize + 20, nullptr,nullptr, hInstance, nullptr);
    ShowWindow(hWnd,SW_SHOW);


    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            hwndButtons[i*3+j] = CreateWindowEx(0, "BUTTON", "X", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10 + i*(10 + buttonSize), 10 + j * (10 + buttonSize), buttonSize, buttonSize, hWnd, (HMENU)(i*3+j), (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);
            states[i][j] = ' ';
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
