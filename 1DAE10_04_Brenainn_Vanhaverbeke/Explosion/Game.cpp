// Vanhaverbeke, Brenainn - 1DAE10

#include "pch.h"
#include "Game.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	InitialiseBomb();
}

void Draw()
{
	ClearBackground(0.62f, 0.62f, 0.62f);
	DrawBomb();
	if (g_IsExploding)
		DrawExplosion();

}

void Update(float elapsedSec)
{
	UpdateExplosion();
}

void End() {}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key) {}

void OnKeyUpEvent(SDL_Keycode key) {}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e) {}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e) {}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	if (IsBombClicked((float)e.x, (float)e.y) && e.button == SDL_BUTTON_LEFT)
	{
		g_Black.a = 0.5f;
		g_IsExploding = true;
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here
void InitialiseBomb()
{
	float left = (g_WindowWidth / 2) - (g_BombSide / 2);
	float bottom = (g_WindowHeight / 2) - (g_BombSide / 2);
	g_Bomb = Rectf{ left, bottom, g_BombSide, g_BombSide };
}

bool IsBombClicked(float mouseX, float mouseY)
{
	mouseY = g_WindowHeight - mouseY;
	bool inBomb{ g_Bomb.left <= mouseX && mouseX <= g_Bomb.width + g_Bomb.left };
	if (inBomb)
		inBomb = g_Bomb.bottom <= mouseY && mouseY <= g_Bomb.height + g_Bomb.bottom;
	return inBomb;
}

void DrawBomb()
{
	SetColor(g_Black);
	FillRect(g_Bomb);
}

void DrawExplosion()
{
	if (g_IsExploding)
	{
		SetColor(g_Red);
		FillRect(g_Bomb.left + g_Offset, g_Bomb.bottom + g_Offset, g_BombSide, g_BombSide);
		FillRect(g_Bomb.left - g_Offset, g_Bomb.bottom - g_Offset, g_BombSide, g_BombSide);
		FillRect(g_Bomb.left - g_Offset, g_Bomb.bottom + g_Offset, g_BombSide, g_BombSide);
		FillRect(g_Bomb.left + g_Offset, g_Bomb.bottom - g_Offset, g_BombSide, g_BombSide);
	}
}

void UpdateExplosion()
{
	if (g_IsExploding)
	{
		g_Offset++;
		if (g_WindowWidth < (g_Offset * 2) - (g_BombSide))
		{
			g_IsExploding = false;
			g_Black.a = 1;
			g_Offset = 0;
		}
	}
}

#pragma endregion ownDefinitions