#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Sliding Rectangles- Vanhaverbeke, Brenainn - 1DAE10" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
float g_NrOfFrames;
float g_SquareSide = g_WindowWidth / 5;

Color4f g_Red = Color4f(1, 0, 0, 0.6f);
Color4f g_Green = Color4f(0, 1, 0, 0.6f);
Color4f g_Blue = Color4f(0, 0, 1, 0.6f);
Color4f g_Yellow = Color4f(1, 1, 0, 0.6f);
Color4f g_Black = Color4f(0, 0, 0, 1);

// Declare your own functions here

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
