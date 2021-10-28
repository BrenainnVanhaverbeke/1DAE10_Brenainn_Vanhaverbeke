#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Concentric Lines - Vanhaverbeke, Brenainn - 1DAE10" };

// Change the window dimensions here
float g_WindowWidth{ 630 };
float g_WindowHeight{ 360 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

enum Colour
{
	red,
	green,
	blue,
	numberOfColours
};

float g_LineStep{ 9 };

Colour g_Colour { red };
Point2f g_MousePosition{};


// Declare your own functions here

void DrawLines();
void DrawVerticalLines();
void DrawHorizontalLines();

Color4f GetCurrentColour();


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
