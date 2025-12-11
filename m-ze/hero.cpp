#include "hero.h"

//===========================================================================================
Hero::Hero() {}

//===========================================================================================
void Hero::move(char& input, const SHORT consoleX, const SHORT consoleY) {
    COORD curr = { x(), y() };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), curr);
    std::cout << " ";

    if (_kbhit()) {
        input = _getch();
        switch (input) {
            case UP:
                if (curr.Y > 0) {
                    setY(curr.Y - 1);
                }
                break;
            case LEFT:
                if (curr.X > 0) {
                    setX(curr.X - 1);
                }
                break;
            case DOWN:
                if (curr.Y < consoleY - 1) {
                    setY(curr.Y + 1);
                }
                break;
            case RIGHT:
                if (curr.X < consoleX - 1) {
                    setX(curr.X + 1);
                }
                break;
            default:
                break;
            }
    }

    curr.X = x();
    curr.Y = y();
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), curr);
    std::cout << body_;
}