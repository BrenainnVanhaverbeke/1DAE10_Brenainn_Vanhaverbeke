#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Sprites - Vanhaverbeke, Brenainn - 1DAE10" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
struct Sprite
{
	Texture texture;
	int frames;
	int rows;
	int columns;
	float frameTime;
	int currentFrame;
	float accumulatedTime;
};

Sprite g_KnightSprite{};
const std::string g_KnightSpritePath{ "Resources/Sprites/RunningKnight.png" };
const int g_KnightFrames{ 8 };
const int g_KnightColumns{ 8 };
const float g_KnightFrameTime{ 1 / 10.0f };
float g_KnightPosition{};
float g_KnightSpeed{ 100.0f };
float g_KnightScale{ 5.0f };
float g_KnightBorder{ 10.0f };

Sprite g_TiboSprite{};
const std::string g_TiboSpritePath{ "Resources/Sprites/Tibo.png" };
const int g_TiboFrames{ 25 };
const int g_TiboColumns{ 5 };
const float g_TiboFrameTime{ 1 / 15.0f };

// Declare your own functions here
void InitialiseSprite(Sprite& sprite, std::string path, int frames, int columns, float frameTime);
void InitialiseKnight();
void InitialiseTibo();
void UpdateSprite(float elapsedSec, Sprite& sprite);
void DrawSprite(Sprite& sprite, float left, float bottom, float scale);
Rectf GenerateSourceRectangleForSprite(Sprite& sprite);

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
