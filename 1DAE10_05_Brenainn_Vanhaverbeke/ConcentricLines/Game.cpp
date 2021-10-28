// Vanhaverbeke, Brenainn - 1DAE10

#include "pch.h"
#include "Game.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
}

void Draw()
{
	ClearBackground();
	DrawLines();
}

void Update(float elapsedSec)
{
}

void End()
{
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{

}

void OnKeyUpEvent(SDL_Keycode key)
{
	switch (key)
	{
	case SDLK_RIGHT:
		g_Colour =  Colour((int)((g_Colour + 1) % (int)Colour::numberOfColours));
		break;
	}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	g_MousePosition = Point2f{ (float)e.x, g_WindowHeight - (float)e.y };
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

void DrawLines()
{
	SetColor(GetCurrentColour());
	DrawVerticalLines();
	DrawHorizontalLines();

}

void DrawVerticalLines()
{
	Point2f lineStart{};
	for (int i{ 0 }; i <= g_WindowWidth / g_LineStep; i++)
	{
		lineStart = Point2f{ i * g_LineStep, 0 };
		DrawLine(lineStart, g_MousePosition);
		lineStart.y += g_WindowHeight;
		DrawLine(lineStart, g_MousePosition);
	}
}

void DrawHorizontalLines()
{
	Point2f lineStart{};
	for (int i{ 0 }; i <= g_WindowHeight / g_LineStep; i++)
	{
		lineStart = Point2f{ 0, i * g_LineStep };
		DrawLine(lineStart, g_MousePosition);
		lineStart.x += g_WindowWidth;
		DrawLine(lineStart, g_MousePosition);
	}
}

Color4f GetCurrentColour()
{
	switch (g_Colour)
	{
	case red:
		return Color4f{ 1.0f, 0.0f, 0.0f, 1.0f };
	case green:
		return Color4f{ 0.0f, 1.0f, 0.0f, 1.0f };
	case blue:
		return Color4f{ 0.0f, 0.0f, 1.0f, 1.0f };
	default:
		return Color4f{ 0.0f, 0.0f, 0.0f, 0.0f };
	}
}

#pragma endregion ownDefinitions