#include <iostream>
#include "../include/BearLibTerminal.h"
#include "../include/Maze.h"

#include <windows.h>

Maze maze;

void DoLoop()
{
    int sizeX = 80;
    int sizeY = 25;
    std::string settings = "window: size=" + std::to_string(sizeX) + "x" +
        std::to_string(sizeY) + " ; window: alt - functions = true";

    std::cout << settings << std::endl;
    maze.Reset(sizeX, sizeY);
    maze.GenerateStringArray();

    terminal_open();
    terminal_set(settings.c_str());
    terminal_clear();
     for (int y{0}; y < sizeY; ++y)
     {
         const std::string line = maze.GetLine(y);
         terminal_print(0, y, line.c_str());
     }

     //terminal_print(1, 1, "Hello, BearLibTerminal!");
     //terminal_put(5, 5, 67);

    terminal_refresh();
    terminal_read();
    terminal_close();
}

int main() {


    DoLoop();
    return 0;
}

/*
int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
    DoLoop();
    return 0;
}*/

