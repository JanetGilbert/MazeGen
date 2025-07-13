#include "../include/Maze.h"
#include "../include/Constants.h"
#include <iostream>

const std::map<TileEnum, char> tileMap
{
	{EMPTY, ' '},
	{WALL, 'O'},
	{DOOR, '+'},
	{CORRIDOR, '#'},
	{EDGE, '='}
};

void Maze::Reset(int sizeX, int sizeY)
{
	m_sizeX = sizeX;
	m_sizeY = sizeY;

	m_tiles[0].fill(EDGE);
	m_tiles[m_sizeY - 1].fill(EDGE);
	for (int y{ 1 }; y < m_sizeY - 1; ++y)
	{
		m_tiles[y].fill(EMPTY);
		
	}
}

void Maze::GenerateStringArray()
{
	for (int y{ 0 }; y < m_sizeY; ++y)
	{
		m_textTiles[y].resize(m_sizeX, ' ');
		for (int x{ 0 }; x < m_sizeX; ++x)
		{
			try {
			//	std::cout << "x:" << x << " y:" << y << m_textTiles[y] << std::endl;
				m_textTiles[y][x] = tileMap.at(m_tiles[y][x]);
			}
			catch (const std::out_of_range& ex)
			{
				std::cout << "Tile does not exist" << std::endl;
			}
		}
	}
}

const std::string & Maze::GetLine(int y)
{
	return m_textTiles[y];
}