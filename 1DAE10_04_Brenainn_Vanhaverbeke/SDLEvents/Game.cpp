// Vanhaverbeke, Brenainn - 1DAE10

#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground();
	DrawSquare();
	// Put your own draw statements here

}

void Update(float elapsedSec)
{

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
	std::cout << SDL_GetKeyName(key) << " was pressed.\n";
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//Point2f mousePos{ float(e.x), float(g_WindowHeight - e.y) };
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	float x = e.x - (g_SquareSide / 2);
	float y = (g_WindowHeight - e.y) - (g_SquareSide / 2);
	g_MouseClick = Point2f{ x, y };// +(g_SquareSide / 2)};
	/*std::cout << "SDL_MOUSEBUTTONDOWN\n";
	std::cout << "\t[" << e.x << ", " << e.y << "]\n";
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
		std::cout << "\tLeft mouse button went down.\n";
		break;
	case SDL_BUTTON_RIGHT:
		std::cout << "\tRight mouse button went down.\n";
		break;
	default:
		break;
	}
	std::cout << std::endl;*/
}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	std::cout << "SDL_MOUSEBUTTONUP\n\n";
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

void DrawSquare()
{
	SetColor(g_Red);
	FillRect(g_MouseClick, 10, 10);
}

#pragma endregion ownDefinitions