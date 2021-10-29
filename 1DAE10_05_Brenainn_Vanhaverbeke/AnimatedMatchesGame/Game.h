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

const float g_Border{ 20 };
const float g_DefaultOffset{ 10 };
const float g_DefaultSpeed{ 5 };
const float g_MatchWidth{ 5 };
const float g_MatchHeight{ 50 };
const float g_MatchHeadHeight{ g_MatchHeight / 5 };
const Color4f g_MatchHeadColour{ 0.98f, 0.98f, 0.39f, 1 };
const Color4f g_MatchBodyColour{ 1.0f, 0.4f, 0.4f, 1.0f };

int g_MatchesPool{ 21 };
int g_PlayerMatchesPool{ 0 };
int g_ComputerMatchesPool{ 0 };
int g_LastPlayerDraw{};
int g_LastComputerDraw{};
std::string g_PlayerMoves{ "Your moves: " };
std::string g_ComputerMoves{ "PC moves: " };
bool g_IsPlaying{ true };
bool g_IsAnimating{ false };
bool g_PlayerVictory{ false };
bool g_ComputerVictory{ false };

Point2f g_MatchPositions[21]{};
Point2f g_MatchDestinations[21]{};
Point2f g_MatchSpeed[21]{};

// Declare your own functions here

void InitialiseMatches();
void DrawMatches();
//void DrawMatchPool(int amountOfMatches, float offsetX, float offsetY);
void HandlePlayerMove(int amountToDraw);
void HandleComputerMove();
void HandleVictory();
int GenerateRandomInt(int min, int max);

float ConvertAngleToRadians(float angle);
void CalculateMatchSpeeds(int amountOfMatches, int totalMatches, float offsetX, float offsetY);
Point2f CalculateMatchPosition(int matchNr, float offsetX, float OoffsetY);
Point2f GetSpeedFromRadians(float radians);

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
