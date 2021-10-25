// Vanhaverbeke, Brenainn - 1DAE10

#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	RectangleSetup();
	LineSetup();
}

void Draw()
{
	//if (g_NumberOfFrames % 15 == 0)
		ClearBackground(0, 0, 0);
	DrawRectangle();
	DrawBouncingLine();
}

void Update(float elapsedSec)
{
	g_NumberOfFrames++;
	RunningRectangleUpdate();
	BouncingLineUpdate();
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
	RunningRectangleEvents(key);
	BouncingLineEvents(key);
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e) {}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e) {}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	ClickRectangleEvents(e);
	LineSetup();
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
	float border{ 50 };
	float startLineX{ GenerateRandomFloat(0, g_WindowWidth) };
	float endLineX{ GenerateRandomFloat(0, g_WindowWidth) };
	float startLineY{ GenerateRandomFloat(0, g_WindowHeight) };
	float endLineY{ GenerateRandomFloat(0, g_WindowHeight) };
	g_StartPointSpeed = GetSpeedFromRadian(g_DefaultSpeed, AngleToRadians(GenerateRandomFloat(0, 360)));
	g_EndPointSpeed = GetSpeedFromRadian(g_DefaultSpeed, AngleToRadians(GenerateRandomFloat(0, 360)));
	g_StartPoint = Point2f{ startLineX, startLineY };
	g_EndPoint = Point2f{ endLineX, endLineY };
	g_LineColour = GenerateRandomColour();
}

void DrawRectangle()
{
	if (g_IsRectangleClicked)
		SetColor(g_Green);
	else
		SetColor(g_Grey);
	FillRect(g_Rectangle);
	FillRect(g_BackupRectangle);
}

void DrawBouncingLine()
{
	SetColor(g_LineColour);
	DrawLine(g_StartPoint, g_EndPoint);
}

void RunningRectangleUpdate()
{
	if (g_IsRectangleRunning)
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

void BouncingLineUpdate()
{
	if (g_IsLineBouncing)
	{
		g_EndPoint.x += g_EndPointSpeed.x;
		g_EndPoint.y += g_EndPointSpeed.y;
		g_StartPoint.x += g_StartPointSpeed.x;
		g_StartPoint.y += g_StartPointSpeed.y;
		if (g_EndPoint.x <= 0 || g_WindowWidth <= g_EndPoint.x)
		{
			g_EndPointSpeed.x *= -1;
			g_LineColour = GenerateRandomColour();
		}
		if (g_EndPoint.y <= 0 || g_WindowHeight <= g_EndPoint.y)
		{
			g_EndPointSpeed.y *= -1;
			g_LineColour = GenerateRandomColour();
		}
		if (g_StartPoint.x <= 0 || g_WindowWidth <= g_StartPoint.x)
		{
			g_StartPointSpeed.x *= -1;
			g_LineColour = GenerateRandomColour();
		}
		if (g_StartPoint.y <= 0 || g_WindowHeight <= g_StartPoint.y)
		{
			g_StartPointSpeed.y *= -1;
			g_LineColour = GenerateRandomColour();
		}
	}
}

void ClickRectangleEvents(SDL_MouseButtonEvent e)
{
	if (e.button == SDL_BUTTON_LEFT)
	{
		if (IsClickInRectangle((float)e.x, (float)e.y))
		{
			if (g_IsRectangleClicked)
			{
				g_Rectangle = GenerateRectangle();
				g_BackupRectangle = g_Rectangle;
				g_BackupRectangle.left -= g_WindowWidth;
				g_IsRectangleClicked = false;
			}
			else
			{
				g_IsRectangleClicked = true;
			}
		}
	}
}

void RunningRectangleEvents(SDL_Keycode key)
{
	if (key == SDLK_r)
	{
		if (g_IsRectangleRunning)
			g_IsRectangleRunning = false;
		else
			g_IsRectangleRunning = true;
	}
}

void BouncingLineEvents(SDL_Keycode key)
{
	if (key == SDLK_l)
	{
		g_IsLineBouncing = !g_IsLineBouncing;
	}
}

bool IsClickInRectangle(float mouseX, float mouseY)
{
	mouseY = g_WindowHeight - mouseY;
	bool inRectangle{ g_Rectangle.left <= mouseX && mouseX <= g_Rectangle.width + g_Rectangle.left || g_BackupRectangle.left <= mouseX && mouseX <= g_BackupRectangle.width + g_BackupRectangle.left };
	if (inRectangle)
		inRectangle = g_Rectangle.bottom <= mouseY && mouseY <= g_Rectangle.height + g_Rectangle.bottom || g_BackupRectangle.bottom <= mouseY && mouseY <= g_BackupRectangle.height + g_BackupRectangle.bottom;
	return inRectangle;
}

float AngleToRadians(float angle)
{
	return angle * g_Pi / 180;
}

Point2f GetSpeedFromRadian(float speed, float radian)
{
	float x = speed * (float)cos(radian);
	float y = speed * (float)sin(radian);
	return Point2f(x, y);
}

Rectf GenerateRectangle(float border, float minimumWidth, float minimumHeight)
{
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

Color4f GenerateRandomColour()
{
	float red{ GenerateRandomFloat(0, 255) / 255 };
	float green{ GenerateRandomFloat(0, 255) / 255 };
	float blue{ GenerateRandomFloat(0, 255) / 255 };
	float alpha{ 1 };
	return Color4f{ red, green, blue, alpha };
}

float GenerateRandomFloat(float min, float max)
{
	return (float)((rand() % (int)max) + min);
}

#pragma endregion ownDefinitions