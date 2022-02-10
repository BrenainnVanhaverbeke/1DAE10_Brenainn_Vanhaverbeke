#pragma once
using namespace utils;
class Vehicle;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Exam 58 - Vanhaverbeke, Brenainn - 1DAE GD10" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation

enum class GameState
{
	PLAY,
	PAUSE,
	WIN,
	LOSE,
	RESET,
	END
};

enum class ChickenDirection
{
	DOWN_IDLE,
	LEFT,
	RIGHT,
	END
};

#pragma region ownDeclarations
// Declare your own global variables here

const float g_ChickenSideLength{ 20 };
const int g_AmountOfVehicles{ 5 };

Texture g_Street{};
Texture g_Chicken{};
Vehicle* g_pVehicles[g_AmountOfVehicles]{ nullptr };

Point2f g_ChickenPosition{};
GameState g_GameState{ GameState::RESET };
ChickenDirection g_ChickenDirection{ ChickenDirection::DOWN_IDLE };
bool g_IsGoingDown{ false };

// Declare your own functions here

void InitStreetTexture();
void InitChicken();
void InitVehicles();
void PrintInstructions();

void DrawStreet();
void DrawChicken();
void DrawVehicles();
void DrawMessage(std::string message);

void UpdateChicken(float elapsedSec);
void UpdateVehicles(float elapsedSec);
void CheckChickenCollision();

void DeleteVehicles();

void Reset();
void ResetChicken();
void ResetVehicles();
Rectf GetChickenSourceRect();
void ShuffleArray(int* pArray, int arraySize);

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
