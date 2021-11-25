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
	DrawClockHands();
}

void Update(float elapsedSec)
{
	g_NumberOfFrames++;
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
float DegreesToRadian(float degrees)
{
	return degrees * (g_Pi / 180);
}

Point2f GetCoordinatesFromRadian(float radius, float radian, float xOffset, float yOffset)
{
	float x = radius * (float)cos(radian);
	float y = radius * (float)sin(radian);
	return Point2f(x + xOffset, y + yOffset);
}

void DrawClockHands()
{
	CalculateHand(g_LargeRotationSpeed, g_Radius);
	CalculateHand(g_SmallRotationSpeed, g_SmallRadius);
}

void CalculateHand(float rotationSpeed, float radius)
{
	float angle = rotationSpeed * ((int)g_NumberOfFrames % (int)(g_LargeFullRotation * 12));
	float topAngle = angle + g_HandOffest;
	float bottomAngle = angle - g_HandOffest;
	float radian = DegreesToRadian(angle) * -1;
	float topRadian = DegreesToRadian(topAngle) * -1;
	float bottomRadian = DegreesToRadian(bottomAngle) * -1;
	float segmentRadius = radius * 0.3f;
	Point2f topCoordinates = GetCoordinatesFromRadian(segmentRadius, topRadian, g_Center.x, g_Center.y);
	Point2f bottomCoordinates = GetCoordinatesFromRadian(segmentRadius, bottomRadian, g_Center.x, g_Center.y);
	Point2f handEndpoint = (GetCoordinatesFromRadian(radius, radian, g_Center.x, g_Center.y));
	DrawClockHand(topCoordinates, bottomCoordinates, handEndpoint);
}

void DrawClockHand(Point2f topCoordinates, Point2f bottomCoordinates, Point2f endPoint)
{
	DrawLine(g_Center, topCoordinates);
	DrawLine(g_Center, bottomCoordinates);
	DrawLine(topCoordinates, endPoint);
	DrawLine(bottomCoordinates, endPoint);
}

#pragma endregion ownDefinitions