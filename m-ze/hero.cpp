#include "hero.h"

class Map;
//===========================================================================================
Hero::Hero(const SHORT consoleX, const SHORT consoleY) : map_(Map{ consoleX, consoleY }) {}

//===========================================================================================
void Hero::move(char& input, const SHORT consoleX, const SHORT consoleY) {
    COORD curr = { x(), y() };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), curr);
    std::cout << " ";

    if (_kbhit()) {
        input = _getch();
        switch (input) {
            case UP:
                if (curr.Y > 0 && map_.map()[curr.Y - 1][curr.X] == ' ') {
                    setY(curr.Y - 1);
                }
                break;
            case LEFT:
                if (curr.X > 0 && map_.map()[curr.Y][curr.X - 1] == ' ') {
                    setX(curr.X - 1);
                }
                break;
            case DOWN:
                if (curr.Y < consoleY - 1 && map_.map()[curr.Y + 1][curr.X] == ' ') {
                    setY(curr.Y + 1);
                }
                break;
            case RIGHT:
                if (curr.X < consoleX - 1 && map_.map()[curr.Y][curr.X + 1] == ' ') {
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