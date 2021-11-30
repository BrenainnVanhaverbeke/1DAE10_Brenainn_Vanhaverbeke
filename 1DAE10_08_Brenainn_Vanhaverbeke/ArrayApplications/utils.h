#pragma once
#include "structs.h"
#include <vector>

namespace utils
{

	const float g_Pi{ 3.1415926535f };

#pragma region OpenGLDrawFunctionality
	void ClearBackground(float r, float g, float b);
	void ClearBackground();
	// Choose a floating point value for each color component between 0.0f and 1.0f. The a (alpha) is optional.
	// Usage: SetColor(1.0f, 0.0f, 0.0f); set the drawing color to red
	void SetColor(float r, float g, float b, float a = 1);
	// Pass a Color4f object to the function
	void SetColor(const Color4f& color);

	// Draws a line by connecting the two points specified by (x1,y1) and (x2,y2)
	void DrawLine(float x1, float y1, float x2, float y2, float lineWidth = 1.0f);
	// Draws a line by connecting the two points specified by p1 and p1
	void DrawLine(const Point2f& p1, const Point2f& p2, float lineWidth = 1.0f);

	void DrawTriangle(const Point2f& p1, const Point2f& p2, const Point2f& p3, float lineWidth = 1);
	void FillTriangle(const Point2f& p1, const Point2f& p2, const Point2f& p3);
	void DrawRect(float left, float bottom, float width, float height, float lineWidth = 1.0f);
	void DrawRect(const Point2f& bottomLeft, float width, float height, float lineWidth = 1.0f);
	void DrawRect(const Rectf& rect, float lineWidth = 1.0f);
	void FillRect(float left, float bottom, float width, float height);
	void FillRect(const Point2f& bottomLeft, float width, float height);
	void FillRect(const Rectf& rect);

	void DrawCircle(const Point2f& center, float radius, float lineWidth = 1.0f);
	void DrawCircle(const Circlef& circle, float lineWidth = 1.0f);
	void DrawEllipse(float centerX, float centerY, float radX, float radY, float lineWidth = 1.0f);
	void DrawEllipse(const Point2f& center, float radX, float radY, float lineWidth = 1.0f);
	void DrawEllipse(const Ellipsef& ellipse, float lineWidth = 1.0f);
	void FillCircle(const Point2f& center, float radius);
	void FillCircle(const Circlef& circle);
	void FillEllipse(float centerX, float centerY, float radX, float radY);
	void FillEllipse(const Ellipsef& ellipse);
	void FillEllipse(const Point2f& center, float radX, float radY);

	// Draws an arc. The angle parameters are in radians, not in degrees.
	void DrawArc(float centerX, float centerY, float radX, float radY, float fromAngle, float tillAngle, float lineWidth = 1.0f);
	// Draws an arc. The angle parameters are in radians, not in degrees.
	void DrawArc(const Point2f& center, float radX, float radY, float fromAngle, float tillAngle, float lineWidth = 1.0f);
	// Fills an arc. The angle parameters are in radians, not in degrees.
	void FillArc(float centerX, float centerY, float radX, float radY, float fromAngle, float tillAngle);
	// Fills an arc. The angle parameters are in radians, not in degrees.
	void FillArc(const Point2f& center, float radX, float radY, float fromAngle, float tillAngle);

	void DrawPolygon(const std::vector<Point2f>& vertices, bool closed = true, float lineWidth = 1.0f);
	void DrawPolygon(const Point2f* pVertices, size_t nrVertices, bool closed = true, float lineWidth = 1.0f);
	void FillPolygon(const std::vector<Point2f>& vertices);
	void FillPolygon(const Point2f* pVertices, size_t nrVertices);

	void DrawVector(Vector2f& vector, Point2f startingPoint = Point2f{ 0, 0 });

#pragma endregion OpenGLDrawFunctionality

#pragma region TextureFunctionality

	struct Texture
	{
		GLuint id;
		float width;
		float height;
	};
	bool TextureFromFile(const std::string& path, Texture& texture);
	bool TextureFromString(const std::string& text, TTF_Font* pFont, const Color4f& textColor, Texture& texture);
	bool TextureFromString(const std::string& text, const std::string& fontPath, int ptSize, const Color4f& textColor, Texture& texture);
	void TextureFromSurface(const SDL_Surface* pSurface, Texture& textureData);
	void DrawTexture(const Texture& texture, const Point2f& dstBottomLeft, const Rectf& srcRect = {});
	void DrawTexture(const Texture& texture, const Rectf& dstRect, const Rectf& srcRect = {});
	void DeleteTexture(Texture& texture);
#pragma endregion TextureFunctionality

#pragma region CollisionFunctionality

	float GetDistance(Point2f pointA, Point2f pointB);
	float GetDistance(float pointAX, float pointAY, float pointBX, float pointBY);
	
	bool IsPointInCircle(const Circlef& circle, const Point2f& point);
	bool IsPointInRectangle(const Rectf& rectangle, const Point2f& point);

	bool IsOverlapping(const Rectf& rectangleA, const Rectf& rectangleB);
	bool IsOverlapping(const Circlef& circleA, const Circlef& circleB);

#pragma endregion CollisionFunctionality

#pragma region VectorFunctionality

	Vector2f Add(Vector2f& vectorA, Vector2f& vectorB);
	Vector2f Subtract(Vector2f& vectorA, Vector2f& vectorB);
	float DotProduct(Vector2f& vectorA, Vector2f& vectorB);
	float CrossProduct(Vector2f& vectorA, Vector2f& vectorB);
	std::string ToString(Vector2f& vector);
	Vector2f Scale(Vector2f& vectorA, float scalar);
	float Length(Vector2f& vector);
	Vector2f Normalise(Vector2f& vector);
	float AngleBetween(Vector2f& vectorA, Vector2f& vectorB);
	bool AreEqual(Vector2f& vectorA, Vector2f& vectorB);

#pragma endregion VectorFunctionality

#pragma region GeneralUtils

	Point2f GetMiddle(const Point2f& pointA, const Point2f& pointB);
	float ConvertDegreesToRadians(float degrees);
	float ConvertRadiansToDegrees(float radians);
	Point2f GetCoordinatesFromRadians(float radius, float radians, Point2f offset = Point2f{ 0.0f, 0.0f });
	Color4f GetRandomColour();
	float GetRandomNumber(int lowestValue, int highestValue, bool isInclusive = true);
	float GetRandomFloat(float minValue, float maxValue, int precision = 2);

#pragma endregion GeneralUtils
}