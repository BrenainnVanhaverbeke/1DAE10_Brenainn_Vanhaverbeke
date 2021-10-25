#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Curves - Vanhaverbeke, Brenainn - 1DAE10" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

const int columns = 2;
const int rows = 1;
const float g_DefaultOffset = g_WindowHeight / (g_WindowHeight / 10);
const float g_DefaultHeight = (g_WindowHeight - g_DefaultOffset * (rows + 1)) / rows;
const float g_DefaultWidth = (g_WindowWidth - g_DefaultOffset * (columns + 1)) / columns;

const Color4f g_Red{ 1,0,0,1 };

// Declare your own functions here

void DrawPolygonShape(int column, int row, int sides);
void DrawCrosier(int column, int row, int windings);

float GetOffsetX(int nthElement);
float GetOffsetY(int nthElement);
float DegreesToRadian(float degrees);
Point2f GetCoordinatesFromRadian(float radius, float radian, float xOffset, float yOffset);

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
