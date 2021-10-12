// Vanhaverbeke, Brenainn - 1DAE10

#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	std::cout << (-1 * g_SquareSide) << std::endl;
}

void Draw()
{
	ClearBackground(0.72f, 0.82f, 0.93f);
	//float offset = (float)((int)g_NrOfFrames % (int)g_WindowHeight + g_SquareSide);
	float offset{(float)((int)g_NrOfFrames % (int)(g_WindowHeight + g_SquareSide))};
	SetColor(g_Red);
	FillRect((-1 * g_SquareSide) + offset, (-1 * g_SquareSide) + offset, g_SquareSide, g_SquareSide);
	SetColor(g_Black);
	DrawRect((-1 * g_SquareSide) + offset, (-1 * g_SquareSide) + offset, g_SquareSide, g_SquareSide);
	SetColor(g_Blue);
	FillRect(g_WindowWidth - offset, g_WindowHeight- offset, g_SquareSide, g_SquareSide);
	SetColor(g_Black);
	DrawRect(g_WindowWidth - offset, g_WindowHeight - offset, g_SquareSide, g_SquareSide);
	SetColor(g_Green);
	FillRect((-1 * g_SquareSide) + offset, g_WindowHeight - offset, g_SquareSide, g_SquareSide);
	SetColor(g_Black);
	DrawRect((-1 * g_SquareSide) + offset, g_WindowHeight - offset, g_SquareSide, g_SquareSide);
	SetColor(g_Yellow);
	FillRect(g_WindowWidth - offset, (-1 * g_SquareSide) + offset, g_SquareSide, g_SquareSide);
	SetColor(g_Black);
	DrawRect(g_WindowWidth - offset, (-1 * g_SquareSide) + offset, g_SquareSide, g_SquareSide);
}

void Update(float elapsedSec)
{
	g_NrOfFrames++;
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
	//switch (key)
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
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
	////std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//switch (e.button)
	//{
	//case SDL_BUTTON_LEFT:
	//{
	//	//std::cout << "Left mouse button released\n";
	//	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
	//	break;
	//}
	//case SDL_BUTTON_RIGHT:
	//	//std::cout << "Right mouse button released\n";
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	//std::cout << "Middle mouse button released\n";
	//	break;
	//}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

#pragma endregion ownDefinitions