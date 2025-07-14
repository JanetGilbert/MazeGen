#pragma once
#include <array>
#include <string>
#include "constants.h"


class MazePrint
{
private:


	int m_sizeX = 80;
	int m_sizeY = 25;


	std::array<std::string, maxMazeSize> m_textTiles;

public:
	void MakePrintable(int sizeX, int sizeY, TileGrid & tileGrid);
	const std::string GetLine(int y);
};

