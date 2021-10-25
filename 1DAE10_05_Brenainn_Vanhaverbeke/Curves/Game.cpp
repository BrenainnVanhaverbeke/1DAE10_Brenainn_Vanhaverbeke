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
	DrawCrosier(1, 0, 8);
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
	float radiusOffset{ 0 };
	float radian{};
	for (int i = 0; i < sides; i++)
	{
		radiusOffset = (float)((int)(radiusOffset + 5) % 25);
		radian = DegreesToRadian(nthOfCircle * i);
		Point2f start = GetCoordinatesFromRadian(radius, radian, center.x, center.y);
		radian = DegreesToRadian(nthOfCircle * (i + 1));
		Point2f end = GetCoordinatesFromRadian(radius, radian, center.x, center.y);
		SetColor(g_Red);
		DrawLine(start, end);
	}
}

void DrawCrosier(int column, int row, int windings)
{
	Point2f center{ Point2f(GetOffsetX(column) + g_DefaultWidth / 2, GetOffsetY(row) + g_DefaultHeight / 2) };
	DrawArc(center, 10, 10, 0, 2 * g_Pi);
	float a{ g_WindowWidth / 4 };
	float theta{ 0.01f };
	float r{};
	for (int b{ 0 }; b < windings; b++)
	{
		r = a / sqrtf(theta);
		theta += 0.01f;
	}
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