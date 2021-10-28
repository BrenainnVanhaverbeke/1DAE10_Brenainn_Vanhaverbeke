// Vanhaverbeke, Brenainn - 1DAE10

/***
*** Statistics conclusion ***
* Double dice throw statistics looks like somebody flipping you off.
***/

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
	ClearBackground();
	int singleDiceRoll = GetDiceRoll(1, 6);
	int doubleDiceRoll = GetDiceRoll(1, 6) + GetDiceRoll(1, 6);
	IncrementSingleRollFrequencyTable(singleDiceRoll);
	IncrementDoubleFrequencyTable(doubleDiceRoll);
	for (int i = 0; i < 17; i++)
	{
		if (i < 6)
			DrawFrequencyBar(i, GetSingleRollFrequency(i), g_Red, GetOffsetY(i));
		DrawFrequencyBar(i, GetDoubleRollFrequency(i), g_Blue, GetOffsetY(i + 6));
	}
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

int GetDiceRoll(int min, int max)
{
	return rand() % max + min;
}

void IncrementSingleRollFrequencyTable(int diceRoll)
{
	switch (diceRoll)
	{
	case 1: 
		g_Roll1Single++;
		break;
	case 2:
		g_Roll2Single++;
		break;
	case 3:
		g_Roll3Single++;
		break;
	case 4:
		g_Roll4Single++;
		break;
	case 5:
		g_Roll5Single++;
		break;
	case 6:
		g_Roll6Single++;
		break;
	}
}

void IncrementDoubleFrequencyTable(int diceRoll)
{
	switch (diceRoll)
	{
	case 2:
		g_Roll2++;
		break;
	case 3:
		g_Roll3++;
		break;
	case 4:
		g_Roll4++;
		break;
	case 5:
		g_Roll5++;
		break;
	case 6:
		g_Roll6++;
		break;
	case 7:
		g_Roll7++;
		break;
	case 8:
		g_Roll8++;
		break;
	case 9:
		g_Roll9++;
		break;
	case 10:
		g_Roll10++;
		break;
	case 11:
		g_Roll11++;
		break;
	case 12:
		g_Roll12++;
		break;

	default:
		break;
	}
}

int GetSingleRollFrequency(int rollNumber)
{
	rollNumber++;
	switch (rollNumber)
	{
	case 1: 
		return g_Roll1Single;
	case 2:
		return g_Roll2Single;
	case 3:
		return g_Roll3Single;
	case 4:
		return g_Roll4Single;
	case 5:
		return g_Roll5Single;
	case 6:
		return g_Roll6Single;
	}
	// Abandon all hope, ye who enter here.
	return 0;
}

int GetDoubleRollFrequency(int rollNumber)
{
	rollNumber++;
	switch (rollNumber)
	{
	case 2:
		return g_Roll2;
	case 3:
		return g_Roll3;
	case 4:
		return g_Roll4;
	case 5:
		return g_Roll5;
	case 6:
		return g_Roll6;
	case 7:
		return g_Roll7;
	case 8:
		return g_Roll8;
	case 9:
		return g_Roll9;
	case 10:
		return g_Roll10;
	case 11:
		return g_Roll11;
	case 12:
		return g_Roll12;
	}
	// Abandon all hope, ye who enter here.
	return 0;
}

void DrawFrequencyBar(int number, int frequency, Color4f colour, float initialOffset)
{
	SetColor(colour);
	FillRect(GenerateBar(number, frequency, initialOffset));
}

float GetOffsetY(int number)
{
	float bottom{ (g_DefaultBorder * number) + g_DefaultBorder * 2 + (g_DefaultHeight * number) };
	return bottom;
}

Rectf GenerateBar(int number, int frequency, float bottom)
{
	//float widthUnit{ (g_WindowWidth - g_DefaultBorder * 2) / 1000 };
	//float width{ widthUnit * frequency };
	float left{ g_DefaultBorder };
	return Rectf{ left, bottom, (float)frequency, g_DefaultHeight };
}

#pragma endregion ownDefinitions