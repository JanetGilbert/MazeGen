#pragma once
#include <map>

enum TileEnum
{
	EMPTY,
	WALL,
	DOOR,
	CORRIDOR,
	EDGE,
	FLOOR
};
constexpr int maxMazeSize = 200;


typedef std::array<std::array<TileEnum, maxMazeSize>, maxMazeSize> TileGrid;
