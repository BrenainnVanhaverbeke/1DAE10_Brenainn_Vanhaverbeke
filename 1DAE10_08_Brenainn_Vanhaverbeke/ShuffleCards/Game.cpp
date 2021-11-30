// Vanhaverbeke, Brenainn - 1DAE10

#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	InitialiseCardTextures();
	std::cout << "Card width: " << g_CardTextures[0].width << " MaxWidth: " << g_CardTextures[0].width * g_AmountOfCards << std::endl;
	std::cout << "Card height: " << g_CardTextures[0].height << " MaxHeight: " << g_CardTextures[0].height * g_AmountOfCards << std::endl;
}

void Draw()
{
	ClearBackground();
	DrawCards();
}

void Update(float elapsedSec)
{

}

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
void OnKeyDownEvent(SDL_Keycode key)
{
	switch (key)
	{
	case SDLK_s:
		ShuffleCards();
		break;
	}
}

void OnKeyUpEvent(SDL_Keycode key)
{

}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{

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

void InitialiseCardTextures()
{
	const int suites{ 4 };
	const int cardsPerSuite{ 13 };
	const std::string fileType{ ".png" };
	const std::string path{ "Resources/Cards/" };
	for (int suite = 0; suite < suites; suite++)
	{
		for (int card = 0; card < cardsPerSuite; card++)
		{
			int cardNumber{ (100 * (suite + 1)) + card + 1 };
			std::string fullPath{ path + std::to_string(cardNumber) + fileType };
			int index{ GetLinearIndexFrom2DIndex(suite, card, suites) };
			TextureFromFile(fullPath, g_CardTextures[index]);
		}
	}
}

void ShuffleCards()
{

}

void DrawCards()
{
	const float left{ g_WindowWidth / g_ColumnsOfCards };
	const float bottom{ g_WindowHeight / g_RowsOfCards };
	for (int row{ 0 }; row < g_RowsOfCards; row++)
	{
		for (int column{ 0 }; column < g_ColumnsOfCards; column++)
		{
			int index{ GetLinearIndexFrom2DIndex(row, column, g_ColumnsOfCards) };
			Rectf cardBase{ left * column, bottom * row, g_WindowWidth / g_ColumnsOfCards, g_WindowHeight / g_RowsOfCards };
			DrawTexture(g_CardTextures[index], cardBase);
		}
	}
}

int GetLinearIndexFrom2DIndex(int rowIndex, int columnIndex, int nrOfColumns)
{
	return rowIndex * nrOfColumns + columnIndex;
}

#pragma endregion ownDefinitions