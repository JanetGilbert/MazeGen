#include <iostream>
#include "../include/BearLibTerminal.h"

#include <windows.h>
/*int main() {
    

    terminal_open();
    terminal_set("window: size=80x25; window: alt-functions=true");
    terminal_print(1, 1, "Hello, BearLibTerminal!");
    terminal_put(5, 5, 67);
    terminal_refresh();
    terminal_read();
    terminal_close();
	return 0;
}	
*/

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
    terminal_open();
    terminal_set("window: size=80x25; window: alt-functions=true");
    terminal_print(1, 1, "Hello, BearLibTerminal!");
    terminal_put(5, 5, 67);
    terminal_refresh();
    terminal_read();
    terminal_close();
    return 0;
}