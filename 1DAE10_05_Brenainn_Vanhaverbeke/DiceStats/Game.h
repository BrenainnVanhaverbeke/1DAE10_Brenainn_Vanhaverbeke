#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Dice Stats - Vanhaverbeke, Brenainn - 1DAE10" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
const float g_DefaultBorder{ 5 };
const float g_DefaultHeight{ 20 };

const Color4f g_Blue{ 0, 0, 1, 1 };
const Color4f g_Red{ 1, 0, 0, 1 };

int g_Roll1Single{};
int g_Roll2Single{};
int g_Roll3Single{};
int g_Roll4Single{};
int g_Roll5Single{};
int g_Roll6Single{};
int g_Roll2{};
int g_Roll3{};
int g_Roll4{};
int g_Roll5{};
int g_Roll6{};
int g_Roll7{};
int g_Roll8{};
int g_Roll9{};
int g_Roll10{};
int g_Roll11{};
int g_Roll12{};



// Declare your own functions here

int GetDiceRoll(int min, int max);
void IncrementSingleRollFrequencyTable(int diceRoll);
void IncrementDoubleFrequencyTable(int diceRoll);
int GetSingleRollFrequency(int rollNumber);
int GetDoubleRollFrequency(int rollNumber);

void DrawFrequencyBar(int number, int frequency, Color4f colour, float initialOffset = 0);
float GetOffsetY(int number);
Rectf GenerateBar(int number, int frequency, float initialOffset = 0);
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
