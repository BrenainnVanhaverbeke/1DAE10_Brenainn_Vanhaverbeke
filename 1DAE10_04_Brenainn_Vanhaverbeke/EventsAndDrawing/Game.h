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
bool g_RectangleClicked{ false };
bool g_RectangleRunning{ false };
bool g_FlipStartLineX{ false };
bool g_FlipStartLineY{ false };
bool g_FlipEndLineX{ false };
bool g_FlipEndLineY{ false };

Rectf g_Rectangle;
Rectf g_BackupRectangle;

Point2f g_StartLine;
Point2f g_EndLine;

Color4f g_Grey(0.56f, 0.61f, 0.62f, 1);
Color4f g_Green(0, 1, 0, 1);
// Declare your own functions here

void RectangleSetup();
void LineSetup();
void DrawRectangle();
float GenerateRandomFloat(float min, float range);
bool IsClickInRectangle(float x, float y);
void ClickRectangleEvents(SDL_MouseButtonEvent e);
void RunningRectangleUpdate();
void RunningRectangleEvents(SDL_Keycode key);
Rectf GenerateRectangle();

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
