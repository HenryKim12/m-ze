#pragma once

#include "map.h"
#include "position.h"
#include "constants.h"

#include <iostream>
#include <Windows.h>
#include <chrono>
#include <conio.h>

class Hero {
public:
    Hero(const SHORT consoleX, const SHORT consoleY);

    SHORT x() { return pos_.x; }
    SHORT y() { return pos_.y; }
    void setX(const int x) { pos_.x = x; }
    void setY(const int y) { pos_.y = y; }

    void move(char& input, const SHORT consoleX, const SHORT consoleY);

private:
    Position pos_ = HERO_START;
    char body_ = HERO_BODY;
    int health_ = 100;
    Map map_;
};

