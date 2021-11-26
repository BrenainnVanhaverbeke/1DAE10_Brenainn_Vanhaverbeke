// Vanhaverbeke, Brenainn - 1DAE10

#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
}

void Draw()
{
	ClearBackground(0.0f, 0.0f, 0.0f);
	Point2f origin{ 0, 0 };
	DrawEquilateralSierpinskiTriangle(origin, g_WindowWidth / 2);
	DrawSierpinskiTriangle(Point2f{ g_WindowWidth / 2,0 }, Point2f{ g_WindowWidth * 0.75f, g_WindowHeight }, Point2f{ g_WindowWidth, 0 });
}

void Update(float elapsedSec)
{
}

void End()
{
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
void DrawEquilateralTriangle(const Point2f& position, float size, bool isFilled)
{
	Point2f position2{ GetCoordinatesFromRadians(size, ConvertDegreesToRadians(60.0f), position) };
	Point2f position3{ Point2f{ position.x + size, position.y } };
	if (isFilled)
		FillTriangle(position, position2, position3);
	else
		DrawTriangle(position, position2, position3);
}

void DrawEquilateralSierpinskiTriangle(const Point2f& position, float size)
{
	if (size <= 10.0f)
		return;
	DrawEquilateralTriangle(position, size, false);
	SetColor(g_Red);
	DrawEquilateralSierpinskiTriangle(position, size / 2);
	Point2f position2{ GetCoordinatesFromRadians(size / 2, ConvertDegreesToRadians(60.0f), position) };
	SetColor(g_Green);
	DrawEquilateralSierpinskiTriangle(position2, size / 2);
	Point2f position3{ position.x + size / 2, position.y };
	SetColor(g_Blue);
	DrawEquilateralSierpinskiTriangle(position3, size / 2);
}

void DrawSierpinskiTriangle(const Point2f& left, const Point2f& top, const Point2f& right)
{
	utils::DrawTriangle(left, top, right);
	if (GetDistance(left, right) <= 20.0f)
		return;
	SetColor(1.0f, 0.0f, 0.0f);
	DrawSierpinskiTriangle(left, GetMiddle(left, top), GetMiddle(left, right));
	SetColor(0.0f, 1.0f, 0.0f);
	DrawSierpinskiTriangle(GetMiddle(left, right), GetMiddle(right, top), right);
	SetColor(0.0f, 0.0f, 1.0f);
	DrawSierpinskiTriangle(GetMiddle(left, top), top, GetMiddle(top, right));
}


Point2f GetMiddle(const Point2f& pointA, const Point2f& pointB)
{
	return Point2f{ (pointA.x + pointB.x) / 2, (pointA.y + pointB.y) / 2 };
}

#pragma endregion ownDefinitions