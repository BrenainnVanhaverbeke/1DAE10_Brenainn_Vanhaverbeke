#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Shuffle Cards - Vanhaverbeke, Brenainn - 1DAE10" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
const int g_AmountOfCards{ 52 };
const int g_RowsOfCards{ 4 };
const int g_ColumnsOfCards{ g_AmountOfCards / g_RowsOfCards };

Texture g_CardTextures[g_AmountOfCards]{};

// Declare your own functions here

void InitialiseCardTextures();
void ShuffleCards(int amountOfShuffles);
void DrawCards();

int GetLinearIndexFrom2DIndex(int rowIndex, int columnIndex, int nrOfColumns);

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
