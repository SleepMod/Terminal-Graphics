// imagine oop, more like raw C but whatever

// todo list
//
// make this libary actually universal, desist from winapi
// probably (but its a stupid idea and a waste of time,
// desist too from cmath lmao)
//
// image displaying
//
// allow the user to draw ANY char to the screen via hex/byte codes
//
// porting truecolor 24bits color instead of 16 colors

// long term ideas
//
// pseudo 3d support probably?
// soon audio ig
// and all the ideas you suggest me

#include <Windows.h>
#include <cmath>
#include <iostream>
#define PI 3.14159265358979323846

// Handle to the window console to apply any changes
// + variables
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
COORD coord;
COORD size;

// reset the console position to 0
void ResetPos()
{
	coord.X = 0;
	coord.Y = 0;
	SetConsoleCursorPosition(hConsole, coord);
}

// it resizes the buffer
void SetConsoleResolution(int w, int h)
{
	size.X = w;
	size.Y = h;

	SetConsoleScreenBufferSize(hConsole, size);
}

// create a funciton that allows safely place anyhwere our char
void Putchar(int x, int y, int color)
{
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(hConsole, coord);
	SetConsoleTextAttribute(hConsole, color);
	printf("%c", 219); // you see that 219? it stands for that ascii wall, change it with whatever you want
}

// draws a circle, imagine using sqrt
void Circle(int x, int y, int rad, int color)
{
	int times = 2 * PI * rad; // poor way of actually calculating the times ngl (mixing ints and floats? EVIL)
	for (double i = 0; i < times; i += 0.2)
	{
		Putchar(x + cos(i) * (rad + 7), y - sin(i) * rad, color);
	}
}

//some old plasma
void Plasma(int frame) // you can later loop the timer in a loop and get an animation
{
	// animation preset for 120x30 consoles.
	for (int x = 0; x < 120; x++)
	{
		for (int y = 0; y < 30; y++)
		{
			double color = (frame + (128.0 + (128.0 * sin(x / 16.0))
				+ 128.0 + (128.0 * sin(y / 8.0))
				+ 128.0 + (128.0 * sin((x - y) / 16.0))
				+ 128.0 + (128.0 * sin(sqrt((x * x + y * y)) / 8.0))
				) / 50);
			Putchar(x, y, (int)(color) % 16);
		}
	}
}

// well idk if this is worth, it works
void ConsoleCreateWindow(int x, int y, int w, int h, int color)
{
	for (int l = 0; l < h; l++)
	{
		for (int j = 0; j < w; j++)
		{
			Putchar(j + x, l + y, color);
		}
	}
}