// Vanhaverbeke, Brenainn - 1DAE10

#include "pch.h"
#include "Game.h"
#include <iostream>

#pragma region gameFunctions											
void Start() {}

void Draw()
{
	ClearBackground(0.0f, 0.0f, 0.0f);
	DrawMatches();
}

void Update(float elapsedSec) {}

void End() {}
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key) {}

void OnKeyUpEvent(SDL_Keycode key)
{
	if (g_IsPlaying)
	{
		switch (key)
		{
		case SDLK_1:
		case SDLK_KP_1:
			HandlePlayerMove(1);
			break;
		case SDLK_2:
		case SDLK_KP_2:
			HandlePlayerMove(2);
			break;
		case SDLK_3:
		case SDLK_KP_3:
			HandlePlayerMove(3);
			break;
		}
		if (g_PlayerVictory || g_ComputerVictory)
		{
			HandleVictory();
		}
	}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e) {}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e) {}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e) {}
#pragma endregion inputHandling

#pragma region ownDefinitions

void DrawMatches()
{
	DrawMatchPool(g_MatchesPool, g_Border, g_WindowHeight - g_Border - g_MatchHeight);
	DrawMatchPool(g_PlayerMatchesPool, g_Border, g_Border);
	DrawMatchPool(g_ComputerMatchesPool, g_WindowWidth / 2.0f + g_Border, g_Border);
}

void DrawMatchPool(int amountOfMatches, float offsetX, float offsetY)
{
	for (int i = 0; i < amountOfMatches; i++)
	{
		SetColor(g_MatchBodyColour);
		FillRect(offsetX, offsetY, g_MatchWidth, g_MatchHeight);
		SetColor(g_MatchHeadColour);
		FillRect(offsetX, offsetY + (g_MatchHeight - g_MatchHeadHeight), g_MatchWidth, g_MatchHeadHeight);
		offsetX += g_MatchWidth + g_DefaultOffset;
	}
}

void HandlePlayerMove(int amountToDraw)
{
	if (g_MatchesPool < amountToDraw)
	{
		std::cout << "Invalid selection, there are too few matches remaining.\n";
	}
	else
	{
		std::cout << "Drawing " << amountToDraw << " matches.\n";
		g_MatchesPool -= amountToDraw;
		g_PlayerMatchesPool += amountToDraw;
		g_PlayerMoves += std::to_string(amountToDraw) + " ";
		g_PlayerVictory = g_MatchesPool == 0;
		if (!g_PlayerVictory)
			HandleComputerMove();
	}
}

void HandleComputerMove()
{
	int amountToDraw{};
	do
	{
		amountToDraw = GenerateRandomInt(1, 3);
	} while (g_MatchesPool < amountToDraw);
	g_MatchesPool -= amountToDraw;
	g_ComputerMatchesPool += amountToDraw;
	g_ComputerMoves += std::to_string(amountToDraw) + " ";
	g_ComputerVictory = g_MatchesPool == 0;
}

void HandleVictory()
{
	std::cout << g_PlayerMoves << std::endl;
	std::cout << g_ComputerMoves << std::endl;
	std::cout << (g_PlayerVictory ? "You win" : "Computer wins.") << std::endl;
	g_IsPlaying = false;
}

int GenerateRandomInt(int min, int max)
{

	return (rand() % max) + min;
}

#pragma endregion ownDefinitions