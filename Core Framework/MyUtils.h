#pragma once

float ConvertDegreesToRadians(float degrees);
Point2f GetCoordinatesFromRadians(float radius, float radians, Point2f offset);
Color4f GetRandomColour();
float GetRandomNumber(int lowestValue, int highestValue, bool isInclusive = true);