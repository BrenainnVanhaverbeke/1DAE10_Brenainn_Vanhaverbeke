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

	// Put your own draw statements here
	SetColor(g_Red);
	float middleRadius = g_Radius * 0.66f;
	float innerRadius = g_Radius * 0.33f;
	float degrees = 0;
	float degrees45 = 45;
	float degrees30 = 30;
	float degrees60 = 60;
	float degreeShift = 90;
	Point2f point0 = GetCoordinatesFromRadian(g_Radius, DegreesToRadian(degrees + (degreeShift * 0)), g_Center.x, g_Center.y);
	Point2f point1 = GetCoordinatesFromRadian(innerRadius, DegreesToRadian(degrees30 + (degreeShift * 0)), g_Center.x, g_Center.y);
	Point2f point2 = GetCoordinatesFromRadian(middleRadius, DegreesToRadian(degrees45 + (degreeShift * 0)), g_Center.x, g_Center.y);
	Point2f point3 = GetCoordinatesFromRadian(innerRadius, DegreesToRadian(degrees60 + (degreeShift * 0)), g_Center.x, g_Center.y);
	Point2f point4 = GetCoordinatesFromRadian(g_Radius, DegreesToRadian(degrees + (degreeShift * 1)), g_Center.x, g_Center.y);
	Point2f point5 = GetCoordinatesFromRadian(innerRadius, DegreesToRadian(degrees30 + (degreeShift * 1)), g_Center.x, g_Center.y);
	Point2f point6 = GetCoordinatesFromRadian(middleRadius, DegreesToRadian(degrees45 + (degreeShift * 1)), g_Center.x, g_Center.y);
	Point2f point7 = GetCoordinatesFromRadian(innerRadius, DegreesToRadian(degrees60 + (degreeShift * 1)), g_Center.x, g_Center.y);
	Point2f point8 = GetCoordinatesFromRadian(g_Radius, DegreesToRadian(degrees + (degreeShift * 2)), g_Center.x, g_Center.y);
	Point2f point9 = GetCoordinatesFromRadian(innerRadius, DegreesToRadian(degrees30 + (degreeShift * 2)), g_Center.x, g_Center.y);
	Point2f point10 = GetCoordinatesFromRadian(middleRadius, DegreesToRadian(degrees45 + (degreeShift * 2)), g_Center.x, g_Center.y);
	Point2f point11 = GetCoordinatesFromRadian(innerRadius, DegreesToRadian(degrees60 + (degreeShift * 2)), g_Center.x, g_Center.y);
	Point2f point12 = GetCoordinatesFromRadian(g_Radius, DegreesToRadian(degrees + (degreeShift * 3)), g_Center.x, g_Center.y);
	Point2f point13 = GetCoordinatesFromRadian(innerRadius, DegreesToRadian(degrees30 + (degreeShift * 3)), g_Center.x, g_Center.y);
	Point2f point14 = GetCoordinatesFromRadian(middleRadius, DegreesToRadian(degrees45 + (degreeShift * 3)), g_Center.x, g_Center.y);
	Point2f point15 = GetCoordinatesFromRadian(innerRadius, DegreesToRadian(degrees60 + (degreeShift * 3)), g_Center.x, g_Center.y);
	DrawLine(point0, point1);
	DrawLine(point1, point2);
	DrawLine(point2, point3);
	DrawLine(point3, point4);
	DrawLine(point4, point5);
	DrawLine(point5, point6);
	DrawLine(point6, point7);
	DrawLine(point7, point8);
	DrawLine(point8, point9);
	DrawLine(point9, point10);
	DrawLine(point10, point11);
	DrawLine(point11, point12);
	DrawLine(point12, point13);
	DrawLine(point13, point14);
	DrawLine(point14, point15);
	DrawLine(point15, point0);
}

float DegreesToRadian(float degrees)
{
	return degrees * (g_Pi / 180);
}

Point2f GetCoordinatesFromRadian(float radius, float radian, float xOffset, float yOffset)
{
	float x = radius * (float)cos(radian);
	float y = radius * (float)sin(radian);
	return Point2f(x + xOffset, y + yOffset);
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