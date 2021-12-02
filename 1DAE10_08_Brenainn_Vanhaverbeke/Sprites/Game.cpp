// Vanhaverbeke, Brenainn - 1DAE10

#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	InitialiseSprite(g_KnightSprite, g_KnightSpritePath, g_KnightFrames, g_KnightColumns, g_KnightFrameTime);
	InitialiseSprite(g_TiboSprite, g_TiboSpritePath, g_TiboFrames, g_TiboColumns, g_TiboFrameTime);
}

void Draw()
{
	const float knightBottomPosition{ g_WindowHeight - g_KnightBorder - (g_KnightSprite.texture.height * g_KnightScale) };
	ClearBackground();
	DrawSprite(g_KnightSprite, g_KnightPosition, knightBottomPosition, g_KnightScale);
	DrawSprite(g_TiboSprite, 0.0f, 0.0f, 1.0f);
}

void Update(float elapsedSec)
{
	g_KnightPosition += g_KnightSpeed * elapsedSec;
	if (g_WindowWidth < g_KnightPosition)
		g_KnightPosition -= (g_WindowWidth + ((g_KnightSprite.texture.width / g_KnightSprite.columns) * g_KnightScale));
	UpdateSprite(elapsedSec, g_KnightSprite);
	UpdateSprite(elapsedSec, g_TiboSprite);
}

void End()
{
	DeleteTexture(g_KnightSprite.texture);
	DeleteTexture(g_TiboSprite.texture);
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key) {}

void OnKeyUpEvent(SDL_Keycode key) {}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e) {}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e) {}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e) {}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

void InitialiseKnight()
{
	bool isCreated{ TextureFromFile("Resources/Sprites/RunningKnight.png", g_KnightSprite.texture) };
	if (isCreated)
	{
		g_KnightSprite.columns = 8;
		g_KnightSprite.frames = 8;
		g_KnightSprite.rows = g_KnightSprite.frames / g_KnightSprite.columns;
		g_KnightSprite.currentFrame = 0;
		g_KnightSprite.accumulatedTime = 0.0f;
		g_KnightSprite.frameTime = 1 / 10.0f;
	}
	else
		std::cout << "Failed to load image RunningKnight.png" << std::endl;
}

void InitialiseTibo()
{
	bool isCreated{ TextureFromFile("Resources/Sprites/Tibo.png", g_TiboSprite.texture) };
	if (isCreated)
	{
		g_TiboSprite.columns = 5;
		g_TiboSprite.frames = 25;
		g_TiboSprite.rows = g_TiboSprite.frames / g_TiboSprite.columns;
		g_TiboSprite.currentFrame = 0;
		g_TiboSprite.accumulatedTime = 0.0f;
		g_TiboSprite.frameTime = 1 / 15.0f;
	}
	else
		std::cout << "Failed to load image TiboSprite.png" << std::endl;
}

void InitialiseSprite(Sprite& sprite, std::string path, int frames, int columns, float frameTime)
{
	bool isCreated{ TextureFromFile(path, sprite.texture) };
	if (isCreated)
	{
		sprite.frames = frames;
		sprite.columns = columns;
		sprite.rows = frames / columns;
		sprite.currentFrame = 0;
		sprite.accumulatedTime = 0.0f;
		sprite.frameTime = frameTime;
	}
	else
		std::cout << "Failed to load image " << path << std::endl;
}

void UpdateSprite(float elapsedSec, Sprite& sprite)
{
	sprite.accumulatedTime += elapsedSec;
	if (sprite.frameTime < sprite.accumulatedTime)
	{
		++sprite.currentFrame %= sprite.frames;
		sprite.accumulatedTime -= sprite.frameTime;
	}
}

void DrawSprite(Sprite& sprite, float left, float bottom, float scale)
{
	Rectf sourceRectangle{ GenerateSourceRectangleForSprite(sprite) };
	Rectf destinationRectangle{};
	destinationRectangle.left = left;
	destinationRectangle.bottom = bottom;
	destinationRectangle.width = sourceRectangle.width * scale;
	destinationRectangle.height = sourceRectangle.height * scale;
	DrawTexture(sprite.texture, destinationRectangle, sourceRectangle);
}

Rectf GenerateSourceRectangleForSprite(Sprite& sprite)
{
	Rectf sourceRectangle{};
	sourceRectangle.width = sprite.texture.width / sprite.columns;
	sourceRectangle.height = sprite.texture.height / sprite.rows;
	sourceRectangle.left = (float)((sprite.currentFrame % sprite.columns) * sourceRectangle.width);
	sourceRectangle.bottom = (float)((sprite.currentFrame / sprite.columns + 1) * sourceRectangle.height);
	return sourceRectangle;
}

#pragma endregion ownDefinitions