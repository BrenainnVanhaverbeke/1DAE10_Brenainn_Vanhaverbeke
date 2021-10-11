#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Static Drawing - Vanhaverbeke, Brenainn - 1DAE10" };

// Change the window dimensions here
float g_WindowWidth{ 800 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

int columns = 2;
int rows = 3;
float g_DefaultOffset = g_WindowHeight / (g_WindowHeight / 10);
float g_DefaultHeight = (g_WindowHeight - g_DefaultOffset * (rows + 1)) / rows;
float g_DefaultWidth = (g_WindowWidth - g_DefaultOffset * (columns + 1)) / columns;
Color4f g_Black = Color4f(0, 0, 0, 1);
Color4f g_Red = Color4f(1, 0, 0, 1);
Color4f g_Green = Color4f(0, 1, 0, 1);
Color4f g_Blue = Color4f(0, 0, 1, 1);
Color4f g_Yellow = Color4f(1, 1, 0, 1);
Color4f g_Magenta = Color4f(1, 0, 1, 1);
Color4f g_Cyan = Color4f(0, 1, 1, 1);
Color4f g_White = Color4f(1, 1, 1, 1);
Color4f g_Bar1 = Color4f(0, 0.54f, 0.54f, 1);
Color4f g_Bar2 = Color4f(0, 0.6f , 0.8f, 1);
Color4f g_Bar3 = Color4f(0, 0.74f, 1, 1);
Color4f g_Bar4 = Color4f(0, 0.54f, 0.8f, 1);

// Declare your own functions here

void DrawHouse(int nthXElement, int nthYElement);
void DrawFlag(int nthXElement, int nthYElement);
void DrawCheckerPattern(int nthXElement, int nthYElement);
void DrawColorBand(int nthXElement, int nthYElement);
void DrawPentagram(int nthXElement, int nthYElement);
void DrawColumnChart(int nthXElement, int nthYElement);

float GetOffsetX(int nthElement);
float GetOffsetY(int nthElement);

Point2f GetCoordinatesFromRadian(float radius, float radian, float xOffset = 0, float yOffset = 0);

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
