#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Growing Bars - Vanhaverbeke, Brenainn - 1DAE10" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

float g_NrFrames;
float g_DefaultOffset = 20;
float g_DefaultHeight = g_WindowHeight / 5;
float g_DefaultWidth = g_WindowWidth - (g_DefaultOffset * 2);
float g_BorderThickness = 3;
float g_YellowWidth;
float g_RedWidth;

Color4f g_White = Color4f(1, 1, 1, 1);
Color4f g_Yellowish = Color4f(0.78f, 0.78f, 0, 1.0f);
Color4f g_Reddish = Color4f(0.65f, 0, 0, 1.0f);

// Declare your own functions here

void DrawYellowishBar();
void DrawReddishBar();

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
