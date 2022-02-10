#pragma once

Point2f GetCenterOfRectangle(const Rectf& rectangle);

float GetRandomNumber(int lowestValue, int highestValue, bool isInclusive = true);
bool IsPointInRectangle(const Rectf& rectangle, const Point2f& point);