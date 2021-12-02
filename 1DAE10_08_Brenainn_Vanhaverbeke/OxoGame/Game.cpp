// Vanhaverbeke, Brenainn - 1DAE10

#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	InitialiseTextures();
	SetGridOrigin();
}

void Draw()
{
	ClearBackground(0.0f, 0.0f, 0.0f);
	DrawGrid();
	DrawPlayerSelection();
}

void Update(float elapsedSec)
{
	if (g_PlayerClicked)
	{
		SetCell(g_LastClickPosition);
		if (CheckWin())
		{
			g_GameWon = true;
			HandleWin();
		}
		else
			g_LeftPlayerTurn = !g_LeftPlayerTurn;
		g_PlayerClicked = false;
	}
}

void End()
{
	for (int i = 0; i < (int)CellState::END; i++)
	{
		DeleteTexture(g_GameTextures[i]);
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
	case SDLK_a:
		if (!g_GameWon)
			g_LeftPlayerSelection = (g_LeftPlayerSelection == CellState::CROSS) ? CellState::CIRCLE : CellState::CROSS;
		break;
	case SDLK_l:
		if (!g_GameWon)
			g_RightPlayerSelection = (g_RightPlayerSelection == CellState::CROSS) ? CellState::CIRCLE : CellState::CROSS;
		break;
	case SDLK_r:
		ResetGame();
	}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e) {}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e) {}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	Point2f mousePosition{ (float)e.x, (float)g_WindowHeight - e.y };
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
		if (!g_GameWon)
		{
			g_LastClickPosition = mousePosition;
			g_PlayerClicked = true;
		}
		break;
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

void InitialiseTextures()
{
	TextureFromFile("Resources/OXO/FreeCell.png", g_GameTextures[(int)CellState::UNMARKED]);
	TextureFromFile("Resources/OXO/WhiteO.png", g_GameTextures[(int)CellState::CIRCLE]);
	TextureFromFile("Resources/OXO/WhiteX.png", g_GameTextures[(int)CellState::CROSS]);
	TextureFromFile("Resources/OXO/GreenO.png", g_GameTextures[(int)CellState::CIRCLE_WIN]);
	TextureFromFile("Resources/OXO/GreenX.png", g_GameTextures[(int)CellState::CROSS_WIN]);
	TextureFromFile("Resources/OXO/Win.png", g_GameTextures[(int)CellState::WIN_BANNER]);
}

void SetGridOrigin()
{
	float gridWidth{ (g_GridColumns * g_SideLength) + (g_GutterSize * (g_GridColumns - 1)) };
	float gridHeight{ (g_GridRows * g_SideLength) + (g_GutterSize * (g_GridRows - 1)) };
	g_GridOrigin.x = (g_WindowWidth - gridWidth) / 2;
	g_GridOrigin.y = (g_WindowHeight - gridHeight) / 2;
}

void SetCell(Point2f& mousePosition)
{
	for (int row{ 0 }; row < g_GridRows; row++)
	{
		for (int column{ 0 }; column < g_GridColumns; column++)
		{
			int index{ GetLinearIndexFrom2DIndex(row, column, g_GridColumns) };
			float left{ g_GridOrigin.x + (g_GutterSize * column + (g_SideLength * column)) };
			float bottom{ g_GridOrigin.y + (g_GutterSize * row + (g_SideLength * row)) };
			Rectf cell{ left, bottom, g_SideLength, g_SideLength };
			if (IsPointInRectangle(cell, mousePosition))
			{
				if (g_Cells[index] == CellState::UNMARKED)
					g_Cells[index] = (g_LeftPlayerTurn) ? g_LeftPlayerSelection : g_RightPlayerSelection;
				return;
			}
		}
	}
}

void DrawGrid()
{
	const Color4f toggledOn{ 1.0f, 0.4f, 0.2f, 1.0f };
	const Color4f togledOff{ 0.8f, 0.8f, 0.8f, 1.0f };
	for (int row{ 0 }; row < g_GridRows; row++)
	{
		for (int column{ 0 }; column < g_GridColumns; column++)
		{
			float left{ g_GridOrigin.x + (g_SideLength * column) + (g_GutterSize * column) };
			float bottom{ g_GridOrigin.y + (g_SideLength * row) + (g_GutterSize * row) };
			int index{ GetLinearIndexFrom2DIndex(row, column, g_GridColumns) };
			Texture& texture{ g_GameTextures[(int)g_Cells[index]] };
			Rectf destination{ left, bottom, g_SideLength, g_SideLength };
			DrawTexture(texture, destination);
		}
	}
}

void DrawPlayerSelection()
{
	Rectf leftPlayerSelection{ g_Border, g_Border, g_SideLength, g_SideLength };
	Rectf rightPlayerSelection{ g_WindowWidth - g_Border - g_SideLength, g_Border, g_SideLength, g_SideLength };
	Texture& leftTexture{ g_GameTextures[(int)g_LeftPlayerSelection] };
	DrawTexture(leftTexture, leftPlayerSelection);
	Texture& rightTexture{ g_GameTextures[(int)g_RightPlayerSelection] };
	DrawTexture(rightTexture, rightPlayerSelection);
}

bool CheckWin()
{
	return CheckHorizontal() || CheckVertical() || CheckDiagonal();
}

bool CheckHorizontal()
{
	bool win{};
	for (int row{ 0 }; row < g_GridRows; row++)
	{
		win = true;
		for (int column = 0; column < g_GridColumns; column++)
		{
			int index{ GetLinearIndexFrom2DIndex(row, column, g_GridColumns) };
			g_WinComboIndexes[column] = index;
			if (g_Cells[index] != ((column % 2 == 0) ? CellState::CIRCLE : CellState::CROSS))
				win = false;
		}
		if (win)
			return win;
	}
	return win;
}

bool CheckVertical()
{
	bool win{};
	for (int column{ 0 }; column < g_GridColumns; column++)
	{
		win = true;
		for (int row = 0; row < g_GridRows; row++)
		{
			int index{ GetLinearIndexFrom2DIndex(row, column, g_GridColumns) };
			g_WinComboIndexes[row] = index;
			if (g_Cells[index] != ((row % 2 == 0) ? CellState::CIRCLE : CellState::CROSS))
				win = false;
		}
		if (win)
			return win;
	}
	return win;
}

bool CheckDiagonal()
{
	bool win{ true };
	for (int i{ 0 }; i < g_GridRows; i++)
	{
		int index{ GetLinearIndexFrom2DIndex(i, i, g_GridColumns) };
		g_WinComboIndexes[i] = index;
		if (g_Cells[index] != ((i % 2 == 0) ? CellState::CIRCLE : CellState::CROSS))
			win = false;
	}
	if (win)
		return win;
	win = true;
	for (int row{ 0 }; row < g_GridRows; row++)
	{
		int column{ g_GridRows - 1 - row };
		int index{ GetLinearIndexFrom2DIndex(row, column, g_GridColumns) };
		g_WinComboIndexes[row] = index;
		if (g_Cells[index] != ((row % 2 == 0) ? CellState::CIRCLE : CellState::CROSS))
			win = false;
	}
	return win;
}

void HandleWin()
{
	for (int i = 0; i < g_GridRows; i++)
	{
		CellState& cell{ g_Cells[g_WinComboIndexes[i]] };
		cell = (cell == CellState::CIRCLE) ? CellState::CIRCLE_WIN : CellState::CROSS_WIN;
		g_LeftPlayerSelection = g_LeftPlayerTurn ? CellState::WIN_BANNER : CellState::UNMARKED;
		g_RightPlayerSelection = !g_LeftPlayerTurn ? CellState::WIN_BANNER : CellState::UNMARKED;
	}
}

void ResetGame()
{
	for (int i = 0; i < g_AmountOfCells; i++)
	{
		g_Cells[i] = CellState::UNMARKED;
	}
	g_LeftPlayerTurn = true;
	g_PlayerClicked = false;
	g_GameWon = false;
}

int GetLinearIndexFrom2DIndex(int rowIndex, int columnIndex, int nrOfColumns)
{
	return rowIndex * nrOfColumns + columnIndex;
}

#pragma endregion ownDefinitions