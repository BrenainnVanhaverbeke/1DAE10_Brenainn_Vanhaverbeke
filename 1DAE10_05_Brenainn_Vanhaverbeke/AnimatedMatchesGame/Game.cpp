// Vanhaverbeke, Brenainn - 1DAE10

#include "pch.h"
#include "Game.h"
#include <iostream>

#pragma region gameFunctions											
void Start()
{
	InitialiseMatches();
}

void Draw()
{
	ClearBackground(0.0f, 0.0f, 0.0f);
	DrawMatches();
}

void Update(float elapsedSec) 
{
	for (int i = 0; i < sizeof(g_MatchPositions) / sizeof(g_MatchPositions[0]); i++)
	{
		Point2f match{ g_MatchPositions[i] };
		Point2f speed{ g_MatchSpeed[i] };
		Point2f destination = g_MatchDestinations[i];
		match.x += speed.x;
		match.y += speed.y;
		float differenceX{ match.x - destination.x };
		float differenceY{ match.y - destination.y };
		if (match.y - destination.y < 0)
		{
			speed = Point2f{ 0.f, 0.f };
			match = destination;
		}
		g_MatchPositions[i] = match;
		g_MatchSpeed[i] = speed;
	}
}

void End() {}
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key) {}

void OnKeyUpEvent(SDL_Keycode key)
{
	if (g_IsPlaying && !g_IsAnimating)
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

void InitialiseMatches()
{
	for (int i{ 0 }; i < 21; i++)
	{
		g_MatchPositions[i] = CalculateMatchPosition(i, g_Border, g_WindowHeight - g_Border - g_MatchHeight);
	}
}

void DrawMatches()
{
	for (int i{ 0 }; i < (sizeof(g_MatchPositions) / sizeof(g_MatchPositions[0])); i++)
	{
		Point2f matchPosition = g_MatchPositions[i];
		SetColor(g_MatchBodyColour);
		FillRect(matchPosition, g_MatchWidth, g_MatchHeight);
		SetColor(g_MatchHeadColour);
		matchPosition.y += (g_MatchHeight - g_MatchHeadHeight);
		FillRect(matchPosition, g_MatchWidth, g_MatchHeadHeight);
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
		CalculateMatchSpeeds(amountToDraw, g_PlayerMatchesPool, g_Border, g_Border);
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
	std::cout << "Drawing " << amountToDraw << " matches.\n";
	CalculateMatchSpeeds(amountToDraw, g_PlayerMatchesPool, g_WindowWidth / 2.0f + g_Border, g_Border);
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

Point2f CalculateMatchPosition(int matchNr, float offsetX, float offsetY)
{
	return Point2f{ offsetX + ((float)matchNr * g_DefaultOffset), offsetY };
}

void CalculateMatchSpeeds(int amountOfMatches, int totalMatches, float offsetX, float offsetY)
{
	for (int i{ 0 }; i < amountOfMatches; i++)
	{
		int index = (g_MatchesPool - amountOfMatches) + i;
		Point2f currentMatch = g_MatchPositions[index];
		Point2f matchDestination = CalculateMatchPosition(i + totalMatches, offsetX, offsetY);
		float differenceX = currentMatch.x - matchDestination.x;
		float differenceY = currentMatch.y - matchDestination.y;
		float hypothenuse = sqrtf(powf(differenceX, 2) + powf(differenceY, 2));
		float radians = asinf(differenceX / hypothenuse);
		g_MatchDestinations[index] = matchDestination;
		g_MatchSpeed[index] =  GetSpeedFromRadians(radians);
	}
}

float ConvertAngleToRadians(float angle)
{
	return angle * g_Pi / 180;
}

Point2f GetSpeedFromRadians(float radians)
{
	float x = g_DefaultSpeed * cosf(radians);
	float y = g_DefaultSpeed * sinf(radians);
	return Point2f{y * -1, x * -1};
}

int GenerateRandomInt(int min, int max)
{

	return (rand() % max) + min;
}

#pragma endregion ownDefinitions