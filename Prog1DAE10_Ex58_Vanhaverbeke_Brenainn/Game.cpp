// Vanhaverbeke, Brenainn - 1DAE10

#include "pch.h"
#include "Game.h"
#include "Vehicle.h"
#include "MyUtils.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	InitStreetTexture();
	InitChicken();
	InitVehicles();
	PrintInstructions();
}

void Draw()
{
	ClearBackground();
	DrawStreet();
	DrawChicken();
	DrawVehicles();
	if (g_GameState == GameState::WIN)
		DrawMessage("The chicken survived!");
	if (g_GameState == GameState::LOSE)
		DrawMessage("The chicken died :(");
	if (g_GameState == GameState::PAUSE)
		DrawMessage("The game is paused.");
}

void Update(float elapsedSec)
{
	if (g_GameState != GameState::PAUSE)
	{
		if (g_GameState == GameState::RESET)
			Reset();
		if (g_GameState != GameState::LOSE)
			UpdateChicken(elapsedSec);
		UpdateVehicles(elapsedSec);
		CheckChickenCollision();
	}
}

void End()
{
	DeleteTexture(g_Street);
	DeleteTexture(g_Chicken);
	DeleteVehicles();
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{
	if (g_GameState == GameState::PLAY)
	{
		switch (key)
		{
		case SDLK_LEFT:
			g_ChickenDirection = ChickenDirection::LEFT;
			break;
		case SDLK_RIGHT:
			g_ChickenDirection = ChickenDirection::RIGHT;
			break;
		case SDLK_DOWN:
			g_IsGoingDown = true;
			break;
		}
	}
}

void OnKeyUpEvent(SDL_Keycode key)
{
	switch (key)
	{
	case SDLK_LEFT:
	case SDLK_RIGHT:
		g_ChickenDirection = ChickenDirection::DOWN_IDLE;
		break;
	case SDLK_DOWN:
		g_IsGoingDown = false;
		break;
	case SDLK_r:
		g_GameState = GameState::RESET;
		break;
	case SDLK_p:
		g_GameState = g_GameState == GameState::PLAY ? GameState::PAUSE : GameState::PLAY;
		break;
	}
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

void InitStreetTexture()
{
	if (!utils::TextureFromFile("Resources/street.png", g_Street))
		std::cout << "The street blew up. Abandon all hope." << std::endl;
}

void InitChicken()
{
	if (utils::TextureFromFile("Resources/Chicken.bmp", g_Chicken))
		ResetChicken();
	else
		std::cout << "Something has gone horribly, horribly wrong with the chicken. Abandon all hope." << std::endl;
}

void InitVehicles()
{
	const float laneBottomOrigin{ 43.0f };
	const float laneHeight{ 45.0f };
	int vehicleIds[g_AmountOfVehicles]{ 1, 2, 3, 4, 5 };
	ShuffleArray(vehicleIds, g_AmountOfVehicles);
	for (int i{ 0 }; i < g_AmountOfVehicles; ++i)
	{
		g_pVehicles[i] = new Vehicle(vehicleIds[i], GetRandomNumber(20, 200));
		g_pVehicles[i]->SetYPos(laneBottomOrigin + (laneHeight * i));
	}
}

void ShuffleArray(int* pArray, int arraySize)
{
	const int nrOfSwaps{ 10 };
	int swapIndex{};
	int swapWith{};
	for (int i{ 0 }; i < nrOfSwaps; ++i)
	{
		do
		{
			swapIndex = (int)GetRandomNumber(0, arraySize, false);
			swapWith = (int)GetRandomNumber(0, arraySize, false);
		} while (swapWith == swapIndex);
		pArray[swapIndex] = pArray[swapIndex] + pArray[swapWith];
		pArray[swapWith] = pArray[swapIndex] - pArray[swapWith];
		pArray[swapIndex] = pArray[swapIndex] - pArray[swapWith];
	}
}

void PrintInstructions()
{
	std::cout << "Press 'R' to reset." << std::endl;
	std::cout << "Press 'P' to pause/unpause" << std::endl;
	std::cout << "Use the arrow keys to move the chicken." << std::endl;
}

void DrawStreet()
{
	utils::DrawTexture(g_Street, Point2f{ 0, 0 });
}

void DrawChicken()
{
	Rectf chickenRect{ g_ChickenPosition.x, g_ChickenPosition.y, g_ChickenSideLength, g_ChickenSideLength };
	utils::DrawTexture(g_Chicken, chickenRect, GetChickenSourceRect());
}

void DrawVehicles()
{
	for (int i{ 0 }; i < g_AmountOfVehicles; ++i)
	{
		g_pVehicles[i]->Draw();
	}
}

void DrawMessage(std::string message)
{
	const int fontSize{ 40 };
	const std::string fontPath{ "Resources/consola.ttf" };
	const Color4f fontColour{ 1.0f, 1.0f, 1.0f, 1.0f };
	const Color4f textBackground{ 0.0f, 0.0f, 0.0f, 0.3f };
	Texture textTexture{};
	if (TextureFromString(message, fontPath, fontSize, fontColour, textTexture))
	{
		float left{ (g_WindowWidth - textTexture.width) / 2 };
		float bottom{ (g_WindowHeight - textTexture.height) / 2 };
		Point2f textOrigin{ left, bottom };
		SetColor(textBackground);
		FillRect(textOrigin, textTexture.width, textTexture.height);
		DrawTexture(textTexture, textOrigin);
		DeleteTexture(textTexture);
	}
}

void UpdateChicken(float elapsedSec)
{
	const float chickenSpeed{ 100 };
	const float winHeight{ 43 };
	if (g_GameState != GameState::WIN)
	{
		switch (g_ChickenDirection)
		{
		case ChickenDirection::LEFT:
			g_ChickenPosition.x -= chickenSpeed * elapsedSec;
			break;
		case ChickenDirection::RIGHT:
			g_ChickenPosition.x += chickenSpeed * elapsedSec;
			break;
		}
		if (g_IsGoingDown)
			g_ChickenPosition.y -= chickenSpeed * elapsedSec;
		if (g_ChickenPosition.y + g_ChickenSideLength <= winHeight)
			g_GameState = GameState::WIN;
	}
}

void UpdateVehicles(float elapsedSec)
{
	for (int i{ 0 }; i < g_AmountOfVehicles; ++i)
		g_pVehicles[i]->Update(elapsedSec, g_WindowWidth);
}

void CheckChickenCollision()
{
	Rectf chicken{ g_ChickenPosition.x, g_ChickenPosition.y, g_ChickenSideLength, g_ChickenSideLength };
	Point2f chickenCentre{ GetCenterOfRectangle(chicken) };
	for (int i{ 0 }; i < g_AmountOfVehicles; ++i)
	{
		if (g_pVehicles[i]->CheckColision(chickenCentre))
		{
			g_GameState = GameState::LOSE;
			return;
		}
	}
}

void DeleteVehicles()
{
	for (int i = 0; i < g_AmountOfVehicles; i++)
	{
		delete g_pVehicles[i];
		g_pVehicles[i] = nullptr;
	}
}

void Reset()
{
	ResetChicken();
	ResetVehicles();
	g_GameState = GameState::PLAY;
}

void ResetChicken()
{
	g_ChickenPosition.x = (g_WindowWidth - (g_Chicken.width / 3)) / 2;
	g_ChickenPosition.y = g_WindowHeight - 20;
}

void ResetVehicles()
{
	for (int i{ 0 }; i < g_AmountOfVehicles; ++i)
		g_pVehicles[i]->Reset();
}

Rectf GetChickenSourceRect()
{
	Rectf sourceRect{};
	sourceRect.bottom = g_Chicken.height;
	sourceRect.left = g_Chicken.height * (int)g_ChickenDirection;
	sourceRect.width = g_Chicken.height;
	sourceRect.height = g_Chicken.height;
	return sourceRect;
}



#pragma endregion ownDefinitions