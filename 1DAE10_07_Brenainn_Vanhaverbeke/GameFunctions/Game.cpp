// Vanhaverbeke, Brenainn - 1DAE10

#include "pch.h"
#include "Game.h"
#include "MyUtils.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground();
	DrawCircles();
	DrawRectangles();
}

void Update(float elapsedSec)
{
	// process input, do physics 

	// e.g. Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}
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
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	Point2f mousePosition{ (float)e.x, (float)g_WindowHeight - e.y };
	g_MouseRect.left = mousePosition.x;
	g_MouseRect.bottom = mousePosition.y;
	g_MouseCircle.center.x = g_MouseRect.left + g_MouseRect.width + g_MouseCircleRadius;
	g_MouseCircle.center.y = g_MouseRect.bottom;
	g_MouseInMouseOverCircle = IsPointInCircle(g_MouseOverCircle, mousePosition);
	g_MouseInMouseOverRect = IsPointInRectangle(g_MouseOverRect, mousePosition);
	g_IsMouseRectOverlapping = IsOverlapping(g_MouseRect, g_MouseOverRect);
	g_IsMouseCircleOverlapping = IsOverlapping(g_MouseCircle, g_MouseOverCircle);
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

void DrawCircles()
{
	SetColor(g_White);
	FillCircle(g_MouseOverCircle);
	if (g_MouseInMouseOverCircle)
	{
		SetColor(g_Red);
		DrawCircle(g_MouseOverCircle, 3.0f);
	}
	SetColor(g_TransparentGreen);
	if (g_IsMouseCircleOverlapping)
		SetColor(g_TransparentRed);
	FillCircle(g_MouseCircle);
}

void DrawRectangles()
{
	SetColor(g_White);
	FillRect(g_MouseOverRect);
	if (g_MouseInMouseOverRect)
	{
		SetColor(g_Red);
		DrawRect(g_MouseOverRect, 3.0f);
	}
	SetColor(g_TransparentGreen);
	if (g_IsMouseRectOverlapping)
		SetColor(g_TransparentRed);
	FillRect(g_MouseRect);
}

#pragma endregion ownDefinitions