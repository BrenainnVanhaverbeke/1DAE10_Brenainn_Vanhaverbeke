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
	ClearBackground(0, 0, 0);
	DrawYellowishBar();
	DrawReddishBar();
}

void Update(float elapsedSec)
{
	g_NrFrames++;
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
// Define your own functions here#

void DrawYellowishBar()
{
	float height = g_DefaultHeight;
	float width = g_DefaultWidth;
	float maxWidth = g_WindowWidth - (g_DefaultOffset * 2) - (g_BorderThickness * 2);
	float bottom = g_WindowHeight - g_DefaultHeight - g_DefaultOffset;
	float left = g_DefaultOffset;
	SetColor(g_White);
	DrawRect(left, bottom, width, height, g_BorderThickness);
	height -= g_BorderThickness;
	width -= g_BorderThickness;
	bottom += g_BorderThickness / 2;
	left += g_BorderThickness / 2;
	SetColor(g_Yellowish);
	FillRect(left, bottom, g_YellowWidth, height);
	g_YellowWidth = (float)((int)(g_YellowWidth + 1) % (int)maxWidth);
}

void DrawReddishBar()
{
	float height = g_DefaultHeight;
	float width = g_DefaultWidth;
	float maxWidth = g_WindowWidth - (g_DefaultOffset * 2) - (g_BorderThickness * 2);
	float bottom = g_DefaultOffset;
	float left = g_DefaultOffset;
	float colourShift = ((255 - 120) * (g_RedWidth / maxWidth)) / 255;
	std::cout << colourShift << std::endl;
	SetColor(g_White);
	DrawRect(left, bottom, width, height, g_BorderThickness);
	height -= g_BorderThickness;
	width -= g_BorderThickness;
	bottom += g_BorderThickness / 2;
	left += g_BorderThickness / 2;
	SetColor((120.0f / 255.0f) + colourShift, 0, 0);
	FillRect(left, bottom, g_RedWidth, height);
	g_RedWidth = (float)((int)(g_RedWidth + ((int)g_NrFrames % 2)) % (int)maxWidth);
}

#pragma endregion ownDefinitions