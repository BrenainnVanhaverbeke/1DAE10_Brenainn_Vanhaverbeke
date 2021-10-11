// Vanhaverbeke, Brenainn - 1DAE10

#include "pch.h"
#include "Game.h"
#include <iostream>

float rangeYoung;
float rangeOld;
float rangeOlder;
float rangeOldest;

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	std::cout << "% people playing games\n";
	std::cout << "In the range [0, 20]? ";
	std::cin >> rangeYoung;
	std::cout << "In the range [21, 40]? ";
	std::cin >> rangeOld;
	std::cout << "In the range [41, 60]? ";
	std::cin >> rangeOlder;
	std::cout << "Older than 60? ";
	std::cin >> rangeOldest;
}

void Draw()
{
	ClearBackground(50.0f / 255.0f, 20.0f / 255.0f, 50.0f / 255.0f);
	DrawFlag(0, 0);
	DrawCheckerPattern(0, 1);
	DrawHouse(0, 2);
	DrawColumnChart(1, 0);
	DrawPentagram(1, 1);
	DrawColorBand(1, 2);
}

void Update(float elapsedSec)
{
	 //process input, do physics 

	 //e.g. Check keyboard state
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

void DrawFlag(int column, int row)
{
	float totalWidth = g_DefaultWidth;
	float segmentWidth = totalWidth / 3;
	float offsetX = GetOffsetX(column);
	float offsetY = GetOffsetY(row);
	SetColor(g_Black);
	FillRect(offsetX + (segmentWidth * 0), offsetY, segmentWidth, g_DefaultHeight);
	SetColor(g_Yellow);
	FillRect(offsetX + (segmentWidth * 1), offsetY, segmentWidth, g_DefaultHeight);
	SetColor(g_Red);
	FillRect(offsetX + (segmentWidth * 2), offsetY, segmentWidth, g_DefaultHeight);
}

void DrawCheckerPattern(int column, int row)
{
	float offsetX = GetOffsetX(column);
	float offsetY = GetOffsetY(row);
	float segmentSide = g_DefaultHeight / 3;
	SetColor(g_White);
	FillRect(g_DefaultOffset, offsetY, g_DefaultHeight, g_DefaultHeight);
	SetColor(g_Black);
	FillRect(g_DefaultOffset + (segmentSide * 0), offsetY + (segmentSide * 0), segmentSide, segmentSide);
	FillRect(g_DefaultOffset + (segmentSide * 2), offsetY + (segmentSide * 0), segmentSide, segmentSide);
	FillRect(g_DefaultOffset + (segmentSide * 1), offsetY + (segmentSide * 1), segmentSide, segmentSide);
	FillRect(g_DefaultOffset + (segmentSide * 0), offsetY + (segmentSide * 2), segmentSide, segmentSide);
	FillRect(g_DefaultOffset + (segmentSide * 2), offsetY + (segmentSide * 2), segmentSide, segmentSide);
}

void DrawHouse(int column, int row)
{
	float offsetX = GetOffsetX(column);
	float offsetY = GetOffsetY(row);
	float height = g_DefaultHeight / 2;
	float width = g_DefaultWidth;
	Point2f triangleBottomLeft = Point2f(offsetX, offsetY + height);
	Point2f triangleBottomRight = Point2f(offsetX + width, offsetY + height);
	Point2f triangleTop = Point2f(offsetX + (width / 2), offsetY + height * 2);

	SetColor(g_Red);
	FillRect(g_DefaultOffset, offsetY, width, height);
	FillTriangle(triangleBottomLeft, triangleTop, triangleBottomRight);
}

void DrawColumnChart(int column, int row)
{
	float offsetX = GetOffsetX(column);
	float offsetY = GetOffsetY(row);
	float width = g_DefaultWidth / 8;
	float height = g_DefaultHeight;
	SetColor(g_Bar1);
	FillRect(offsetX + (width * 0), offsetY, width, height * (rangeYoung / 100));
	SetColor(g_Bar2);
	FillRect(offsetX + (width * 1), offsetY, width, height * (rangeOld / 100));
	SetColor(g_Bar3);
	FillRect(offsetX + (width * 2), offsetY, width, height * (rangeOlder / 100));
	SetColor(g_Bar4);
	FillRect(offsetX + (width * 3), offsetY, width, height * (rangeOldest / 100));
}

void DrawPentagram(int column, int row)
{
	Point2f center = Point2f(GetOffsetX(column) + g_DefaultWidth / 2, GetOffsetY(row) + g_DefaultHeight / 2);
	float fifthOfCircle = (g_Pi * 2) / 5;
	float radius = g_DefaultHeight / 2;
	Point2f p0 = GetCoordinatesFromRadian(radius, fifthOfCircle * 0, center.x, center.y);
	Point2f p1 = GetCoordinatesFromRadian(radius, fifthOfCircle * 1, center.x, center.y);
	Point2f p2 = GetCoordinatesFromRadian(radius, fifthOfCircle * 2, center.x, center.y);
	Point2f p3 = GetCoordinatesFromRadian(radius, fifthOfCircle * 3, center.x, center.y);
	Point2f p4 = GetCoordinatesFromRadian(radius, fifthOfCircle * 4, center.x, center.y);
	SetColor(g_Red);
	DrawLine(p0, p2);
	DrawLine(p2, p4);
	DrawLine(p4, p1);
	DrawLine(p1, p3);
	DrawLine(p3, p0);
}

void DrawColorBand(int column, int row)
{
	float offsetX = GetOffsetX(column);
	float offsetY = GetOffsetY(row);
	float barWidth = g_DefaultHeight / 4;
	float barHeight = g_DefaultHeight;
	
	SetColor(g_Yellow);
	FillRect(offsetX, offsetY, barWidth * 8 + 5, barHeight);
	
	offsetX += 5;
	offsetY += 5;
	barWidth -= 5;
	barHeight -= 10;

	SetColor(g_Red);
	FillRect(offsetX + (barWidth * 0), offsetY, barWidth, barHeight);
	SetColor(g_Green);
	FillRect(offsetX + (barWidth * 1), offsetY, barWidth, barHeight);
	SetColor(g_Blue);
	FillRect(offsetX + (barWidth * 2), offsetY, barWidth, barHeight);
	SetColor(g_Cyan);
	FillRect(offsetX + (barWidth * 3), offsetY, barWidth, barHeight);
	SetColor(g_Magenta);
	FillRect(offsetX + (barWidth * 4), offsetY, barWidth, barHeight);
	SetColor(g_Yellow);
	FillRect(offsetX + (barWidth * 5), offsetY, barWidth, barHeight);
	SetColor(g_Red);
	FillRect(offsetX + (barWidth * 6), offsetY, barWidth, barHeight);
	SetColor(g_Blue);
	FillRect(offsetX + (barWidth * 7), offsetY, barWidth, barHeight);
	SetColor(g_Red);
	FillRect(offsetX + (barWidth * 8), offsetY, barWidth, barHeight);
	SetColor(0, 0, 0, 0.5f);
	
	barHeight /= 2;
	FillRect(offsetX + (barWidth * 0), offsetY, barWidth, barHeight);
	FillRect(offsetX + (barWidth * 1), offsetY, barWidth, barHeight);
	FillRect(offsetX + (barWidth * 2), offsetY, barWidth, barHeight);
	FillRect(offsetX + (barWidth * 3), offsetY, barWidth, barHeight);
	FillRect(offsetX + (barWidth * 4), offsetY, barWidth, barHeight);
	FillRect(offsetX + (barWidth * 5), offsetY, barWidth, barHeight);
	FillRect(offsetX + (barWidth * 6), offsetY, barWidth, barHeight);
	FillRect(offsetX + (barWidth * 7), offsetY, barWidth, barHeight);
	FillRect(offsetX + (barWidth * 8), offsetY, barWidth, barHeight);
}

float GetOffsetX(int nthElement)
{
	float offset = g_DefaultOffset * (nthElement + 1) + (nthElement * g_DefaultWidth);
	return offset;
}

float GetOffsetY(int nthElement)
{
	return g_DefaultOffset * (nthElement + 1) + (nthElement * g_DefaultHeight);
}

Point2f GetCoordinatesFromRadian(float radius, float radian, float xOffset, float yOffset)
{
	float x = radius * cos(radian);
	float y = radius * sin(radian);
	return Point2f(x + xOffset, y + yOffset);
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