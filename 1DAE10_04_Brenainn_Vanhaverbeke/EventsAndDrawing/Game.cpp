// Vanhaverbeke, Brenainn - 1DAE10

#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	g_Rectangle = GenerateRectangle();
}

void Draw()
{
	ClearBackground();
	DrawRectangle();

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
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
	{
		if (IsClickInRectangle((float)e.x, (float)e.y))
		{
			g_RectangleClicked = true;
		}
		break;
	}
	case SDL_BUTTON_RIGHT:
		g_Rectangle = GenerateRectangle();
		g_RectangleClicked = false;
		break;
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

Rectf GenerateRectangle()
{
	float border{ 50 };
	float minimumWidth{ 60 };
	float minimumHeight{ 40 };
	float minX{ border };
	float maxX{ g_WindowWidth - minimumWidth - border };
	float minY{ border };
	float maxY{ g_WindowHeight - minimumHeight - border };
	float randomLeft{ GenerateRandomFloat(minX, maxX - minX) };
	float randomBottom{ GenerateRandomFloat(minY, maxY - minY) };
	float maxWidth{ maxX - randomLeft };
	float maxHeight{ maxY - randomBottom };
	float randomWidth{ GenerateRandomFloat(minimumWidth, maxWidth) };
	float randomHeight{ GenerateRandomFloat(minimumHeight, maxHeight) };
	return Rectf{ randomLeft, randomBottom, randomWidth, randomHeight };
}

void DrawRectangle()
{
	if (g_RectangleClicked)
		SetColor(g_Green);
	else
		SetColor(g_Grey);
	FillRect(g_Rectangle);
}

float GenerateRandomFloat(float min, float max)
{
	return (float)((rand() % (int)max) + min);
}

bool IsClickInRectangle(float mouseX, float mouseY)
{
	mouseY = g_WindowHeight - mouseY;
	bool inRectangle{ g_Rectangle.left <= mouseX && mouseX <= g_Rectangle.width + g_Rectangle.left };
	if (inRectangle)
		inRectangle = g_Rectangle.bottom <= mouseY && mouseY <= g_Rectangle.height + g_Rectangle.bottom;
	return inRectangle;
}

#pragma endregion ownDefinitions