// Vanhaverbeke, Brenainn - 1DAE10

#include "pch.h"
#include "Game.h"
#include "MyUtils.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground(0.0f, 0.0f, 0.0f);
	DrawBall();
	DrawFreeFall();
}

void Update(float elapsedSec)
{
	UpdateStatistics(elapsedSec);
	UpdateBall(elapsedSec);
	UpdateFreeFall(elapsedSec);
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
	if (key == SDLK_s)
		g_IsFalling = true;
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e) {}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e) {}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e) {}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

void UpdateStatistics(float elapsedSec)
{
	g_NumberOfFrames++;
	g_AccumulatedTime += elapsedSec;
	if (g_NumberOfFrames % 100 == 0)
	{
		std::cout << "Number of frames: " << g_NumberOfFrames;
		std::cout << "\t AccumulatedTime: " << g_AccumulatedTime;
		std::cout << "\t Framerate: " << g_NumberOfFrames / g_AccumulatedTime;
		std::cout << std::endl;
	}
}

void UpdateBall(float elapsedSec)
{
	g_Ball.center.x += g_HorizontalBallSpeed * elapsedSec;
	g_Ball.center.y += g_VerticalBallSpeed * elapsedSec;
	if (g_Ball.center.x < g_BallRadius || g_WindowWidth - g_BallRadius < g_Ball.center.x)
		g_HorizontalBallSpeed *= -1;
	if (g_Ball.center.y < g_BallRadius || g_WindowHeight - g_BallRadius < g_Ball.center.y)
		g_VerticalBallSpeed *= -1;
}

void UpdateFreeFall(float elapsedSec)
{
	if (g_IsFalling)
	{
		g_FreeFallSpeed += g_Gravity * elapsedSec;
		g_FreeFallingSquare.bottom += g_FreeFallSpeed * elapsedSec;
		std::cout << "Current velocity: " << g_FreeFallSpeed << std::endl;
		if (g_FreeFallingSquare.bottom + g_SquareSide < 0)
		{
			g_IsFalling = false;
			g_FreeFallingSquare.bottom = g_WindowHeight - g_SquareSide;
			g_FreeFallSpeed = 0.0f;
		}
	}
}

void DrawBall()
{
	SetColor(g_Orange);
	FillEllipse(g_Ball);
}

void DrawFreeFall()
{
	SetColor(g_Yellow);
	FillRect(g_FreeFallingSquare);
}

#pragma endregion ownDefinitions