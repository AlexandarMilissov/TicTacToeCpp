#pragma once
#include <d2d1_1.h>
#include <stdlib.h>
#include <Windows.h>
#include "Game.h"

void Game::test(HWND hWnd)
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
LRESULT CALLBACK Game::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
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
Game::Game(HINSTANCE hInstance)
{
    player = false;

    const auto pClassName = "Tic Tac Toe";

    WNDCLASSEX wc;

    wc.cbSize = sizeof(wc);
    wc.style = 0;//CS_OWNDC;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = nullptr;
    wc.hCursor = nullptr;
    wc.hbrBackground = CreateSolidBrush(RGB(255, 255, 255));
    wc.lpszMenuName = nullptr;
    wc.lpszClassName = pClassName;
    wc.hIconSm = nullptr;
    RegisterClassEx(&wc);
    int windowsSize = min(GetSystemMetrics(SM_CYSCREEN), GetSystemMetrics(SM_CXSCREEN)) * 0.6;
    const int buttonSize = ((windowsSize - 55) / 3);

    HWND hWnd = CreateWindowEx(0, pClassName, "Tic Tac Toe", WS_CAPTION | WS_MINIMIZEBOX | WS_BORDER | WS_SYSMENU, 0, 0, windowsSize, windowsSize + 20, nullptr, nullptr, hInstance, nullptr);
    ShowWindow(hWnd, SW_SHOW);

    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            hwndButtons[(x * 3 + y)] = CreateWindowEx(0, "BUTTON", "", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10 + (y * (buttonSize + 10)), 10 + (x * (buttonSize + 10)), 0 + buttonSize, 0 + buttonSize, hWnd, (HMENU)(x * 3 + y), (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);
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
    }
    else
    {
        msg.wParam;
    }
}


