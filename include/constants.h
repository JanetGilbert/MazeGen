#pragma once
#include <map>

enum TileType
{
	EMPTY,
	WALL,
	DOOR,
	CORRIDOR,
	EDGE
};

struct TileMap
{
	static const std::map<TileType, char> tileMap;
};

const std::map<TileType, char> TileMap::tileMap = 
	{	
		{EMPTY, ' '},
		{WALL, 'O'},
		{DOOR, '+'},
		{CORRIDOR, '#'},
		{EDGE, '='}
	};