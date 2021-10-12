#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Project name - Name, firstname - 1DAExx" };

// Change the window dimensions here
float g_WindowWidth{ 550 };
float g_WindowHeight{ 450 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
float g_SquareSize = 200;
float g_Border = 10;
Color4f g_Green = Color4f(0, 1, 0, 1);
Color4f g_White = Color4f(1, 1, 1, 1);

// Declare your own functions here

void DrawSquares();
void DrawLines();

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
