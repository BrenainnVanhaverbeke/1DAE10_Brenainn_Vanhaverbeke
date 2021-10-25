#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Rectangles - Vanhaverbeke, Brenainn - 1DAE10" };

// Change the window dimensions here
float g_WindowWidth{ 800 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

const float g_MinimumRectangleWidth{ 10 };
const float g_MinimumRectangleHeight{ 10 };
const float g_DefaultBorder{ 10 };
const Color4f g_Black{ 0, 0, 0, 1 };

// Declare your own functions here

void DrawRectangles();
Rectf GenerateRectangle(float border, float minimumWidth, float minimumHeight);
Color4f GenerateRandomColour();
float GenerateRandomFloat(float min, float max);

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
