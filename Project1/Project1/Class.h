#pragma once
#include <iostream>
#include <Windows.h>
#include <d2d1_1.h>

#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <wchar.h>
#include <math.h>

#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#include <wincodec.h>

class Class
{
public:
    LRESULT CALLBACK WindowProc(_In_ HWND   hwnd, _In_ UINT   uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam)
    {
        if (uMsg == WM_DESTROY)
        {
            PostQuitMessage(0);
        }
        return 0;
        DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    void RunMessageLoop()
    {
        MSG msg;

        while (GetMessage(&msg, NULL, 0, 0))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

};

