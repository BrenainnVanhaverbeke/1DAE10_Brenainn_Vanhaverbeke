// Vanhaverbeke, Brenainn - 1DAE10
// Note: To be able to draw a golden spiral, I had to resize the window to have a golden ratio.

#include "pch.h"

#include <iostream>
#include <string>
#include <ctime>

#include "Core.h"

int main(int argc, char* args[])
{
	// seed the pseudo random number generator
	srand(unsigned int(time(nullptr)));

	// Initialize SDL and OpenGL in core.cpp
	Initialize();

	// Event loop
	Run();

	// Clean up SDL and OpenGL in core.cpp
	Cleanup();

	return 0;
}