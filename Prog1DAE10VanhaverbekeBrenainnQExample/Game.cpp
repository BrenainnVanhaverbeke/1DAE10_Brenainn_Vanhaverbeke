// Vanhaverbeke, Brenainn - 1DAE10

#include "pch.h"
#include "Game.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	Generate();
	PrintRandomNumbers();
	InitialiseElevator();
}

void Draw()
{
	ClearBackground();
	DrawElevator();
}

void Update(float elapsedSec)
{
	g_TotalElapsedTime += elapsedSec;
	if (1 <= g_TotalElapsedTime)
	{
		Generate();
		PrintRandomNumbers();
		g_TotalElapsedTime = 0;
	}
	if (g_IsElevatorMoving)
	{
		CheckElevatorDirection();
		float elevatorSpeed{ GetElevatorSpeed(elapsedSec, g_ElevatorState) };
		g_Elevator.bottom += elevatorSpeed;
		g_ElevatorInterior.bottom += elevatorSpeed;
	}
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
	switch (key)
	{
	case SDLK_n:
		Generate();
		PrintRandomNumbers();
		break;
	}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	float correctedY{ g_WindowHeight - e.y };
	bool isWithinWidth{ g_Elevator.left <= e.x && e.x <= g_Elevator.left + g_ElevatorWidth };
	bool isWithinHeight{ g_Elevator.bottom <= correctedY && correctedY <= g_Elevator.bottom + g_ElevatorHeight };
	bool isWithinLeftWall{ (g_Elevator.left <= e.x && e.x <= g_Elevator.left + g_WallThickness) };
	bool isWithinRightWall{ g_Elevator.left + g_ElevatorWidth - g_WallThickness <= e.x && e.x <= g_Elevator.left + g_ElevatorWidth };
	bool isWithinBottomWall{ g_Elevator.bottom <= correctedY && correctedY <= g_Elevator.bottom + g_WallThickness };
	bool isWithinTopWall{ g_Elevator.bottom + g_ElevatorHeight - g_WallThickness <= correctedY && correctedY <= g_Elevator.bottom + g_ElevatorHeight };
	if ((isWithinBottomWall && isWithinWidth) || (isWithinTopWall && isWithinWidth) || (isWithinLeftWall && isWithinHeight) || (isWithinRightWall && isWithinHeight))
		g_IsElevatorMoving = !g_IsElevatorMoving;
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

void Generate()
{
	do
	{
		g_Even = GenerateRandomNumber(0, 10);
		g_Odd = GenerateRandomNumber(0, 10);
		g_Any = GenerateRandomNumber(0, 10);
	} while (g_Even % 2 != 0 || g_Odd % 2 != 1);
}

void PrintRandomNumbers()
{
	printf("Even: %i, odd: %i, any: %i\n", g_Even, g_Odd, g_Any);
}

void InitialiseElevator()
{
	float elevatorLeft{ g_WindowWidth - g_Border - g_ElevatorWidth };
	float elevatorBottom{ g_Border };
	float elevatorWidth{ g_ElevatorWidth };
	float elevatorHeight{ g_ElevatorHeight };
	g_Elevator = Rectf{ elevatorLeft, elevatorBottom, elevatorWidth, elevatorHeight };
	elevatorBottom += g_WallThickness;
	elevatorLeft += g_WallThickness;
	elevatorWidth -= g_WallThickness * 2;
	elevatorHeight -= g_WallThickness * 2;
	g_ElevatorInterior = Rectf{ elevatorLeft, elevatorBottom, elevatorWidth, elevatorHeight };
	g_IsElevatorMoving = false;
}

void DrawElevator()
{
	SetColor(g_Blue);
	FillRect(g_Elevator);
	SetColor(GetElevatorInteriorColour(g_ElevatorState));
	FillRect(g_ElevatorInterior);
}

void CheckElevatorDirection()
{
	if (g_WindowHeight - g_Border <= g_Elevator.bottom + g_ElevatorHeight)
	{
		g_ElevatorState = ELEVATOR_MOVING_DOWN;
	}
	else if (g_Elevator.bottom <= g_Border)
	{
		g_ElevatorState = ELEVATOR_MOVING_UP;
	}
}

float GetElevatorSpeed(float elapsedSec, ElevatorState elevatorState)
{
	switch (elevatorState)
	{
	case ELEVATOR_MOVING_UP:
		return g_ElevatorSpeed * elapsedSec;
	case ELEVATOR_MOVING_DOWN:
		return -(g_ElevatorSpeed * elapsedSec);
	default:
		return 0.0f;
	}
}

Color4f GetElevatorInteriorColour(ElevatorState elevatorState)
{
	if (!g_IsElevatorMoving)
		return g_Grey;
	switch (elevatorState)
	{
	case ELEVATOR_MOVING_UP:
		return g_Red;
	case ELEVATOR_MOVING_DOWN:
		return g_Green;
	default:
		return g_Grey;
	}
}

int GenerateRandomNumber(int min, int amountOfNumbers)
{
	return (rand() % amountOfNumbers) + min;
}

#pragma endregion ownDefinitions