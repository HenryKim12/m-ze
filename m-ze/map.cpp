#include "map.h"

Map::Map(const SHORT consoleX, const SHORT consoleY) {
	std::vector<char> initialRow(consoleX, ' ');
	std::vector<std::vector<char>> map(consoleY, initialRow);

	for (SHORT x{}; x < 50; x++) {
		for (SHORT y{}; y < consoleY / 2; y++) {
			COORD coord{ x, y };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			std::cout << "X";
			map[y][x] = 'X';
		}
	}

	for (SHORT x = consoleX - 50; x < consoleX; x++) {
		for (SHORT y{}; y < consoleY / 2; y++) {
			COORD coord{ x, y };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			std::cout << "X";
			map[y][x] = 'X';
		}
	}

	for (SHORT y = consoleY / 2; y < consoleY; y++) {
		for (SHORT x{}; x < consoleX; x++) {
			COORD coord{ x, y };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			std::cout << "X";
			map[y][x] = 'X';
		}
	}
	map_ = map;
}
