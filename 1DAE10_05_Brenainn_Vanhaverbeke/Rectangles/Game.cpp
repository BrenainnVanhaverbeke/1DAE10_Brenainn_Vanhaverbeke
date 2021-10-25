// Vanhaverbeke, Brenainn - 1DAE10

#include "pch.h"
#include "Game.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground();
	DrawRectangles();
	Sleep(60);
}

void Update(float elapsedSec)
{
}

void End()
{
	// free game resources here
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{

}

void OnKeyUpEvent(SDL_Keycode key)
{
	//switch (key)
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	////std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//switch (e.button)
	//{
	//case SDL_BUTTON_LEFT:
	//{
	//	//std::cout << "Left mouse button released\n";
	//	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
	//	break;
	//}
	//case SDL_BUTTON_RIGHT:
	//	//std::cout << "Right mouse button released\n";
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	//std::cout << "Middle mouse button released\n";
	//	break;
	//}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

void DrawRectangles()
{
	for (int i = 0; i < 100; i++)
	{
		Rectf randomRectangle{ GenerateRectangle(g_DefaultBorder, g_MinimumRectangleWidth, g_MinimumRectangleHeight) };
		Color4f randomColour = GenerateRandomColour();
		SetColor(randomColour);
		FillRect(randomRectangle);
		SetColor(g_Black);
		DrawRect(randomRectangle);
	}
}

Rectf GenerateRectangle(float border, float minimumWidth, float minimumHeight)
{
	float minX{ border };
	float maxX{ g_WindowWidth - minimumWidth - border };
	float minY{ border };
	float maxY{ g_WindowHeight - minimumHeight - border };
	float randomLeft{ GenerateRandomFloat(minX, maxX - minX) };
	float randomBottom{ GenerateRandomFloat(minY, maxY - minY) };
	float maxWidth{ maxX - randomLeft };
	float maxHeight{ maxY - randomBottom };
	float randomWidth{ GenerateRandomFloat(minimumWidth, maxWidth) };
	float randomHeight{ GenerateRandomFloat(minimumHeight, maxHeight) };
	return Rectf{ randomLeft, randomBottom, randomWidth, randomHeight };
}

Color4f GenerateRandomColour()
{
	float red{ GenerateRandomFloat(0, 255) / 255 };
	float green{ GenerateRandomFloat(0, 255) / 255 };
	float blue{ GenerateRandomFloat(0, 255) / 255 };
	float alpha{ 1 };
	return Color4f{ red, green, blue, alpha };
}

float GenerateRandomFloat(float min, float max)
{
	return (float)((rand() % (int)max) + min);
}

#pragma endregion ownDefinitions