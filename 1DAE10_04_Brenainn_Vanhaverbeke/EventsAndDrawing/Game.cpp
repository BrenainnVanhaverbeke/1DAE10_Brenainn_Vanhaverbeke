// Vanhaverbeke, Brenainn - 1DAE10

#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	g_Rectangle = GenerateRectangle();
	g_BackupRectangle = g_BackupRectangle = g_Rectangle;
	g_BackupRectangle.left -= g_WindowWidth;
}

void Draw()
{
	ClearBackground();
	DrawRectangle();
}

void Update(float elapsedSec)
{
	RunningRectangleUpdate();
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
	switch (key)
	{
	case SDLK_r:
		RunningRectangleEvents();
		break;
	case SDLK_RIGHT:
		//std::cout << "Right arrow key released\n";
		break;
	case SDLK_1:
	case SDLK_KP_1:
		//std::cout << "Key 1 released\n";
		break;
	}
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
		ClickRectangleEvents(e);
		break;
	}
	case SDL_BUTTON_RIGHT:
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

void RunningRectangleEvents()
{
	if (g_RectangleRunning)
		g_RectangleRunning = false;
	else
		g_RectangleRunning = true;
}

#pragma endregion ownDefinitions