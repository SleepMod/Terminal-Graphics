#include <windows.h>
#include <cmath>
#include "uinput.h"
#include "graphics.h"

// the project name itself is VidBuffers because that's the first thing it came to my mind
// dm me for any suggestion Zetah#1376

int main()
{
	// all the magic comes here

	Plasma(3);
	for (int i = 0; i < 10; i++)
	{
		Circle(60, 15, i, 37);
	}

	ConsoleCreateWindow(30, 10, 25, 5, 14);
	ResetPos();
	Sleep(INFINITE); // lol what
}