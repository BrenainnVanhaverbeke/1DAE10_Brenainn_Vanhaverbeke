#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Project name - Name, firstname - 1DAExx" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
float g_Radius = 200.0f;
float g_Circle = 2 * g_Pi;
float g_QuarterCircle = (2 * g_Pi) / 4;
Point2f g_Center = Point2f(g_WindowWidth / 2, g_WindowHeight / 2);

Color4f g_Red = Color4f(1, 0, 0, 1);

// Declare your own functions here

Point2f GetCoordinatesFromRadian(float radius, float radian, float xOffset, float yOffset);
float DegreesToRadian(float degrees);

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
