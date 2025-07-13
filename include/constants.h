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
/*
struct TileMap
{
	static const std::map<TileEnum, char> tileMap;
};

const std::map<TileEnum, char> TileMap::tileMap
	{	
		{EMPTY, ' '},
		{WALL, 'O'},
		{DOOR, '+'},
		{CORRIDOR, '#'},
		{EDGE, '='}
	};*/