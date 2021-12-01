// Vanhaverbeke, Brenainn - 1DAE10

#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	InitialiseCardTextures();
}

void Draw()
{
	ClearBackground();
	DrawCards();
}

void Update(float elapsedSec) {}

void End()
{
	for (int i = 0; i < g_AmountOfCards; i++)
	{
		DeleteTexture(g_CardTextures[i]);
	}
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key) {}

void OnKeyUpEvent(SDL_Keycode key)
{
	switch (key)
	{
	case SDLK_s:
		ShuffleCards((int)GetRandomNumber(1, 100));
		break;
	}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e) {}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e) {}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e) {}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

void InitialiseCardTextures()
{
	const std::string fileType{ ".png" };
	const std::string path{ "Resources/Cards/" };
	for (int suite = 0; suite < g_RowsOfCards; suite++)
	{
		for (int card{ 0 }; card < g_ColumnsOfCards; card++)
		{
			int index{ GetLinearIndexFrom2DIndex(suite, card, g_ColumnsOfCards) };
			std::string fullPath{ path + std::to_string(100 * (suite + 1) + card + 1) + fileType };
			std::cout << "Index: " << index << " Path: " << fullPath << std::endl;
			TextureFromFile(fullPath, g_CardTextures[index]);
		}
	}
}

void ShuffleCards(int amountOfShuffles)
{
	int swapIndex{};
	int swapWithIndex{};
	for (int i{ 0 }; i < amountOfShuffles; i++)
	{
		do
		{
			swapIndex = (int)GetRandomNumber(0, 51);
			swapWithIndex = (int)GetRandomNumber(0, 51);
		} while (swapIndex == swapWithIndex);
		Texture temporaryLocation{ g_CardTextures[swapIndex] };
		g_CardTextures[swapIndex] = g_CardTextures[swapWithIndex];
		g_CardTextures[swapWithIndex] = temporaryLocation;
	}
}

void DrawCards()
{
	const float width{ g_WindowWidth / g_ColumnsOfCards };
	const float height{ g_WindowHeight / g_RowsOfCards };
	for (int row{ 0 }; row < g_RowsOfCards; row++)
	{
		for (int column{ 0 }; column < g_ColumnsOfCards; column++)
		{
			int index{ GetLinearIndexFrom2DIndex(row, column, g_ColumnsOfCards) };
			Rectf cardBase{ width * column, height * row, width, height };
			DrawTexture(g_CardTextures[index], cardBase);
		}
	}
}

int GetLinearIndexFrom2DIndex(int rowIndex, int columnIndex, int nrOfColumns)
{
	return rowIndex * nrOfColumns + columnIndex;
}

#pragma endregion ownDefinitions