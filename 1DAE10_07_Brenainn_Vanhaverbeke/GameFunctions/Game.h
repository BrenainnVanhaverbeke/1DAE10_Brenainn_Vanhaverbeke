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
const float g_MouseRectHeight{ 20.0f };
const float g_MouseRectWidth{ 50.0f };
const float g_MouseCircleRadius{ 25.0f };

const Point2f g_MouseOverCircleCenter{ g_WindowWidth / 2, 100.0f };
const Point2f g_MouseOverRectOrigin{ 100.0f, g_WindowHeight / 2 };

const Rectf g_MouseOverRect{ g_MouseOverRectOrigin.x, g_MouseOverRectOrigin.y, 100.0f, 50.0f };

const Circlef g_MouseOverCircle{ g_MouseOverCircleCenter, 50.0f };

const Color4f g_White{ 1.0f, 1.0f, 1.0f, 1.0f };
const Color4f g_Red{ 1.0f, 0.0f, 0.0f, 1.0f };
const Color4f g_TransparentGreen{ 0.0f, 1.0f, 0.0f, 0.5f };
const Color4f g_TransparentRed{ 1.0f, 0.0f, 0.0f, 0.5f };

bool g_MouseInMouseOverCircle{};
bool g_MouseInMouseOverRect{};
bool g_IsMouseRectOverlapping{};
bool g_IsMouseCircleOverlapping{};

Rectf g_MouseRect{ 0, 0, g_MouseRectWidth, g_MouseRectHeight };

Circlef g_MouseCircle{ Point2f{g_MouseRect.left + g_MouseRect.width + g_MouseCircleRadius, g_MouseRect.bottom}, g_MouseCircleRadius };

// Declare your own functions here

void DrawCircles();
void DrawRectangles();

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
