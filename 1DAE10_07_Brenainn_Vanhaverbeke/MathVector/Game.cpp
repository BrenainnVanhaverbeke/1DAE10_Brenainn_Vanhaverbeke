// Vanhaverbeke, Brenainn - 1DAE10

#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	//TestVectorToString();
	//TestDotProduct();
	//TestCrossProduct();
	//TestLengthVector();
	//TestScaleVector();
	//TestNormaliseVector();
	//TestAngleBetween();
	//TestAreEqual();
}

void Draw()
{
	ClearBackground(0.0f, 0.0f, 0.0f);
	//TestDrawVector();
	//TestAddVector();
	//TestSubtractVector();
	DrawAnimatedVector();
}

void Update(float elapsedSec)
{
	g_VectorAngle += g_RotationSpeed * elapsedSec;
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

}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{

}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{

}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

void DrawAnimatedVector()
{
	const float vectorLength{ 100.0f };
	Point2f coordinates{ GetCoordinatesFromRadians(vectorLength, ConvertDegreesToRadians(g_VectorAngle)) };
	Vector2f vector{ coordinates.x, coordinates.y };
	Vector2f toNormalise{ 69.0f, 42.0f };
	Vector2f normalised{ Normalise(toNormalise) };
	float dotProduct{ DotProduct(vector, normalised) };
	Vector2f projection{ Scale(normalised, dotProduct) };
	SetColor(g_White);
	DrawVector(vector, Point2f{ g_WindowWidth / 2, g_WindowHeight / 2 });
	SetColor(g_Red);
	DrawVector(projection, Point2f{ g_WindowWidth / 2, g_WindowHeight / 2 });
}

void TestDrawVector()
{
	SetColor(1.0f, 1.0f, 0.0f);
	Vector2f vector{ 100.0f, 30.0f };
	DrawVector(vector);
	DrawVector(vector, Point2f{ 30.0f, 50.0f });
	DrawVector(vector, Point2f{ 50.0f, 30.0f });
}

void TestVectorToString()
{
	Vector2f vector{ 100, 30 };
	std::cout << ToString(vector) << std::endl;
	std::cout << std::endl;
}

void TestAddVector()
{
	Vector2f vector1{ 50.0f, 10.0f };
	Vector2f vector2{ 25.0f,30.0f };
	Vector2f vector3{ Add(vector1, vector2) };
	Point2f startPoint{ 10.0f, 10.0f };
	DrawVector(vector1, startPoint);
	DrawVector(vector2, Point2f{ startPoint.x + vector1.x, startPoint.y + vector1.y });
	DrawVector(vector3, startPoint);
}

void TestSubtractVector()
{
	Vector2f vector1{ 100.0f, 20.0f };
	Vector2f vector2{ 25.0f,30.0f };
	Vector2f vector3{ Subtract(vector1, vector2) };
	Point2f startPoint{ 10.0f, 10.0f };
	DrawVector(vector1, startPoint);
	DrawVector(vector2, startPoint);
	SetColor(1.0f, 0.0f, 0.0f);
	DrawVector(vector3, Point2f{ startPoint.x + vector2.x, startPoint.y + vector2.y });
}

void TestDotProduct()
{
	Vector2f horizontal{ 80.0f, 0.0f };
	Vector2f vertical{ 0.0f, 50.0f };
	float dotProduct{ DotProduct(horizontal, vertical) };
	std::cout << "hor = " << ToString(horizontal) << "\tver = " << ToString(vertical) << "\tDot product: "
		<< std::to_string(dotProduct) << std::endl;
	Vector2f parallel{ 0.0f, 25.0f };
	dotProduct = DotProduct(vertical, parallel);
	std::cout << "ver = " << ToString(vertical) << "\tpar = " << ToString(parallel) << "\tDot product: "
		<< std::to_string(dotProduct) << std::endl;
	std::cout << std::endl;
}

void TestCrossProduct()
{
	Vector2f horizontal{ 80.0f, 0.0f };
	Vector2f vertical{ 0.0f, 50.0f };
	float crossProduct{ CrossProduct(horizontal, vertical) };
	std::cout << "hor = " << ToString(horizontal) << "\tver = " << ToString(vertical) << "\tCross product: "
		<< std::to_string(crossProduct) << std::endl;
	crossProduct = CrossProduct(vertical, horizontal);
	std::cout << "ver = " << ToString(vertical) << "\thor = " << ToString(horizontal) << "\tCross product: "
		<< std::to_string(crossProduct) << std::endl;
	std::cout << std::endl;
}

void TestLengthVector()
{
	Vector2f vector{ 100.0f, 30.0f };
	float length = Length(vector);
	std::cout << "Length of " << ToString(vector) << " is " << length << std::endl;
	std::cout << std::endl;
}

void TestScaleVector()
{
	float scalar{ 0.1f };
	Vector2f vector{ 100.0f, 30.0f };
	Vector2f scaledVector{ Scale(vector, scalar) };
	std::cout << "Scaled " << ToString(vector) << " by " << scalar << " is " << ToString(scaledVector) << std::endl;
	std::cout << std::endl;
}

void TestNormaliseVector()
{
	Vector2f vector{ 10.0f, 3.0f };
	vector = Normalise(vector);
	std::cout << "Normalised " << ToString(vector) << " is " << ToString(vector) << " its length is: " << std::to_string(Length(vector));
	std::cout << std::endl;
}

void TestAngleBetween()
{
	Vector2f vectorA{ 10.0f, 0.0f };
	Vector2f vectorB{ 10.0f, 10.0f };
	float angle{ AngleBetween(vectorA, vectorB) };
	std::cout << "Angle between " << ToString(vectorA) << " and " << ToString(vectorB) << " is: "
		<< std::to_string(angle) << ", or " << std::to_string(ConvertRadiansToDegrees(angle)) << " degrees." << std::endl;
	std::cout << std::endl;
}

void TestAreEqual()
{
	Vector2f vectorA{ 10.0f, 0.0f };
	Vector2f vectorB{ 10.0f, 0.0f };
	bool areEqual{ AreEqual(vectorA, vectorB) };
	std::cout << areEqual << std::endl;
	vectorA = Vector2f{ 10.0f, 0.0f };
	vectorB = Vector2f{ 0.0f, 10.0f };
	areEqual = AreEqual(vectorA, vectorB);
	std::cout << areEqual << std::endl;
	vectorA = Vector2f{ 10.0f, 0.0f };
	vectorB = Vector2f{ -10.0f, 0.0f };
	areEqual = AreEqual(vectorA, vectorB);
	std::cout << areEqual << std::endl;
	std::cout << std::endl;
}

#pragma endregion ownDefinitions