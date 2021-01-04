#include <limits>
int maxInt = std::numeric_limits<int>::max();
int minInt = std::numeric_limits<int>::min(); 


#include <d2d1_1.h>


#include <stdlib.h>

#include <Windows.h>
#include <time.h>
#include <iomanip>
#include <algorithm>
#include "resource.h"
#define IDB_BITMAP1                     101

using namespace std;

HWND Main;
HWND hwndButtons[9];

#define endGame 10000
#define draw 101
#define humanWin 102
#define computerWin 103

char states[3][3];

enum Player
{
    none = ' ',
    human = 'X',
    computer = 'O'
};
struct Move
{
    unsigned int x = 0;
    unsigned int y = 0;
};
bool checkWin(char c);
bool isTie();
Move minimax();
void VictoryScreen();

void test(int code)
{
    int i = code / 3;
    int j = code % 3;

    //bool exit = false;

    if (states[i][j] == Player::none)
    {
        states[i][j] = Player::human;
        SetWindowTextA(hwndButtons[code], (LPCSTR)"X");
        if (checkWin(Player::human))
        {
            PostMessage(Main, endGame, Player::human, 0);
            VictoryScreen();
        }
        if (isTie())
            PostMessage(Main, endGame, Player::none, 0);


        Move move = minimax();
        states[move.x][move.y] = Player::computer;
        SetWindowTextA(hwndButtons[move.x*3 + move.y],(LPCSTR)"O");

        if (checkWin(Player::computer))
            PostMessage(Main, endGame, Player::computer, 0);

        if (isTie())
            PostMessage(Main, endGame, Player::none, 0);
    }
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case endGame:
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                SetWindowTextA(hwndButtons[i * 3 + j], (LPCSTR)" ");
                states[i][j] = Player::none;
            }
        }
        return 0;
        break;
    }
    case WM_CLOSE:
    {
        PostQuitMessage(0);
        break;
    }
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
        if (states[i][0] == Player::none || states[i][1] == Player::none || states[i][2] == Player::none)
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
    int score = maxInt;
    Move move;

    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
        {

            if (states[i][j] == Player::none)
            {
                states[i][j] = Player::computer;

                int temp = maxSearch();


                if (temp < score)
                {
                    score = temp;
                    move.x = i;
                    move.y = j;
                }
                states[i][j] = Player::none;
            }
        }
    }

    return move;
}

int maxSearch()
{
    if (checkWin(Player::human)) { return 10; }
    else if (checkWin(Player::computer))
    {
        srand(time(NULL));
        int randomNumber = rand() % 15 + 1;
        if(randomNumber>10)
           return 10;
        else
            return -10;
    }
    else if (isTie()) { return 0; }

    int score = minInt;

    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
        {
            if (states[i][j] == Player::none)
            {
                states[i][j] = Player::human;
                score = max(score, minSearch());
                states[i][j] = Player::none;
            }
        }
    }

    return score;
}

int minSearch()
{
    if (checkWin(Player::human)) { return 10; }
    else if (checkWin(Player::computer)) { return -10; }
    else if (isTie()) { return 0; }

    int score = maxInt;

    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
        {
            if (states[i][j] ==Player::none)
            {
                states[i][j] = Player::computer;
                score = min(score, maxSearch());
                states[i][j] = Player::none;
            }
        }
    }

    return score;
}

void VictoryScreen(HINSTANCE hInstance)
{
     const auto Victory = "Victory screen";

    WNDCLASSEX wc = { 0 };
    wc.cbSize = sizeof(wc);
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = DefWindowProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = nullptr;
    wc.hCursor = nullptr;
    wc.hbrBackground = CreatePatternBrush(LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAP1)));
    wc.lpszMenuName = nullptr;
    wc.lpszClassName = Victory;
    wc.hIconSm = nullptr;

    RegisterClassEx(&wc);

    HWND hWnd = CreateWindowEx(0, Victory, "Congratulations",
        WS_CAPTION | WS_BORDER | WS_SYSMENU,
        200, 200, 480, 410,
        nullptr,nullptr, hInstance, nullptr);

    ShowWindow(hWnd,SW_SHOW);
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
    Main = CreateWindowEx( 0, pClassName, "Tic Tac Toe", WS_CAPTION | WS_MINIMIZEBOX | WS_BORDER | WS_SYSMENU, 200, 200, windowSize, windowSize + 20, nullptr,nullptr, hInstance, nullptr);
    ShowWindow(Main,SW_SHOW);


    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            hwndButtons[i*3+j] = CreateWindowEx(0, "BUTTON", "", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10 + i*(10 + buttonSize), 10 + j * (10 + buttonSize), buttonSize, buttonSize, Main, (HMENU)(i*3+j), (HINSTANCE)GetWindowLongPtr(Main, GWLP_HINSTANCE), NULL);
            states[i][j] = Player::none;
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
