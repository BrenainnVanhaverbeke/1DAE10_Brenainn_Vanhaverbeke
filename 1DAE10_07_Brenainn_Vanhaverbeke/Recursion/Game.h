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
Color4f g_Red{ 1.0f, 0.0f, 0.0f, 1.0f };
Color4f g_Green{ 0.0f, 1.0f, 0.0f, 1.0f };
Color4f g_Blue{ 0.0f, 0.0f, 1.0f, 1.0f };

// Declare your own functions here
void DrawEquilateralTriangle(const Point2f& position, float size, bool isFilled);
void DrawEquilateralSierpinskiTriangle(const Point2f& position, float size);
void DrawSierpinskiTriangle(const Point2f& left, const Point2f& top, const Point2f& right);
Point2f GetMiddle(const Point2f& pointA, const Point2f& pointB);

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
