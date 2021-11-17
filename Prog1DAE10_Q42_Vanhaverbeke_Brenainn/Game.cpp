#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	PrintLetters();
}

void Draw()
{
	ClearBackground();
	DrawCircle();
}

void Update(float elapsedSec)
{
	switch (g_CircleState)
	{
	case GROWING:
		HandleCircleGrowing();
		break;
	case SHRINKING:
		HandleCircleShrinking();
		break;
	case WAITING:
	default:
		break;
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
	switch (key)
	{
	case SDLK_UP:
	case SDLK_RIGHT:
		if (g_CurrentSpeed < g_MaxSpeed)
			g_CurrentSpeed += g_SpeedIncrement;
		else
			std::cout << "Speed can't go any higher." << std::endl;
		std::cout << "Current speed is " << g_CurrentSpeed << std::endl;
		break;
	case SDLK_DOWN:
	case SDLK_LEFT:
		if (g_MinSpeed < g_CurrentSpeed)
			g_CurrentSpeed -= g_SpeedIncrement;
		else
			std::cout << "Speed can't go any lower." << std::endl;
		std::cout << "Current speed is " << g_CurrentSpeed << std::endl;
		break;
	default:
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
	if (g_CircleState == CircleState::WAITING)
	{
		g_MouseClickPosition = Point2f{ (float)e.x, (float)(g_WindowHeight - e.y) };
		g_Circle = Ellipsef{ g_MouseClickPosition, 0.0f, 0.0f };
		g_CircleState = CircleState::GROWING;
		g_CurrentColour = GetRandomColour();
		g_MaxRadius = GetRandomNumber(50, 100);
		std::cout << "The circle is growing." << std::endl;
		std::cout << "The maximum radius is: " << g_MaxRadius << "." << std::endl;
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

bool CheckWindowCollision()
{
	bool collisionX{ g_MouseClickPosition.x - g_Circle.radiusX < 0 || g_WindowWidth < g_Circle.radiusX + g_MouseClickPosition.x};
	bool collisionY{ g_MouseClickPosition.y - g_Circle.radiusY < 0 || g_WindowHeight < g_Circle.radiusY + g_MouseClickPosition.y };
	return collisionX || collisionY;
}

void PrintLetters()
{
	int lettersPerLine{};
	std::cout << "How many letters per line? ";
	std::cin >> lettersPerLine;
	std::cout << std::endl;
	char firstLetter{ 'a' };
	for (int i = 0; i < 26; i++)
	{
		if (i != 0 && i % lettersPerLine == 0)
		{
			std::cout << std::endl;
		}
		std::cout << (char)(firstLetter + i);
	}
}

void DrawCircle()
{
	SetColor(g_CurrentColour);
	FillEllipse(g_Circle);
}

void HandleCircleGrowing()
{
	if (CheckWindowCollision())
	{
		std::cout << "Ouch!" << std::endl;
		std::cout << "The circle is shrinking." << std::endl;
		g_CurrentColour = g_Red;
		g_CircleState = CircleState::SHRINKING;
	}
	else if (g_Circle.radiusX < g_MaxRadius)
	{
		g_Circle.radiusX += g_CurrentSpeed;
		g_Circle.radiusY += g_CurrentSpeed;
	}
	else
	{
		g_CircleState = CircleState::SHRINKING;
		std::cout << "The circle is shrinking." << std::endl;
	}
}

void HandleCircleShrinking()
{
	if (0 < g_Circle.radiusX - g_CurrentSpeed)
	{
		g_Circle.radiusX -= g_CurrentSpeed;
		g_Circle.radiusY -= g_CurrentSpeed;
	}
	else
	{
		g_Circle.radiusX = 0;
		g_Circle.radiusY = 0;
		g_CircleState = CircleState::WAITING;
		std::cout << "Waiting for a new click." << std::endl;
	}
}

Color4f GetRandomColour()
{
	float r{ GetRandomNumber(0, 255) / 255 };
	float g{ GetRandomNumber(0, 255) / 255 };
	float b{ GetRandomNumber(0, 255) / 255 };
	return Color4f{ r, g, b, 1 };
}

float GetRandomNumber(int lowestValue, int amountOfValues)
{
	amountOfValues++;
	return (float)(rand() % amountOfValues) + lowestValue;
}

#pragma endregion ownDefinitions