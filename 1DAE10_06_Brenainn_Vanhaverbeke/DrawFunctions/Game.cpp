// Vanhaverbeke, Brenainn - 1DAE10

#include "pch.h"
#include "Game.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground();
	DrawSquares();
	DrawEquilateralTriangles();
	DrawPentagrams();
}

void Update(float elapsedSec) {}

void End() {}
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

void DrawSquares()
{
	SetColor(g_White);
	DrawSquare(Point2f{ 20, 200 }, 80, 10);
	DrawSquare(Point2f{ 120, 200 }, 60, 5);
	DrawSquare(Point2f{ 190, 200 }, 40, 3);
}

void DrawEquilateralTriangles()
{
	DrawConcentricTriangles();
	DrawSierpinskiTriangle(Point2f{ 350, 200 }, 80);
}

void DrawPentagrams()
{

}

void DrawConcentricTriangles()
{
	SetColor(g_Red);
	DrawEquilateralTriangle(Point2f{ 250, 200 }, 80, true);
	SetColor(g_Green);
	DrawEquilateralTriangle(Point2f{ 260, 205 }, 60, true);
	SetColor(g_Blue);
	DrawEquilateralTriangle(Point2f{ 270, 210 }, 40, true);
}

void DrawSquare(Point2f position, float size, float amountOfSquares)
{
	float offset = size / (amountOfSquares * 2);
	for (int i = 0; i < amountOfSquares; i++)
	{
		DrawRect(position, size, size);
		position.x += offset;
		position.y += offset;
		size -= (offset * 2);
	}
}

void DrawEquilateralTriangle(Point2f position, float size, bool isFilled)
{
	Point2f position2{ GetCoordinatesFromRadians(size, ConvertDegreesToRadians(60.0f), position) };
	Point2f position3{ Point2f{ position.x + size, position.y } };
	if (isFilled)
		FillTriangle(position, position2, position3);
	else
		DrawTriangle(position, position2, position3);
}

void DrawSierpinskiTriangle(Point2f position, float size)
{
	if (size <= 3.0f)
		return;
	SetColor(g_Black);
	DrawEquilateralTriangle(position, size, false);
	DrawSierpinskiTriangle(position, size / 2);
	Point2f position2{ GetCoordinatesFromRadians(size / 2, ConvertDegreesToRadians(60.0f), position) };
	DrawSierpinskiTriangle(position2, size / 2);
	Point2f position3{ position.x + size / 2, position.y };
	DrawSierpinskiTriangle(position3, size / 2);
}

void DrawPentagram(Point2f position, float size)
{
	float offset{ (360 / 5) * 2 };
	for (int i = 0; i < 5; i++)
	{

	}
}

float ConvertDegreesToRadians(float degrees)
{
	return degrees * (g_Pi / 180);
}

Point2f GetCoordinatesFromRadians(float radius, float radians, Point2f offset)
{
	float x = offset.x + (radius * cosf(radians));
	float y = offset.y + (radius * sinf(radians));
	return Point2f{ x, y };
}

#pragma endregion ownDefinitions