#pragma once
#include <map>

enum TileEnum
{
	EMPTY,
	WALL,
	DOOR,
	CORRIDOR,
	EDGE
};
constexpr int maxMazeSize = 200;


typedef std::array<std::array<TileEnum, maxMazeSize>, maxMazeSize> TileGrid;
