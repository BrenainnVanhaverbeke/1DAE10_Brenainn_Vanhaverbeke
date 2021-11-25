#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Project name - Name, firstname - 1DAExx" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

// Declare your own functions here

void TestSum();
void TestPrint();
void TestMultiply();
void TestModulo();
void TestPrintNumbers();
void TestCalcElapsedTime();
void TestPrintMessage();
void TestIsEven();
void TestIsLeapYear();
void TestGetIntRand();
void TestGetFloatRand();
void TestGetDistance();
void TestCalcCosSin();

int Sum(int a, int b);
int Multiply(int a, int b);
int Modulo(int number, int divisor);
float CalcElapsedTime(int start, int end);
bool IsEven(int number);
bool IsLeapYear(int year);
int GetIntRand(int minValue, int maxValue);
float GetFloatRand(float minValue, float maxValue, int precision);
float GetDistance(Point2f pointA, Point2f pointB);
float GetDistance(float pointAX, float pointAY, float pointBX, float pointBY);
void CalcCosSin(float radians, float& cosResult, float& sinResult);

void PrintInt(int value, char delimiter = ' ');
void PrintChar(char value, char delimiter = ' ');
void PrintFloat(float value, char delimiter = ' ');
void PrintNumbers(int start, int end);
void PrintMessage(int leadingSpaces, std::string message);

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
