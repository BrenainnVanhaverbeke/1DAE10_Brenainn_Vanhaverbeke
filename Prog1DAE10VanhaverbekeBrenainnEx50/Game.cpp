// Vanhaverbeke, Brenainn - 1DAE10

#include "pch.h"
#include "Game.h"
#include "Tile.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	InitialiseTiles();
	RandomiseTiles();
}

void Draw()
{
	ClearBackground(0.0f, 0.0f, 0.0f);
	DrawTiles();
	DrawBorder();
	if (g_IsWon)
		DrawAnimalName();
}

void Update(float elapsedSec) {}

void End()
{
	DeleteTiles();
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling
void OnKeyDownEvent(SDL_Keycode key) {}

void OnKeyUpEvent(SDL_Keycode key)
{
	switch (key)
	{
	case SDLK_r:
		RandomiseTiles();
		break;
	}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	Point2f mousePosition{ float(e.x), float(g_WindowHeight - e.y) };
	for (int i{ 0 }; i < g_NrOfTiles; ++i)
		g_pTiles[i]->CheckActivation(mousePosition);
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e) {}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	Point2f mousePosition{ float(e.x), float(g_WindowHeight - e.y) };
	for (int i{ 0 }; i < g_NrOfTiles; ++i)
	{
		if (g_pTiles[i]->CheckHit(mousePosition))
		{
			CheckWin();
			return;
		}
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions

void InitialiseTiles()
{
	const float sideLength{ 128 };
	const float defaultLeft{ (g_WindowWidth - (sideLength * g_GridColumns)) / 2 };
	const float defaultBottom{ (g_WindowHeight - (sideLength * g_GridRows)) / 2 };
	for (int row{ 0 }; row < g_GridRows; ++row)
	{
		Rectf destinationRectangle{ defaultLeft, defaultBottom + (sideLength * (1 - row)), sideLength, sideLength };
		for (int column{ 0 }; column < g_GridColumns; ++column)
		{
			int tileIndex{ GetLinearIndexFrom2D(1 - row, column, g_GridColumns) };
			std::string imagePath{ "Resources/Tiles" + std::to_string(row) + std::to_string(column) + ".png" };
			destinationRectangle.left = defaultLeft + (column * sideLength);
			g_pTiles[tileIndex] = new Tile(destinationRectangle, imagePath, g_NrOfAnimals);
		}
	}
}

void DrawTiles()
{
	for (int tile{ 0 }; tile < g_NrOfTiles; tile++)
		g_pTiles[tile]->Draw();
}

void DrawBorder()
{
	const float sideLength{ 128.0f };
	const Color4f borderColourPlaying{ 1.0f, 0.0f, 0.0f, 1.0f };
	const Color4f borderColourWon{ 0.0f, 1.0f, 0.0f, 1.0f };

	float left{ (g_WindowHeight - (sideLength * g_GridColumns)) / 2 };
	float bottom{ (g_WindowHeight - (sideLength * g_GridRows)) / 2 };
	float width{ sideLength * g_GridColumns };
	float height{ sideLength * g_GridRows };
	SetColor(g_IsWon ? borderColourWon : borderColourPlaying);
	DrawRect(left, bottom, width, height, 3.0f);
}

void DrawAnimalName()
{
	const std::string animalsNamePath{ "Resources/Names.png" };

	Texture animalNameSprite{};
	if (TextureFromFile(animalsNamePath, animalNameSprite))
	{
		Rectf destination{};
		destination.height = animalNameSprite.height / g_NrOfAnimals;
		destination.width = animalNameSprite.width;
		destination.left = (g_WindowWidth - destination.width) / 2;
		destination.bottom = ((g_WindowHeight - (128.0f * g_GridRows)) / 2) - destination.height;
		Rectf source{ destination };
		source.left = 0;
		source.bottom = destination.height * (g_pTiles[0]->GetCurrentAnimal() + 1);
		DrawTexture(animalNameSprite, destination, source);
		DeleteTexture(animalNameSprite);
	}
	else
		std::cout << "I dun goofed..." << std::endl;
}

void CheckWin()
{
	for (int i{ 0 }; i < g_NrOfTiles - 1; ++i)
	{
		if (g_pTiles[i]->GetCurrentAnimal() != g_pTiles[i + 1]->GetCurrentAnimal())
			return;
	}
	g_IsWon = true;
	DeactivateTiles();
}

void RandomiseTiles()
{
	do
	{
		for (int i{ 0 }; i < g_NrOfTiles; ++i)
			g_pTiles[i]->Randomise();
		g_IsWon = false;
		CheckWin();
	} while (g_IsWon);
}

void DeactivateTiles()
{
	for (int i{ 0 }; i < g_NrOfTiles; ++i)
		g_pTiles[i]->Deactivate();
}

void DeleteTiles()
{
	for (int tile{ 0 }; tile < g_NrOfTiles; ++tile)
	{
		delete g_pTiles[tile];
		g_pTiles[tile] = nullptr;
	}
}

#pragma endregion ownDefinitions