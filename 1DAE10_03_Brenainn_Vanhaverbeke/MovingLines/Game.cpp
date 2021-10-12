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
	ClearBackground(0.39f, 0.39f, 0.66f);
	DrawLines();
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

void DrawLines()
{
	float offset = (float)(g_NrOfFrames % (int)g_WindowWidth);
	SetColor(g_White);
	DrawLine(0, g_WindowHeight - offset, g_WindowWidth, g_WindowHeight - offset);
	DrawLine(0, offset, g_WindowWidth, 0.0f + offset);
	DrawLine(g_WindowWidth - offset, 0, g_WindowWidth - offset, g_WindowHeight);
	DrawLine(offset, 0, offset, g_WindowHeight);
	SetColor(g_Yellow);
	DrawLine(offset, 0, g_WindowWidth, offset);
	DrawLine(g_WindowWidth, offset, g_WindowWidth - offset, g_WindowHeight);
	DrawLine(0, g_WindowHeight - offset, g_WindowWidth - offset, g_WindowHeight);
	DrawLine(0, g_WindowHeight - offset, offset, 0);
}

#pragma endregion ownDefinitions