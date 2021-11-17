#include "pch.h"
#include "Game.h"
#include <iostream>
#include <chrono>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	//TestSum();
	//TestPrint();
	//TestMultiply();
	//TestModulo();
	//TestPrintNumbers();
	//TestCalcElapsedTime();
	//TestPrintMessage();
	//TestIsEven();
	//TestIsLeapYear();
	//TestGetIntRand();
	//TestGetFloatRand();
	TestGetDistance();
	TestCalcCosSin();
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here

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


void TestSum()
{
	std::cout << "Testing Sum();\n";
	std::cout << Sum(50, 30) << std::endl;
	std::cout << Sum(40, 20) << std::endl;
	std::cout << Sum(70, 100) << std::endl;
	std::cout << std::endl;
}

void TestPrint()
{
	std::cout << "Testing print functions.\n";
	PrintChar('a', '\n');
	PrintInt(20, '\n');
	PrintFloat(20.0f, '\n');
	std::cout << std::endl;
}

void TestMultiply()
{
	int a{};
	int b{};
	int c{};
	int d{};
	std::cout << "Testing Multiply()\n";
	std::cout << "Please give 2 numbers, seperated by a space, to multiply. ";
	std::cin >> a >> b;
	PrintInt(Multiply(a, b), '\n');
	std::cout << "Please enter 4 more numbers, seperated by a space. ";
	std::cin >> a >> b >> c >> d;
	PrintInt(Multiply(a, Multiply(b, Multiply(c, d))), '\n');
	std::cout << std::endl;
}

void TestModulo()
{
	int a{};
	int b{};
	std::cout << "Testing Modulo()\n";
	std::cout << "Please give 2 numbers, seperated by a space, to do a modulo operation with. ";
	std::cin >> a >> b;
	PrintInt(Modulo(a, b), '\n');
	std::cout << std::endl;
}

void TestPrintNumbers()
{
	int start{ 10 };
	int end{ 20 };
	std::cout << "Testing PrintNumbers()\n";
	PrintNumbers(start, end);
	std::cout << "Please give 2 numbers, seperated by a space. ";
	std::cin >> start >> end;
	PrintNumbers(start, end);
	std::cout << std::endl;
}

void TestCalcElapsedTime()
{
	std::cout << "Testing CalcElapsedTime()\n";
	std::cout << "This print task took ";
	PrintFloat(CalcElapsedTime(0, 30), ' ');
	std::cout << "milliseconds\n";
	std::cout << "This print task took ";
	PrintFloat(CalcElapsedTime(0, 400), ' ');
	std::cout << "milliseconds\n";
	std::cout << std::endl;
}

void TestPrintMessage()
{
	std::cout << "Testing PrintMessage()\n";
	PrintMessage(0, "No indentation specified.");
	PrintMessage(2, "2 spaces indentation specified.");
	PrintMessage(4, "4 spaces indentation specified.");
	std::cout << std::endl;
}

void TestIsEven()
{
	std::cout << "Testing IsEven()\n";
	std::cout << "41 is " << (IsEven(41) ? "even" : "odd") << std::endl;
	std::cout << "18467 is " << (IsEven(18467) ? "even" : "odd") << std::endl;
	std::cout << "6334 is " << (IsEven(6334) ? "even" : "odd") << std::endl;
	std::cout << "26500 is " << (IsEven(26500) ? "even" : "odd") << std::endl;
	std::cout << "19169 is " << (IsEven(19169) ? "even" : "odd") << std::endl;
	std::cout << std::endl;
}

void TestIsLeapYear()
{
	int year{};
	std::cout << "Teting IsLeapYear()\n";
	while (year != -1)
	{
		if (0 <= year)
		{
			std::cout << "Year? ";
			std::cin >> year;
			std::cout << year << " has " << (IsLeapYear(year) ? 29 : 28) << " days in February.\n";
		}
	}
	std::cout << std::endl;
}

void TestGetIntRand()
{
	std::cout << "Testing GetIntRand()\n";
	std::cout << "In [1,6] " << GetIntRand(1, 6) << std::endl;
	std::cout << "In [10,20] " << GetIntRand(10, 20) << std::endl;
	std::cout << "In [-5,0] " << GetIntRand(-5, 0) << std::endl;
	std::cout << std::endl;
}

void TestGetFloatRand()
{
	std::cout << "Testing GetFloatRand()\n";
	std::cout << "In [0, 3.14159] " << GetFloatRand(0.0f, 3.14159f, 2) << std::endl;
	std::cout << "In [-2, 3] " << GetFloatRand(-2.0f, 5.0f, 2) << std::endl;
	std::cout << std::endl;
}

void TestGetDistance()
{
	std::cout << "Testing GetDistance()\n";
	for (int i = 0; i < 5; i++)
	{
		float pointAX{ GetFloatRand(0, g_WindowWidth, 2) };
		float pointAY{ GetFloatRand(0, g_WindowHeight, 2) };
		float pointBX{ GetFloatRand(0, g_WindowWidth, 2) };
		float pointBY{ GetFloatRand(0, g_WindowHeight, 2) };
		std::cout << "Distance between [" << pointAX << ", " << pointAY << "] and [" << pointBX << ", " << pointBY << "]\n";
		std::cout << "Calling one version " << GetDistance(pointAX, pointAY, pointBX, pointBY) << std::endl;
		std::cout << "Calling the other version " << GetDistance(Point2f{ pointAX, pointAY }, Point2f{ pointBX, pointBY }) << std::endl;
	}
	std::cout << std::endl;
}

void TestCalcCosSin() {}

int Sum(int a, int b)
{
	return a + b;
}

int Multiply(int a, int b)
{
	return a * b;
}

int Modulo(int number, int divisor)
{
	int quotient{ number / divisor };
	return number - (quotient * divisor);
}

int GetIntRand(int minValue, int maxValue)
{
	int range{ maxValue - minValue };
	range++;
	return rand() % range + minValue;
}

float GetFloatRand(float minValue, float maxValue, int precision)
{
	precision = (int)(pow(10, precision));
	int range{ (int)((maxValue - minValue) * precision) };
	int randomNumber = rand() % range + (int)(minValue * precision);
	return (float)randomNumber / precision;
}

float CalcElapsedTime(int start, int end)
{
	std::chrono::steady_clock::time_point startTime{ std::chrono::steady_clock::now() };
	PrintNumbers(start, end);
	std::chrono::steady_clock::time_point endTime{ std::chrono::steady_clock::now() };
	std::chrono::duration<float, std::milli> elapsedTime{ endTime - startTime };
	return elapsedTime.count();
}

bool IsEven(int number)
{
	return number % 2 == 0;
}

bool IsLeapYear(int year)
{
	bool isLeapYear{ false };
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		isLeapYear = true;
	}
	return isLeapYear;
}

float GetDistance(Point2f pointA, Point2f pointB)
{
	float differenceX{ abs(pointA.x - pointB.x) };
	float differenceY{ abs(pointA.y - pointB.y) };
	return sqrtf(powf(differenceX, 2) + powf(differenceY, 2));
}

float GetDistance(float pointAX, float pointAY, float pointBX, float pointBY)
{
	float differenceX{ abs(pointAX - pointBX) };
	float differenceY{ abs(pointAY - pointBY) };
	return sqrtf(powf(differenceX, 2) + powf(differenceY, 2));
}

void PrintInt(int value, char delimiter)
{
	std::cout << value << delimiter;
}

void PrintChar(char value, char delimiter)
{
	std::cout << value << delimiter;
}

void PrintFloat(float value, char delimiter)
{
	std::cout << value << delimiter;
}

void PrintNumbers(int start, int end)
{
	std::cout << "Interval [" << start << ", " << end << "]\n";
	if (start < end)
	{
		for (int i{ start }; i <= end; i++)
		{
			PrintInt(i, ' ');
		}
	}
	else
	{
		std::cout << "Invalid entry. First number has to be smaller than the 2nd.";
	}
	std::cout << std::endl;
}

void PrintMessage(int leadingSpaces, std::string message)
{
	std::string indentation{ "" };
	for (int i = 0; i < leadingSpaces; i++)
	{
		indentation += " ";
	}
	message = indentation + message;
	std::cout << message << std::endl;
}

#pragma endregion ownDefinitions