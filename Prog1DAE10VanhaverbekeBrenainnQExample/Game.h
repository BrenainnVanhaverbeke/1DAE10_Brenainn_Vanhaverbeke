#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "QExample - Vanhaverbeke, Brenainn - 1DAE10" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

enum ElevatorState
{
	ELEVATOR_MOVING_UP,
	ELEVATOR_MOVING_DOWN,
};

const float g_Border{ 30.0f };
const float g_WallThickness{ 10.0f };
const float g_ElevatorWidth{ 40.0f };
const float g_ElevatorHeight{ 60.0f };
const float g_ElevatorSpeed{ 100.0f };

const Color4f g_Red{ 1.0f, 0.0f, 0.0f, 1.0f };
const Color4f g_Green{ 0.0f, 1.0f, 0.0f, 1.0f };
const Color4f g_Blue{ 0.0f, 0.0f, 1.0f, 1.0f };
const Color4f g_Grey{ 0.5f, 0.5f, 0.5f, 1.0f };

int g_Even{ 0 };
int g_Odd{ 0 };
int g_Any{ 0 };
float g_TotalElapsedTime{ 0.0f };
bool g_IsElevatorMoving{};

Rectf g_Elevator{};
Rectf g_ElevatorInterior{};
ElevatorState g_ElevatorState{};

// Declare your own functions here

void Generate();
void PrintRandomNumbers();
void InitialiseElevator();
void DrawElevator();
void CheckElevatorDirection();

int GenerateRandomNumber(int min, int max);
float GetElevatorSpeed(float elapsedSec, ElevatorState elevatorState);
Color4f GetElevatorInteriorColour(ElevatorState elevatorState);

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
