#pragma once

#include "hero.h"
#include "map.h"
#include "position.h"
#include "constants.h"

#include <iostream>
#include <Windows.h>
#include <chrono>
#include <thread>
#include <conio.h>

COORD initConsole() {
    // set to fullscreen
    HWND consoleWindow = GetConsoleWindow();
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD coord;
    ShowWindow(consoleWindow, SW_MAXIMIZE);
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    coord.X = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    coord.Y = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    SetConsoleScreenBufferSize(hConsole, coord);

    // hide the cursor
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);

    // set the text color 
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    SetConsoleTextAttribute(hConsole, (csbi.wAttributes & 0xF0) | 10);

    return coord;
}

int main()
{
    COORD consoleDimensions = initConsole();
    Hero hero;
    char input = ' ';
    while (input != 'q') {
        hero.move(input, consoleDimensions.X, consoleDimensions.Y);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

 