#pragma once
#include <array>
#include "constants.h"

constexpr int maxMazeSize = 200;

class Maze
{
private:


	int m_sizeX;
	int m_sizeY;

	std::array<std::array<TileType, maxMazeSize>, maxMazeSize> m_tiles;

public:
	void Clear();
};

