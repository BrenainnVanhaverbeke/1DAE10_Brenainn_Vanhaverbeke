#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Events And Drawing - Vanhaverbeke, Brenainn - 1DAE10" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
unsigned int g_NumberOfFrames{ 0 };
bool g_IsRectangleClicked{ false };
bool g_IsRectangleRunning{ false };
bool g_IsLineBouncing{ true };
float g_DefaultSpeed{ 5 };

Rectf g_Rectangle{};
Rectf g_BackupRectangle{};

Point2f g_StartPoint{};
Point2f g_StartPointSpeed{};
Point2f g_EndPoint{};
Point2f g_EndPointSpeed{};

Color4f g_Grey(0.56f, 0.61f, 0.62f, 1);
Color4f g_Green(0, 1, 0, 1);
Color4f g_LineColour{};
// Declare your own functions here

void RectangleSetup();
void LineSetup();
void DrawRectangle();
void DrawBouncingLine();
float GenerateRandomFloat(float min, float range);
bool IsClickInRectangle(float x, float y);
void RunningRectangleUpdate();
void BouncingLineUpdate();
void RunningRectangleEvents(SDL_Keycode key);
void BouncingLineEvents(SDL_Keycode key);
void ClickRectangleEvents(SDL_MouseButtonEvent e);
float AngleToRadians(float angle);

Rectf GenerateRectangle(float border = 50, float minimumWidth = 60, float minimumHeight = 40);
Point2f GetSpeedFromRadian(float speed, float radian);
Color4f GenerateRandomColour();

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
