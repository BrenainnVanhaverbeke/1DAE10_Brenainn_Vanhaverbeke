// Vanhaverbeke, Brenainn - 1DAE10

#include "pch.h"
#include "Game.h"
#include "Fraction.h"
#include "Light.h"
#include "DaeEllipse.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	InitialiseFractions();
	InitialiseLights();
	InitialiseDaeEllipses();
}

void Draw()
{
	ClearBackground(0.0f, 0.0f, 0.0f);
	DrawFractions();
	DrawLights();
	DrawDaeEllipses();
}

void Update(float elapsedSec)
{
}

void End()
{
	DeleteFractions();
	DeleteLights();
	DeleteDaeEllipses();
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
	Point2f mousePosition{ (float)e.x, g_WindowHeight - (float)e.y };
	ActivateDaeEllipses(mousePosition);
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	Point2f mousePosition{ (float)e.x, (float)g_WindowHeight - e.y };
	HitLights(mousePosition);
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

void InitialiseFractions()
{
	const int maxNumerator{ 3 };
	const int maxDenominator{ 5 };
	int randomNumerator{};
	int randomDenominator{};
	g_pFractions = new Fraction[g_AmountOfFractions];
	for (int fraction = 0; fraction < g_AmountOfFractions; fraction++)
	{
		randomNumerator = (int)GetRandomNumber(1, maxNumerator);
		randomDenominator = (int)GetRandomNumber(maxNumerator, maxDenominator);
		g_pFractions[fraction] = Fraction{ randomNumerator, randomDenominator };
	}
}

void InitialiseLights()
{
	const int widthMin{ 30 };
	const int widthMax{ 60 };
	const float height{ 25.0f };
	const float gutter{ 10.0f };
	const float leftDefault{ 100.0f };
	Rectf rectangle{ leftDefault, 10.0f, 0.0f, height };
	g_pLights = new Light[g_AmountOfLightRows * g_AmountOfLightColumns];
	for (int row{ 0 }; row < g_AmountOfLightRows; ++row)
	{
		for (int column{ 0 }; column < g_AmountOfLightColumns; ++column)
		{
			int index{ GetLinearIndexFrom2D(row, column, g_AmountOfLightColumns) };
			rectangle.width = GetRandomNumber(widthMin, widthMax);
			g_pLights[index] = Light(rectangle, GetRandomColour());
			rectangle.left += rectangle.width + gutter;
		}
		rectangle.bottom += gutter + height;
		rectangle.left = leftDefault;
	}
}

void InitialiseDaeEllipses()
{
	g_pDaeEllipses = new DaeEllipse[g_AmountOfDaeEllipses];
	g_pDaeEllipses[0] = DaeEllipse(Point2f{ 50.0f, 200.0f }, 30.0f, 50.0f, GetRandomColour());
	g_pDaeEllipses[1] = DaeEllipse(Point2f{ 300.0f, 200.0f }, 100.0f, 50.0f, GetRandomColour());
	g_pDaeEllipses[2] = DaeEllipse(Point2f{ 350.0f, 50.0f }, 40.0f, 40.0f, GetRandomColour());
}

void HitLights(const Point2f& mousePosition)
{
	bool isLightHit{ false };
	int amountOfLightsOn{ 0 };
	for (int lightIndex = 0; lightIndex < g_AmountOfLights; lightIndex++)
	{
		Light& light{ g_pLights[lightIndex] };
		bool isLightHit{ light.IsHit(mousePosition) };
		if (light.IsOn())
			amountOfLightsOn++;
	}
	if (0 < amountOfLightsOn)
		std::cout << amountOfLightsOn << ((1 < amountOfLightsOn) ? " lights are on." : " light is on") << std::endl;
}

void ActivateDaeEllipses(const Point2f mousePosition)
{
	for (int daeEllipseIndex = 0; daeEllipseIndex < g_AmountOfDaeEllipses; daeEllipseIndex++)
		g_pDaeEllipses[daeEllipseIndex].ActivateTest(mousePosition);
}

void DrawFractions()
{
	const float border{ 10.0f };
	const float gutter{ 7.0f };
	const float size{ 15.0f };
	Point2f position{ border, border };
	for (int i = 0; i < g_AmountOfFractions; i++)
	{
		position.y = gutter * i + size * (i + 1);
		g_pFractions[i].Draw(position, size);
	}
}

void DrawLights()
{
	for (int lightIndex{ 0 }; lightIndex < 8; ++lightIndex)
		g_pLights[lightIndex].Draw();
}

void DrawDaeEllipses()
{
	for (int daeEllipseIndex = 0; daeEllipseIndex < g_AmountOfDaeEllipses; daeEllipseIndex++)
		g_pDaeEllipses[daeEllipseIndex].Draw();
}

void DeleteFractions()
{
	delete[] g_pFractions;
	g_pFractions = nullptr;
}

void DeleteLights()
{
	delete[] g_pLights;
	g_pLights = nullptr;
}

void DeleteDaeEllipses()
{
	delete[] g_pDaeEllipses;
	g_pDaeEllipses = nullptr;
}

#pragma endregion ownDefinitions