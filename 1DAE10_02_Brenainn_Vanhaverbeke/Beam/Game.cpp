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
	ClearBackground(0, 0, 0);

	// Put your own draw statements here
	DrawSquares();
	DrawLines();
}

void DrawSquares()
{
	SetColor(g_Green);
	FillRect(g_Border, g_Border, g_SquareSize, g_SquareSize);
	FillRect(g_WindowWidth - g_SquareSize - g_Border, g_WindowHeight - g_SquareSize - g_Border, g_SquareSize, g_SquareSize);
	SetColor(g_White);
	DrawRect(g_Border, g_Border, g_SquareSize, g_SquareSize);
	DrawRect(g_WindowWidth - g_SquareSize - g_Border, g_WindowHeight - g_SquareSize - g_Border, g_SquareSize, g_SquareSize);
}

void DrawLines()
{
	SetColor(g_White);
	DrawLine(g_Border, g_Border, g_WindowWidth - g_Border, g_WindowHeight - g_Border);
	DrawLine(g_Border + g_SquareSize, g_Border, g_WindowWidth - g_Border, g_WindowHeight - g_Border - g_SquareSize);
	DrawLine(g_Border, g_Border + g_SquareSize, g_WindowWidth - g_Border - g_SquareSize, g_WindowHeight - g_Border);
}

void Update(float elapsedSec)
{
	// process input, do physics 

	// e.g. Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}
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

#pragma endregion ownDefinitions