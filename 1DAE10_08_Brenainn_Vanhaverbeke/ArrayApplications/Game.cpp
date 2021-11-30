// Vanhaverbeke, Brenainn - 1DAE10

#include "pch.h"
#include "Game.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	InitialisePentagrams();
	InitialiseRandomStatistics();
}

void Draw()
{
	ClearBackground(0.0f, 0.0f, 0.0f);
	DrawClickedPoints();
	DrawPentagrams();
	DrawRandomStatistics();
	DrawMouseMovePoints();
	DrawGrid();
}

void Update(float elapsedSec)
{
	UpdatePentagrams(elapsedSec);
	UpdateRandomStatistics();
}

void End()
{
	for (int i{ 0 }; i < g_AmountOfRandomStatistics; i++)
	{
		DeleteTexture(g_RandomStatisticsText[i]);
	}
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
	Point2f mousePosition{ (float)e.x, (float)g_WindowHeight - e.y };
	AddMouseMovePoint(mousePosition);
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	Point2f mousePosition{ (float)e.x, (float)g_WindowHeight - e.y };
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
		AddClickedPoint(mousePosition);
		break;
	case SDL_BUTTON_RIGHT:
		ToggleCell(mousePosition);
		break;
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

void InitialisePentagrams()
{
	for (int i{ 0 }; i < g_AmountOfPentagrams; i++)
	{
		AngleSpeed pentagram{ 0.0f, GetRandomFloat(0.2f, 1.1f) };
		g_Pentagrams[i] = pentagram;
	}
}

void InitialiseRandomStatistics()
{
	for (int i{ 0 }; i < g_AmountOfRandomStatistics; i++)
	{
		TextureFromString(std::to_string(i), "Resources/DIN-Light.otf", 12, g_Yellow, g_RandomStatisticsText[i]);
	}
}

void AddClickedPoint(Point2f& mousePosition)
{
	if (g_LastClickedPointIndex < g_MaxClickedPoints)
		g_LastClickedPointIndex++;
	ShoveIntoArrayLeft(g_ClickedPoints, mousePosition, g_LastClickedPointIndex);
}

void AddMouseMovePoint(Point2f& mousePosition)
{
	if (g_LastMouseMoveIndex < g_MaxMouseMovePoints)
		g_LastMouseMoveIndex++;
	ShoveIntoArrayLeft(g_MouseMovePoints, mousePosition, g_LastMouseMoveIndex);
}

void ToggleCell(Point2f& mousePosition)
{
	for (int row{ 0 }; row < g_GridRows; row++)
	{
		for (int column{ 0 }; column < g_GridColumns; column++)
		{
			int index{ Get2DIndex(row, column, g_GridColumns) };
			Rectf gridCell{ g_GridOrigin.x + (g_SideLength * column),
							g_GridOrigin.y + (g_SideLength * row), g_SideLength, g_SideLength };
			if (IsPointInRectangle(gridCell, mousePosition))
			{
				g_CellClickState[index] = !g_CellClickState[index];
				return;
			}
		}
	}
}

void ShoveIntoArrayLeft(Point2f* pPoints, Point2f& toShove, int lastIndex)
{
	for (int i{ 1 }; i < lastIndex; i++)
		pPoints[lastIndex - i] = pPoints[lastIndex - i - 1];
	pPoints[0] = toShove;
}

void UpdatePentagrams(float elapsedSec)
{
	for (int i{ 0 }; i < g_AmountOfPentagrams; i++)
	{
		AngleSpeed& pentagram{ g_Pentagrams[i] };
		pentagram.angle += pentagram.speed * elapsedSec;
		if (360.0f < pentagram.angle)
			pentagram.angle -= 360.0f;
	}
}

void UpdateRandomStatistics()
{
	int randomNumber{ (int)GetRandomNumber(0, g_AmountOfRandomStatistics, false) };
	if (g_RandomStatistics[randomNumber] < g_MaxBarWidth)
		g_RandomStatistics[randomNumber]++;
}

void DrawClickedPoints()
{
	for (int i{ 0 }; i < g_LastClickedPointIndex; i++)
	{
		Point2f& clickedPoint{ g_ClickedPoints[i] };
		SetColor(g_White);
		if (i != 0)
			DrawLine(clickedPoint, g_ClickedPoints[i - 1]);
		SetColor(g_Red);
		FillCircle(clickedPoint, g_ClickedPointRadius);
	}
}

void DrawPentagrams()
{
	const float amountOfPoints{ 5 };
	const float nthOfCircle{ 360.0f / amountOfPoints };
	for (int pentagramIndex{ 0 }; pentagramIndex < g_AmountOfPentagrams; pentagramIndex++)
	{
		AngleSpeed pentagram{ g_Pentagrams[pentagramIndex] };
		for (int point{ 0 }; point < amountOfPoints; point++)
		{
			float angleStart = pentagram.angle + (nthOfCircle * point);
			float angleEnd = pentagram.angle + (nthOfCircle * (point + 2));
			Point2f start{ GetCoordinatesFromRadians(g_PentagramSize, ConvertDegreesToRadians(angleStart), g_PentagramCenter) };
			Point2f end{ GetCoordinatesFromRadians(g_PentagramSize, ConvertDegreesToRadians(angleEnd), g_PentagramCenter) };
			SetColor(g_Green);
			DrawLine(start, end);
		}
	}
}

void DrawRandomStatistics()
{
	const float textOffsetLeft{ g_DefaultBorder };
	const float barOffsetLeft{ g_DefaultBorder * 3 };
	const float heightOffset{ g_RandomStatisticsText[0].height + g_DefaultBorder };
	SetColor(g_Yellow);
	for (int i{ 0 }; i < g_AmountOfRandomStatistics; i++)
	{
		Point2f bottomLeft{ textOffsetLeft, g_WindowHeight - (heightOffset * (i + 1)) };
		DrawTexture(g_RandomStatisticsText[i], bottomLeft);
		bottomLeft.x = barOffsetLeft;
		FillRect(bottomLeft, (float)g_RandomStatistics[i], g_RandomStatisticsText[0].height);
	}
}

void DrawMouseMovePoints()
{
	const float transparencyShift{ 1.0f / g_MaxMouseMovePoints };
	const float radiusShift{ g_MouseMovePointRadius / g_MaxMouseMovePoints };
	Color4f blueish{ 0.0f, 0.5f, 0.42f, 1.0f };
	for (int i{ 0 }; i < g_LastMouseMoveIndex; i++)
	{
		SetColor(blueish);
		blueish.a -= transparencyShift;
		FillCircle(g_MouseMovePoints[i], g_MouseMovePointRadius - (i * radiusShift));
	}
}

void DrawGrid()
{
	const Color4f toggledOn{ 1.0f, 0.4f, 0.2f, 1.0f };
	const Color4f togledOff{ 0.8f, 0.8f, 0.8f, 1.0f };
	for (int row = 0; row < g_GridRows; row++)
	{
		for (int column = 0; column < g_GridColumns; column++)
		{
			Point2f bottomLeft{ g_GridOrigin.x + (g_SideLength * column), g_GridOrigin.y + (g_SideLength * row) };
			int index{ Get2DIndex(row, column, g_GridColumns) };
			SetColor(togledOff);
			if (g_CellClickState[index])
				SetColor(toggledOn);
			FillRect(bottomLeft, g_SideLength, g_SideLength);
			SetColor(g_White);
			DrawRect(bottomLeft, g_SideLength, g_SideLength);
		}
	}
}

int Get2DIndex(int rowIndex, int columnIndex, int nrOfColumns)
{
	return rowIndex * nrOfColumns + columnIndex;
}

#pragma endregion ownDefinitions