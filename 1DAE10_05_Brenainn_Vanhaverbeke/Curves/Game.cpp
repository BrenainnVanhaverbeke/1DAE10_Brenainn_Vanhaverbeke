// Vanhaverbeke, Brenainn - 1DAE10

#include "pch.h"
#include "Game.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground();
	DrawPolygonShape(0, 0, 10);
	DrawBezier(1, 0);
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
	//switch (key)
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	////std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//switch (e.button)
	//{
	//case SDL_BUTTON_LEFT:
	//{
	//	//std::cout << "Left mouse button released\n";
	//	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
	//	break;
	//}
	//case SDL_BUTTON_RIGHT:
	//	//std::cout << "Right mouse button released\n";
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	//std::cout << "Middle mouse button released\n";
	//	break;
	//}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

void DrawPolygonShape(int column, int row, int sides)
{
	Point2f center{ Point2f(GetOffsetX(column) + g_DefaultWidth / 2, GetOffsetY(row) + g_DefaultHeight / 2) };
	float nthOfCircle{ 360.0f / (float)sides };
	float radius{ g_DefaultHeight / 3 };
	float radian{};
	for (int i = 0; i < sides; i++)
	{
		radian = DegreesToRadian(nthOfCircle * i);
		Point2f start = GetCoordinatesFromRadian(radius, radian, center.x, center.y);
		radian = DegreesToRadian(nthOfCircle * (i + 1));
		Point2f end = GetCoordinatesFromRadian(radius, radian, center.x, center.y);
		SetColor(g_Red);
		DrawLine(start, end);
	}
}

void DrawBezier()
{

}

float GetOffsetX(int nthElement)
{
	float offset = g_DefaultOffset * (nthElement + 1) + (nthElement * g_DefaultWidth);
	return offset;
}

float GetOffsetY(int nthElement)
{
	return g_DefaultOffset * (nthElement + 1) + (nthElement * g_DefaultHeight);
}

float DegreesToRadian(float degrees)
{
	return degrees * (g_Pi / 180);
}

Point2f GetCoordinatesFromRadian(float radius, float radian, float xOffset, float yOffset)
{
	float x = radius * cosf(radian);
	float y = radius * sinf(radian);
	return Point2f(x + xOffset, y + yOffset);
}

#pragma endregion ownDefinitions