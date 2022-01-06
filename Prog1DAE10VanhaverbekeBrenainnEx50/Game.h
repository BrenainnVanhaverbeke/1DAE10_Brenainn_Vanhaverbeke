#pragma once
using namespace utils;
class Tile;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Ex50 - Vanhaverbeke Brenainn - 1 DAE GD10" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

const int g_GridColumns{ 2 };
const int g_GridRows{ 2 };
const int g_NrOfTiles{ g_GridColumns * g_GridRows };
const int g_NrOfAnimals{ 6 };

bool g_IsWon{ false };
Tile* g_pTiles[g_NrOfTiles]{};

// Declare your own functions here

#pragma endregion ownDeclarations

void InitialiseTiles();

void DrawTiles();
void DrawBorder();
void DrawAnimalName();

void CheckWin();
void RandomiseTiles();
void DeactivateTiles();

void DeleteTiles();

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
