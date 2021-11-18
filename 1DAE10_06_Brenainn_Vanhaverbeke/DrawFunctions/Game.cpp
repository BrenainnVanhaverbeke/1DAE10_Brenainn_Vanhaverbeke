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
	DrawLinearGradients();
	DrawDotGrids();
	//DrawSierpinskiTriangle(Point2f{ (g_WindowWidth - g_WindowHeight) / 2, 10 }, g_WindowHeight);
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
	DrawSquare(Point2f{ 20, 300 }, 80, 10);
	DrawSquare(Point2f{ 120, 300 }, 60, 5);
	DrawSquare(Point2f{ 190, 300 }, 40, 3);
}

void DrawEquilateralTriangles()
{
	DrawConcentricTriangles();
	SetColor(g_Black);
	DrawSierpinskiTriangle(Point2f{ 350, 300 }, 80);
}

void DrawPentagrams()
{
	SetColor(g_Blue);
	DrawPentagram(Point2f{ 350, 265 }, 30);
	SetColor(g_Red);
	DrawPentagram(Point2f{ 400, 265 }, 15);
}

void DrawLinearGradients()
{
	DrawLinearGradient(Point2f{ 20, 270 }, Rectf{ 0, 0, 100, 15 }, g_Black, g_White);
	DrawLinearGradient(Point2f{ 20, 240 }, Rectf{ 0, 0, 150, 20 }, g_Green, g_Red);
	DrawLinearGradient(Point2f{ 20, 200 }, Rectf{ 0, 0, 200, 30 }, Color4f{ 0.7f, 0.4f, 1.0f, 1.0f }, Color4f{ 1.0f, 0.4f, 0.7f, 1.0f });
	DrawLinearGradient(Point2f{ 20, 150 }, Rectf{ 0, 0, 300, 40 }, g_Red, g_Black);
}

void DrawConcentricTriangles()
{
	SetColor(g_Red);
	DrawEquilateralTriangle(Point2f{ 250, 300 }, 80, true);
	SetColor(g_Green);
	DrawEquilateralTriangle(Point2f{ 260, 305 }, 60, true);
	SetColor(g_Blue);
	DrawEquilateralTriangle(Point2f{ 270, 310 }, 40, true);
}

void DrawDotGrids()
{
	SetColor(g_Red);
	DrawDotGrid(Point2f{ 10, 10 }, 20, 5, 3, 5);
	SetColor(g_Green);
	DrawDotGrid(Point2f{ 250, 50 }, 15, 7, 2, 3);
	SetColor(g_Blue);
	DrawDotGrid(Point2f{ 260, 60 }, 5, 7, 2, 23);
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
		Point2f startLine{ GetCoordinatesFromRadians(size, ConvertDegreesToRadians(offset * i), position) };
		Point2f endLine{ GetCoordinatesFromRadians(size, ConvertDegreesToRadians(offset * (i + 1)), position) };
		DrawLine(startLine, endLine);
	}
}

void DrawLinearGradient(Point2f position, Rectf size, Color4f colourLeft, Color4f colourRight)
{
	float colourShift{ 1.0f / size.width };
	colourRight.a = 0;
	for (int i = 1; i < size.width; i++)
	{
		Point2f startLine{ position.x + i, position.y };
		Point2f endLine{ position.x + i, position.y + size.height };
		SetColor(colourLeft);
		DrawLine(startLine, endLine);
		SetColor(colourRight);
		DrawLine(startLine, endLine);
		colourLeft.a -= colourShift;
		colourRight.a += colourShift;
	}
}

void DrawDotGrid(Point2f basePosition, float radius, float columns, float rows, float offset)
{
	basePosition.x += radius;
	basePosition.y += radius;
	offset = radius * 2 + offset;
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			FillEllipse(basePosition.x + (offset * column), basePosition.y + (offset * row), radius, radius);
		}
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