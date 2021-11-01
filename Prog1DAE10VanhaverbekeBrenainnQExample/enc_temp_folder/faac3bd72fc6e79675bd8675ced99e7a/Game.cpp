// Vanhaverbeke, Brenainn - 1DAE10

#include "pch.h"
#include "Game.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	Generate();
	PrintRandomNumbers();
}

void Draw()
{
	ClearBackground();
}

void Update(float elapsedSec)
{
	g_TotalElapsedTime += elapsedSec;
	if (1 <= g_TotalElapsedTime)
	{
		Generate();
		PrintRandomNumbers();
		g_TotalElapsedTime = 0;
	}
}

void End()
{
	// free game resources here
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{

}

void OnKeyUpEvent(SDL_Keycode key)
{
	switch (key)
	{
	case SDLK_n:
		Generate();
		PrintRandomNumbers();
		break;
	}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

void Generate()
{
	do
	{
		g_Even = GenerateRandomNumber(0, 10);
		g_Odd = GenerateRandomNumber(0, 10);
		g_Any = GenerateRandomNumber(0, 10);
	} while (g_Even % 2 != 0 || g_Odd % 2 != 1);
}

void PrintRandomNumbers()
{
	printf("Even: %i, odd: %i, any: %i\n", g_Even, g_Odd, g_Any);
}

int GenerateRandomNumber(int min, int max)
{
	return (rand() % max) + min;
}

#pragma endregion ownDefinitions