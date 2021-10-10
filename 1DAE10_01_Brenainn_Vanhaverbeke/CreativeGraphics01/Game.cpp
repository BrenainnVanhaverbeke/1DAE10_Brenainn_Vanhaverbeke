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
	float left = 0;
	float bottom = 0;
	float rectWidth = g_WindowHeight;
	float rectHeight = g_WindowWidth - g_WindowHeight;
	float temp;
	SetColor(255, 0, 0);
	DrawRect(left, bottom, rectWidth, rectWidth);
	DrawArc(rectWidth, bottom, rectWidth, rectWidth, g_Pi / 2, g_Pi);
	FillArc(left, bottom, 4, 4, 0, 2 * g_Pi);

	left += rectWidth;
	bottom += rectWidth;
	temp = rectWidth;
	rectWidth = rectHeight;
	rectHeight = temp - rectWidth;
	SetColor(0, 255, 0);
	DrawRect(left, bottom, rectWidth, rectWidth * -1);
	DrawArc(left, bottom - rectWidth, rectWidth, rectWidth, 0, g_Pi / 2);
	FillArc(left, bottom, 4, 4, 0, 2 * g_Pi);

	left += rectWidth;
	bottom -= rectWidth;
	temp = rectWidth;
	rectWidth = rectHeight;
	rectHeight = temp - rectWidth;
	SetColor(0, 0, 255);
	DrawRect(left, bottom, rectWidth * -1, rectWidth * -1);
	DrawArc(left - rectWidth, bottom, rectWidth, rectWidth, g_Pi * 1.5f, g_Pi * 2);
	FillArc(left, bottom, 4, 4, 0, 2 * g_Pi);

	left -= rectWidth;
	bottom -= rectWidth;
	temp = rectWidth;
	rectWidth = rectHeight;
	rectHeight = temp - rectWidth;
	SetColor(255, 255, 0);
	DrawRect(left, bottom, rectWidth * -1, rectWidth);
	DrawArc(left, bottom + rectWidth, rectWidth, rectWidth, g_Pi, g_Pi * 1.5f);
	FillArc(left, bottom, 4, 4, 0, 2 * g_Pi);

	left -= rectWidth;
	bottom += rectWidth;
	temp = rectWidth;
	rectWidth = rectHeight;
	rectHeight = temp - rectWidth;
	SetColor(255, 0, 255);
	DrawRect(left, bottom, rectWidth, rectWidth);
	DrawArc(left + rectWidth, bottom, rectWidth, rectWidth, g_Pi / 2, g_Pi);
	FillArc(left, bottom, 4, 4, 0, 2 * g_Pi);

	left += rectWidth;
	bottom += rectWidth;
	temp = rectWidth;
	rectWidth = rectHeight;
	rectHeight = temp - rectWidth;
	SetColor(0, 255, 255);
	DrawRect(left, bottom, rectWidth, rectWidth * - 1);
	DrawArc(left, bottom - rectWidth, rectWidth, rectWidth, 0, g_Pi / 2);
	FillArc(left, bottom, 4, 4, 0, 2 * g_Pi);

	left += rectWidth;
	bottom -= rectWidth;
	temp = rectWidth;
	rectWidth = rectHeight;
	rectHeight = temp - rectWidth;
	SetColor(255, 255, 255);
	DrawRect(left, bottom, rectWidth * -1, rectWidth * -1);
	DrawArc(left - rectWidth, bottom, rectWidth, rectWidth, g_Pi * 1.5f, g_Pi * 2);
	FillArc(left, bottom, 4, 4, 0, 2 * g_Pi);
}

void Update(float elapsedSec)
{
	// process input, do physics 

	// e.g. Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}
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