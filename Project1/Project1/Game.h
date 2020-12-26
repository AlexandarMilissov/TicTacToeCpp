#pragma once
//#include <d2d1_1.h>
#include <stdlib.h>
#include <Windows.h>

class Game
{
public:
    Game(HINSTANCE hInstance);

    static HWND hwndButtons[9];
    static bool player;

    static void test(HWND hWnd);
    static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

};

