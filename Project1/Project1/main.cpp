#include <d2d1_1.h>
#include <stdlib.h>
#define NOMINMAX 
#include <Windows.h>
#undef min
#include <limits>
#include <time.h>
#include <iomanip>
#include <algorithm>

using namespace std;
#define button1 1

HWND hwndButtons[9];
char states[3][3];
bool player = true;
bool computer;
struct Move
{
    unsigned int x = 0;
    unsigned int y = 0;
};

void test(int code)
{
    int i = code / 3;
    int j = code % 3;
    if (states[i][j] == ' ')
    {
        if (player)
        {
            states[i][j] = 'X';
            SetWindowTextA(hwndButtons[code], "X");
        }
        else
        {
            states[i][j] = 'O';
            SetWindowTextA(hwndButtons[code], "O");
        }
        player = !player;
    }
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
        test(code);


    }
    }
    return DefWindowProc(hWnd,msg,wParam,lParam);
}

bool isTie()
{
    for (unsigned int i = 0; i < 3; i++)
    {
        if (states[i][0] == ' ' || states[i][1] == ' ' || states[i][2] == ' ')
            return false;
    }
    return true;
}

bool checkWin(char space)
{
    for (unsigned int i = 0; i < 3; i++)
    {
        // Check horizontals
        if (states[i][0] == space && states[i][1] == space && states[i][2] == space)
            return true;

        // Check verticals
        if (states[0][i] == space && states[1][i] == space && states[2][i] == space)
            return true;
    }

    // Check diagonals
    if (states[0][0] == space && states[1][1] == space && states[2][2] == space)
        return true;

    if (states[0][2] == space && states[1][1] == space && states[2][0] == space)
        return true;

    return false;
}
int minSearch();
int maxSearch();


Move minimax()
{
    unsigned int score = -1;
    Move move;

    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
        {

            if (states[i][j] == ' ')
            {
                states[i][j] = 'O';

                int temp = maxSearch();


                if (temp < score)
                {
                    score = temp;
                    move.x = i;
                    move.y = j;
                }
                states[i][j] = ' ';
            }
        }
    }

    return move;
}

int maxSearch()
{
    if (checkWin('O')) { return 10; }
    else if (checkWin('X'))
    {
        srand(time(NULL));
        int randomNumber = rand() % 15 + 1;
        if(randomNumber>10)
           return 10;
        return -10;
    }
    else if (isTie()) { return 0; }

    int score = -2147483648;

    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
        {
            if (states[i][j] == ' ')
            {
                states[i][j] = 'X';
                score = max(score, minSearch());
                states[i][j] = ' ';
            }
        }
    }

    return score;
}

int minSearch()
{
    if (checkWin('X')) { return 10; }
    else if (checkWin('O')) { return -10; }
    else if (isTie()) { return 0; }

   int score = 2147483647;

    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
        {
            if (states[i][j] ==' ')
            {
                states[i][j] = 'O';
                score = min(score, maxSearch());
                states[i][j] = ' ';
            }
        }
    }

    return score;
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
            hwndButtons[i*3+j] = CreateWindowEx(0, "BUTTON", "", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10 + i*(10 + buttonSize), 10 + j * (10 + buttonSize), buttonSize, buttonSize, hWnd, (HMENU)(i*3+j), (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);
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
