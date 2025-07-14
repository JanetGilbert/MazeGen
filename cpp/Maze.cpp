#include "../include/Maze.h"
#include "../include/Constants.h"
#include <iostream>
using std::cout;

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

void Maze::ConvertMazeToStringArray()
{
	m_print.MakePrintable(m_sizeX, m_sizeY, m_tiles);
}

const std::string Maze::GetLine(int y)
{
	return m_print.GetLine(y);
}

bool Maze::IsValid(int x, int y)
{
	if (x < 0 || x >= m_sizeX || y < 0 || y >= m_sizeY)
	{
		return false;
	}

	if (m_tiles[x][y] != EMPTY)
	{
		return false;
	}

	return true;

}

bool Maze::AddRoom(int posX, int posY, int width, int height)
{
	bool placementValid = true;
	for (int x{ posX-1 }; x < posX + width + 1; ++x)
	{
		for (int y{ posY - 1 }; y < posY + height + 1; ++y)
		{
			if (!IsValid(x, y))
			{
				placementValid = false;
				break;
			}
		}

		if (!placementValid) break;
	}
	if (!placementValid) return false;

	for (int x{ posX }; x < posX + width; ++x)
	{
		for (int y{ posY }; y < posY + height; ++y)
		{
			if (y == posY ||
				y == posY + height - 1 ||
				x == posX ||
				x == posX + width - 1
				)
			{
				m_tiles[x][y] = WALL;
			}
			else
			{
				m_tiles[x][y] = FLOOR;
			}
		}
	}

	std::shared_ptr<Room> newRoom = std::make_shared<Room>(posX, posY, width, height);


	m_rooms.push_back(newRoom);
	return true;
}

void Maze::GenerateMaze(int sizeX, int sizeY, int minRoomSize, int maxRoomSize)
{
	Reset(sizeX, sizeY);

	// Add rooms.
	int numRooms{ 4 };
	//if (numRooms < 4) numRooms = 4;

	cout << "Num rooms:" << numRooms;

	for (int i{ 0 }; i < numRooms; ++i)
	{
		int tries = 5;

		while (tries > 0)
		{
			tries--;
			int roomX = std::rand() % sizeX;
			int roomY = std::rand() % sizeY;
			int roomWidth = std::max(std::rand() % maxRoomSize, minRoomSize);
			int roomHeight = std::max(std::rand() % maxRoomSize, minRoomSize);

			bool added = AddRoom(
				roomX,
				roomY,
				roomWidth,
				roomHeight);

			if (added) break;
		}
	}

}

Maze::Maze()
{
	Reset(m_sizeX, m_sizeY);
	std::srand(std::time({}));
}

