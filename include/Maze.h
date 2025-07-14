#pragma once
#include <array>
#include <string>
#include "constants.h"

constexpr int maxMazeSize = 200;

class Maze
{
private:


	int m_sizeX = 80;
	int m_sizeY = 25;

	std::array<std::array<TileEnum, maxMazeSize>, maxMazeSize> m_tiles;
	std::array<std::string, maxMazeSize> m_textTiles;

public:
	void Reset(int sizeX, int sizeY);
	void GenerateStringArray();
	const std::string GetLine(int y);
};

