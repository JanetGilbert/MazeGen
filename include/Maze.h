#pragma once
#include <array>
#include <string>
#include <vector>
#include <memory>
#include "constants.h"
#include "../include/MazePrint.h"
#include "../include/Room.h"

class Maze
{
private:


	int m_sizeX = 80;
	int m_sizeY = 25;

	TileGrid m_tiles;

	MazePrint m_print;

	std::vector<std::shared_ptr<Room>> m_rooms;

	bool IsValid(int x, int y);
	bool AddRoom(int posX, int posY, int width, int height);
public:
	Maze();
	void Reset(int sizeX, int sizeY);

	// Convert to printable version.
	void ConvertMazeToStringArray();
	const std::string GetLine(int y);

	// Generate Maze
	void GenerateMaze(int sizeX, int sizeY, int minRoomSize, int maxRoomSize);

};

