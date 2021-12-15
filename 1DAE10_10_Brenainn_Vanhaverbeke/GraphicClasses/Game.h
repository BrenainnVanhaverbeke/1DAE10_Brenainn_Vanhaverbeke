#pragma once
using namespace utils;
class Fraction;
class Light;
class DaeEllipse;

#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Project name - Name, firstname - 1DAExx" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
const int g_AmountOfFractions{ 6 };
const int g_AmountOfLightRows{ 4 };
const int g_AmountOfLightColumns{ 2 };
const int g_AmountOfLights{ g_AmountOfLightRows * g_AmountOfLightColumns };
const int g_AmountOfDaeEllipses{ 3 };

Color4f g_Black{ 0.0f, 0.0f, 0.0f, 1.0f };

Fraction* g_pFractions[g_AmountOfFractions] { nullptr };
Light* g_pLights[g_AmountOfLights]{ nullptr };
DaeEllipse* g_pDaeEllipses[g_AmountOfDaeEllipses]{ nullptr };

// Declare your own functions here
void InitialiseFractions();
void InitialiseLights();
void InitialiseDaeEllipses();

void HitLights(const Point2f& mousePosition);
void ActivateDaeEllipses(const Point2f mousePosition);

void DrawFractions();
void DrawLights();
void DrawDaeEllipses();

void DeleteFractions();
void DeleteLights();
void DeleteDaeEllipses();

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
