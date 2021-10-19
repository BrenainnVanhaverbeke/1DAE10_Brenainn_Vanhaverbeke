#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Project name - Name, firstname - 1DAExx" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
float g_IsExploding{ false };
float g_BombSide{ 75 };
float g_Offset{ 0 };

Color4f g_Black{ 0, 0, 0, 1 };
Color4f g_Red{ 1, 0.08f, 0.08f, 1 };
Rectf g_Bomb{};

// Declare your own functions here
bool IsBombClicked(float mouseX, float mouseY);
void InitialiseBomb();
void DrawBomb();
void DrawExplosion();
void UpdateExplosion();

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
