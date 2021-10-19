// Vanhaverbeke, Brenainn - 1DAE10

#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	//RectangleSetup();
	LineSetup();
}

void Draw()
{
	ClearBackground();
	//DrawRectangle();
	DrawLine(g_StartLine, g_EndLine);
}

void Update(float elapsedSec)
{
	//RunningRectangleUpdate();
	if (g_FlipEndLineX)
	{
		if (--g_EndLine.x <= 0)
			g_FlipEndLineX = false;
	}
	else
	{
		if (g_WindowWidth <= ++g_EndLine.x)
			g_FlipEndLineX = true;
	}
	if (g_FlipStartLineX)
	{
		if (--g_StartLine.x <= 0)
			g_FlipStartLineX = false;
	}
	else
	{
		if (g_WindowWidth <= ++g_StartLine.x)
			g_FlipStartLineX = true;
	}
	if (g_FlipEndLineY)
	{
		if (--g_EndLine.y <= 0)
			g_FlipEndLineY = false;
	}
	else
	{
		if (g_WindowHeight <= ++g_EndLine.y)
			g_FlipEndLineY = true;
	}
	if (g_FlipStartLineY)
	{
		if (--g_StartLine.y <= 0)
			g_FlipStartLineY = false;
	}
	else
	{
		if (g_WindowHeight <= ++g_StartLine.y)
			g_FlipStartLineY = true;
	}
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
	//RunningRectangleEvents(key);
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
	//ClickRectangleEvents();
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

void RectangleSetup()
{
	g_Rectangle = GenerateRectangle();
	g_BackupRectangle = g_BackupRectangle = g_Rectangle;
	g_BackupRectangle.left -= g_WindowWidth;
}

void LineSetup()
{
	float startLineX = GenerateRandomFloat(0, g_WindowWidth);
	float endLineX = GenerateRandomFloat(0, g_WindowWidth);
	float startLineY = GenerateRandomFloat(0, g_WindowWidth);
	float endLineY = GenerateRandomFloat(0, g_WindowWidth);
	g_StartLine = Point2f{ startLineX, startLineY };
	g_EndLine = Point2f{ endLineX, endLineY };
}

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
	FillRect(g_BackupRectangle);
}

float GenerateRandomFloat(float min, float max)
{
	return (float)((rand() % (int)max) + min);
}

bool IsClickInRectangle(float mouseX, float mouseY)
{
	mouseY = g_WindowHeight - mouseY;
	bool inRectangle{ g_Rectangle.left <= mouseX && mouseX <= g_Rectangle.width + g_Rectangle.left || g_BackupRectangle.left <= mouseX && mouseX <= g_BackupRectangle.width + g_BackupRectangle.left };
	if (inRectangle)
		inRectangle = g_Rectangle.bottom <= mouseY && mouseY <= g_Rectangle.height + g_Rectangle.bottom || g_BackupRectangle.bottom <= mouseY && mouseY <= g_BackupRectangle.height + g_BackupRectangle.bottom;
	return inRectangle;
}

void ClickRectangleEvents(SDL_MouseButtonEvent e)
{
	if (e.button == SDL_BUTTON_LEFT)
	{
		if (IsClickInRectangle((float)e.x, (float)e.y))
		{
			if (g_RectangleClicked)
			{
				g_Rectangle = GenerateRectangle();
				g_BackupRectangle = g_Rectangle;
				g_BackupRectangle.left -= g_WindowWidth;
				g_RectangleClicked = false;
			}
			else
			{
				g_RectangleClicked = true;
			}
		}
	}
}

void RunningRectangleUpdate()
{
	if (g_RectangleRunning)
	{
		g_Rectangle.left++;
		g_BackupRectangle.left++;
		if (g_WindowWidth <= g_Rectangle.left)
		{
			g_Rectangle = g_BackupRectangle;
			g_BackupRectangle.left -= g_WindowWidth;
		}
	}
}

void RunningRectangleEvents(SDL_Keycode key)
{
	if (key == SDLK_r)
	{
		if (g_RectangleRunning)
			g_RectangleRunning = false;
		else
			g_RectangleRunning = true;
	}
}

#pragma endregion ownDefinitions