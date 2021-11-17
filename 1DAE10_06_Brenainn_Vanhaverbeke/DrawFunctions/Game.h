#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Draw Functions - Vanhaverbeke, Brenainn - 1DAE10" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
Color4f g_Red(1.0f, 0.0f, 0.0f, 1.0f);
Color4f g_Green(0.0f, 1.0f, 0.0f, 1.0f);
Color4f g_Blue(0.0f, 0.0f, 1.0f, 1.0f);
Color4f g_White{ 1.0f, 1.0f, 1.0f, 1.0f };
Color4f g_Black{ 0.0f, 0.0f, 0.0f, 1.0f };

// Declare your own functions here
void DrawSquares();
void DrawEquilateralTriangles();
void DrawConcentricTriangles();
void DrawPentagrams();

void DrawSquare(Point2f position, float size, float amountOfSquares);
void DrawEquilateralTriangle(Point2f position, float size, bool isFilled);
void DrawSierpinskiTriangle(Point2f position, float size);
void DrawPentagram(Point2f position, float size);

float ConvertDegreesToRadians(float degrees);
Point2f GetCoordinatesFromRadians(float radius, float radians, Point2f offset);

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
