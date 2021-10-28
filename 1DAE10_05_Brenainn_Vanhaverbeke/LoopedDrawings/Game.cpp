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
	ClearBackground(0, 0, 0);
	DrawSquares(0, 0, g_Iterations);
	DrawStairs(0, 1, g_Iterations);
	DrawSpiral(1, 0, g_Iterations);
	DrawSpinningLines(1, 1, g_Iterations);
}

void Update(float elapsedSec)
{

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

}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

void DrawSquares(int column, int row, int iterations)
{
	float offsetX{ GetOffsetX(column) };
	float offsetY{ GetOffsetY(row) };
	float squareSide{ g_DefaultHeight };
	float offsetStep{ squareSide / (iterations * 2) };
	SetColor(g_SquaresColour);
	for (int i{ 0 }; i < iterations; i++)
	{
		DrawRect(offsetX, offsetY, squareSide, squareSide, g_LineThickness);
		offsetX += offsetStep;
		offsetY += offsetStep;
		squareSide -= (offsetStep * 2);
	}
}

void DrawStairs(int column, int row, int iterations)
{
	float offsetX{ GetOffsetX(column) };
	float offsetY{ GetOffsetY(row) };
	float stairLength{ g_DefaultHeight / iterations };
	for (int i{ 0 }; i < iterations; i++)
	{
		SetColor(i % 2 == 0 ? g_StepsColourEven : g_StepsColourOdd);
		DrawLine(offsetX, offsetY, offsetX + stairLength, offsetY, 3);
		DrawLine(offsetX + stairLength, offsetY, offsetX + stairLength, offsetY + stairLength, g_LineThickness);
		offsetX += stairLength;
		offsetY += stairLength;
	}
}


// Can be simplified further, will get back to it.
void DrawSpiral(int column, int row, int iterations)
{
	iterations *= 2;
	float offsetX{ GetOffsetX(column) };
	float offsetY{ GetOffsetY(row) };
	float lineReduction{ g_DefaultHeight / iterations };
	float lineLength{ g_DefaultHeight };
	Point2f lineStart{ offsetX, offsetY };
	Point2f lineEnd{ lineStart };
	SetColor(g_SpiralColour);
	for (int i = 0; i < iterations; i++)
	{
		if (i % 2 == 0)
			lineEnd.x += lineLength;
		else
			lineEnd.x -= lineLength;
		DrawLine(lineStart, lineEnd, g_LineThickness);
		lineStart = lineEnd;
		if (i % 2 == 0)
			lineEnd.y += lineLength;
		else
			lineEnd.y -= lineLength;
		DrawLine(lineStart, lineEnd, g_LineThickness);
		lineStart = lineEnd;
		lineLength -= lineReduction;
	}
}

void DrawSpinningLines(int column, int row, int iterations)
{
	float offsetX{ GetOffsetX(column) };
	float offsetY{ GetOffsetY(row) };
	float lineOffset{ g_DefaultHeight / iterations };
	Point2f redLineStart{ offsetX, offsetY };
	Point2f redLineEnd{ offsetX + g_DefaultWidth, offsetY };
	Point2f greenLineStart{ offsetX + g_DefaultWidth, offsetY };
	Point2f greenLineEnd{ offsetX + g_DefaultWidth, offsetY + g_DefaultHeight };
	Point2f blueLineStart{ offsetX + g_DefaultWidth, offsetY + g_DefaultHeight };
	Point2f blueLineEnd{ offsetX, offsetY + g_DefaultHeight };
	Point2f yellowLineStart{ offsetX, offsetY + g_DefaultHeight};
	Point2f yellowLineEnd{ offsetX, offsetY };
	for (int i = 0; i < iterations; i++)
	{
		SetColor(g_SpinningLinesRed);
		DrawLine(redLineStart, redLineEnd);
		SetColor(g_SpinningLinesGreen);
		DrawLine(greenLineStart, greenLineEnd);
		SetColor(g_SpinningLinesBlue);
		DrawLine(blueLineStart, blueLineEnd);
		SetColor(g_SpinningLinesYellow);
		DrawLine(yellowLineStart, yellowLineEnd);
		redLineStart.x += lineOffset;
		redLineEnd.y += lineOffset;
		greenLineStart.y += lineOffset;
		greenLineEnd.x -= lineOffset;
		blueLineStart.x -= lineOffset;
		blueLineEnd.y -= lineOffset;
		yellowLineStart.y -= lineOffset;
		yellowLineEnd.x += lineOffset;
	}
}

float GetOffsetX(int column)
{
	return g_DefaultOffset * (column + 1) + (column * g_DefaultWidth);
}

float GetOffsetY(int row)
{
	return g_DefaultOffset * (row + 1) + (row * g_DefaultHeight);
}

#pragma endregion ownDefinitions