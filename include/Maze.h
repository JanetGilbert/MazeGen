#pragma once
#include <array>
#include <string>
#include "constants.h"
#include "../include/MazePrint.h"

class Maze
{
private:


	int m_sizeX = 80;
	int m_sizeY = 25;

	TileGrid m_tiles;

	MazePrint m_print;

public:
	void Reset(int sizeX, int sizeY);

	// Convert to printable version.
	void GenerateStringArray();
	const std::string GetLine(int y);
};

