#include "../include/MazePrint.h"
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



void MazePrint::MakePrintable(int sizeX, int sizeY, TileGrid& tileGrid)
{
	m_sizeX = sizeX;
	m_sizeY = sizeY;

	for (int x{ 0 }; x < m_sizeX; ++x)
	{
		if (m_textTiles[x].length() != m_sizeY)
		{
			m_textTiles[x].resize(m_sizeY, tileMap.at(EMPTY));
		}

		for (int y{ 0 }; y < m_sizeY; ++y)
		{
			try {
				m_textTiles[x][y] = tileMap.at(tileGrid[x][y]);
			}
			catch (const std::out_of_range& ex)
			{
				std::cout << "Tile does not exist" << std::endl;
			}
		}
	}
}

const std::string MazePrint::GetLine(int y)
{
	std::string str(m_sizeX, tileMap.at(EMPTY));
	for (int x{ 0 }; x < m_sizeX; ++x)
	{
		str[x] = m_textTiles[x][y];
	}
	
	return str;
}