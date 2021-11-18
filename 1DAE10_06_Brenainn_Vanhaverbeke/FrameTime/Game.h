#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Project name - Name, firstname - 1DAExx" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

const float g_Gravity{ -9.81f };
const float g_BallRadius{ 20.0f };
const float g_SquareSide{ 25.0f };

const Color4f g_Orange{ 0.82f, 0.32f, 0.0f, 1.0f };
const Color4f g_Yellow{ 1.0f, 1.0f, 0.0f, 1.0f };

int g_NumberOfFrames{ 0 };
float g_AccumulatedTime{ 0 };
float g_FrameRate{ 0 };
float g_HorizontalBallSpeed{ 100 };
float g_VerticalBallSpeed{ 80 };
float g_FreeFallSpeed{ 0 };
bool g_IsFalling{ false };

Ellipsef g_Ball{ g_WindowWidth / 2, g_WindowHeight / 2, g_BallRadius, g_BallRadius };
Rectf g_FreeFallingSquare{ (g_WindowWidth - g_SquareSide) / 2, g_WindowHeight - g_SquareSide, g_SquareSide, g_SquareSide };

// Declare your own functions here

void UpdateStatistics(float elapsedSec);
void UpdateBall(float elapsedSec);
void UpdateFreeFall(float elapsedSec);

void DrawBall();
void DrawFreeFall();

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
