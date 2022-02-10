#include "pch.h"
#include "MyUtils.h"

float GetRandomNumber(int lowestValue, int highestValue, bool isInclusive)
{
	int amountOfValues{ highestValue - lowestValue };
	if (isInclusive)
		amountOfValues++;
	return (float)(rand() % amountOfValues) + lowestValue;
}

Point2f GetCenterOfRectangle(const Rectf& rectangle)
{
	float x{ (rectangle.left * 2 + rectangle.width) / 2 };
	float y{ (rectangle.bottom * 2 + rectangle.height) / 2 };
	return Point2f{ x, y };
}

bool IsPointInRectangle(const Rectf& rectangle, const Point2f& point)
{
	if ((rectangle.left <= point.x && point.x <= rectangle.left + rectangle.width)
		&& (rectangle.bottom <= point.y && point.y <= rectangle.bottom + rectangle.height))
		return true;
	return false;
}