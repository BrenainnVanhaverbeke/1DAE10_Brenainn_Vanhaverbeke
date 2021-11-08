#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Q-Week 42 - Brenainn, Vanhaverbeke - 1DAE10" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

enum CircleState
{
	GROWING,
	SHRINKING,
	WAITING
};

const Color4f g_Red{ 1.0f, 0.0f, 0.0f, 1.0f };
const float g_MinSpeed{ 0.2f };
const float g_MaxSpeed{ 5.0f };
const float g_SpeedIncrement{ 0.4f };

float g_MaxRadius{};
float g_CurrentSpeed{ 3.0f };

Ellipsef g_Circle{};
Point2f g_MouseClickPosition{};
Color4f g_CurrentColour{};
CircleState g_CircleState{ CircleState::WAITING };	

// Declare your own functions here

void PrintLetters();
void DrawCircle();
void HandleCircleGrowing();
void HandleCircleShrinking();

bool CheckWindowCollision();
float GetRandomNumber(int min, int max);
Color4f GetRandomColour();

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
