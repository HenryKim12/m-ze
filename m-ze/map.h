#pragma once

#include <iostream>
#include <vector>
#include <Windows.h>
#include <chrono>
#include <conio.h>

class Map {
public:
    Map(const SHORT consoleX, const SHORT consoleY);

    std::vector<std::vector<char>> map() { return map_; }

private:
    std::vector<std::vector<char>> map_;
};
