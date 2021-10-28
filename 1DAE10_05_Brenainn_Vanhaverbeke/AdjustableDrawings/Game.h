#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Adjustable Drawings - Vanhaverbeke, Brenainn - 1DAE10" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

const int g_Columns{ 2 };
const int g_Rows{ 2 };
const float g_DefaultOffset{ g_WindowHeight / (g_WindowHeight / 20) };
const float g_DefaultHeight{ (g_WindowHeight - g_DefaultOffset * (g_Rows + 1)) / g_Rows };
const float g_DefaultWidth{ (g_WindowWidth - g_DefaultOffset * (g_Columns + 1)) / g_Columns };
const float g_LineThickness{ 3 };

const Color4f g_SquaresColour{ 0.6f, 1.0f, 0.8f, 1.0f };
const Color4f g_StepsColourEven{ 0.6f, 0.8f, 1.0f, 1.0f };
const Color4f g_StepsColourOdd{ 0.89f, 0.53f, 0.53f, 1.0f };
const Color4f g_SpiralColour{ 0.52f, 0.7f, 0.87f, 1.0f };
const Color4f g_SpinningLinesRed{ 0.89f, 0.53f, 0.53f, 1.0f };
const Color4f g_SpinningLinesGreen{ 0.59f, 1.0f, 0.79f, 1.0f };
const Color4f g_SpinningLinesBlue{ 0.6f, 0.8f, 1.0f, 1.0f };
const Color4f g_SpinningLinesYellow{ 1.0f, 1.0f, 0.6f, 1.0f };

int g_Iterations{ 5 };

// Declare your own functions here
void DrawSquares(int column, int row, int iterations);
void DrawStairs(int column, int row, int iterations);
void DrawSpiral(int column, int row, int iterations);
void DrawSpinningLines(int column, int row, int iterations);

float GetOffsetX(int column);
float GetOffsetY(int row);

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
