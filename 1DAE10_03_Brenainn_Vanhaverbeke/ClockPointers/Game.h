#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Clock Pointers - Vanhaverbeke, Brenainn - 1DAE10" };

// Change the window dimensions here
float g_WindowWidth{ 400 };
float g_WindowHeight{ 400 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

// Constants
float g_NumberOfFrames = 0;
const float g_LargeFullRotation = 240;
const float g_HandOffest = 10;

// Derived constants
const float g_Radius = (g_WindowWidth + g_WindowHeight) / 8;
const float g_SmallRadius = g_Radius * 0.6f;
const float g_SmallFullRotation = g_LargeFullRotation / 12;
const float g_LargeRotationSpeed = 360.0f / g_LargeFullRotation;
const float g_SmallRotationSpeed = g_LargeRotationSpeed / 12;

const Point2f g_Center = Point2f(g_WindowWidth / 2, g_WindowHeight / 2);

// Declare your own functions here

float DegreesToRadian(float degrees);
Point2f GetCoordinatesFromRadian(float radius, float radian, float xOffset, float yOffset);
void DrawClockHands();
void CalculateHand(float rotationSpeed, float radius);
void DrawClockHand(Point2f topCoordinate, Point2f bottomCoordinate, Point2f endPoint);

#pragma endregion ownDeclarations

#pragma region gameFunctions											
void Start();
void Draw();
void Update(float elapsedSec);
void End();
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key);
void OnKeyUpEvent(SDL_Keycode key);
void OnMouseMotionEvent(const SDL_MouseMotionEvent& e);
void OnMouseDownEvent(const SDL_MouseButtonEvent& e);
void OnMouseUpEvent(const SDL_MouseButtonEvent& e);
#pragma endregion inputHandling
