#include "pch.h"
#include "MyUtils.h"

float ConvertDegreesToRadians(float degrees)
{
	return degrees * (utils::g_Pi / 180);
}

Point2f GetCoordinatesFromRadians(float radius, float radians, Point2f offset)
{
	float x = offset.x + (radius * cosf(radians));
	float y = offset.y + (radius * sinf(radians));
	return Point2f{ x, y };
}

Color4f GetRandomColour()
{
	float r{ GetRandomNumber(0, 255) / 255 };
	float g{ GetRandomNumber(0, 255) / 255 };
	float b{ GetRandomNumber(0, 255) / 255 };
	return Color4f{ r, g, b, 1 };
}

float GetRandomNumber(int lowestValue, int amountOfValues)
{
	amountOfValues++;
	return (float)(rand() % amountOfValues) + lowestValue;
}