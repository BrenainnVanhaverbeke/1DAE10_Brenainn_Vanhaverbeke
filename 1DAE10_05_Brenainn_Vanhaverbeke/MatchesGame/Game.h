#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Matches Game - Vanhaverbeke, Brenainn - 1DAE10" };

// Change the window dimensions here
float g_WindowWidth{ 600 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

const int g_Border{20};
const int g_DefaultOffset{ 10 };
const int g_MatchWidth{ 5 };
const int g_MatchHeight{ 50 };
const int g_MatchHeadHeight{ g_MatchHeight / 5 };
const Color4f g_MatchHeadColour{ 0.98f, 0.98f, 0.39f, 1 };
const Color4f g_MatchBodyColour{1.0f, 0.4f, 0.4f, 1.0f};

int g_MatchesPool{ 21 };
int g_PlayerMatchesPool{ 0 };
int g_ComputerMatchesPool{ 0 };
std::string g_PlayerMoves{ "Your moves: " };
std::string g_ComputerMoves{ "PC moves: " };
bool g_IsPlaying{ true };
bool g_PlayerVictory{ false };
bool g_ComputerVictory{ false };


// Declare your own functions here

void DrawMatches();
void DrawMatchPool(int amountOfMatches, float offsetX, float offsetY);
void HandlePlayerMove(int amountToDraw);
void HandleComputerMove();
void HandleVictory();
int GenerateRandomInt(int min, int max);

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
