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


using namespace std;



LRESULT CALLBACK WindowProc(  _In_ HWND   hwnd,  _In_ UINT   uMsg,  _In_ WPARAM wParam,  _In_ LPARAM lParam)
{
    if(uMsg == WM_DESTROY)
    {
        PostQuitMessage(0);
    }
    return 0;
    DefWindowProc(hwnd,uMsg,wParam,lParam);
}
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE prevInstance,LPSTR cmd,int nCmdShow)
{
    WNDCLASSEX windowsclass;
    ZeroMemory(&windowsclass, sizeof(WNDCLASSEX));
    windowsclass.cbSize = sizeof(WNDCLASSEX);
    windowsclass.hbrBackground = (HBRUSH)COLOR_WINDOW;
    windowsclass.hInstance = hInstance;
    windowsclass.lpfnWndProc = WindowProc;
    windowsclass.lpszClassName = "MainWindow";
    windowsclass.style = CS_HREDRAW | CS_VREDRAW;
    RegisterClassEx(&windowsclass);

    HWND windowHandle = CreateWindow("MainWindow", "DircectX Tute!", WS_OVERLAPPEDWINDOW, 100,100,800,600,NULL,NULL,hInstance,0);

    if(!windowHandle)
        return -1;

    ShowWindow(windowHandle, nCmdShow);
    MSG message;
    while(GetMessage(&message,NULL,0,0))
    {
        DispatchMessage(&message);
    }
    return 0;
}
HWND CreateWindowExA(
  DWORD     dwExStyle,
  LPCSTR    lpClassName,
  LPCSTR    lpWindowName,
  DWORD     dwStyle,
  int       X,
  int       Y,
  int       nWidth,
  int       nHeight,
  HWND      hWndParent,
  HMENU     hMenu,
  HINSTANCE hInstance,
  LPVOID    lpParam
);
