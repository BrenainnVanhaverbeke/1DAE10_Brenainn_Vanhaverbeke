// Vanhaverbeke, Brenainn - 1DAE10

#include "pch.h"
#include "Game.h"
#include <time.h>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	srand(int(time(nullptr)));
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	Rectf rectangle = GetRandomRectangle();
	SetColor(GetRandomColour());
	FillRect(rectangle);
	SetColor(GetRandomColour());
	DrawRect(rectangle);
}

Rectf GetRandomRectangle()
{
	float left = GetRandomInRange(g_DefaultOffset, g_WindowWidth - g_DefaultOffset * 2);
	float bottom = GetRandomInRange(g_DefaultOffset, g_WindowHeight - g_DefaultOffset * 2);
	float widthRemainder = g_WindowWidth - left - g_DefaultOffset;
	float heightRemainder = g_WindowHeight - bottom - g_DefaultOffset;
	float width = (float)((int)GetRandomInRange(left, widthRemainder) % (int)widthRemainder);
	float height = (float)((int)GetRandomInRange(bottom, heightRemainder) % (int)heightRemainder);
	return Rectf(left, bottom, width, height);
}

Color4f GetRandomColour()
{
	float r = GetRandomInRange(0.0f, 255.0f) / 255.0f;
	float g = GetRandomInRange(0.0f, 255.0f) / 255.0f;
	float b = GetRandomInRange(0.0f, 255.0f) / 255.0f;
	float a = 1;
	return Color4f(r, g, b, a);
}

float GetRandomInRange(float min, float max)
{
	return (float)(rand() % (int)((max)) + min);
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