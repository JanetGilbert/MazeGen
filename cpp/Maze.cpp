#include "../include/Maze.h"
#include "../include/Constants.h"
#include <iostream>


void Maze::Reset(int sizeX, int sizeY)
{
	m_sizeX = sizeX;
	m_sizeY = sizeY;

	m_tiles[0].fill(EDGE);
	m_tiles[m_sizeX - 1].fill(EDGE);
	for (int x{ 1 }; x < m_sizeX - 1; ++x)
	{
		m_tiles[x].fill(EMPTY);
		m_tiles[x][0] = EDGE;
		m_tiles[x][m_sizeY-1] = EDGE;
	}
}

void Maze::GenerateStringArray()
{
	m_print.MakePrintable(m_sizeX, m_sizeY, m_tiles);
}

const std::string Maze::GetLine(int y)
{
	return m_print.GetLine(y);
}