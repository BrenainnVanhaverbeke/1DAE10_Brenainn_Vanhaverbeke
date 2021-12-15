#include "pch.h"
#include "Fraction.h"
#include "utils.h"

Fraction::Fraction(int numerator, int denominator)
	:m_Numerator{ numerator }, m_Denominator{ denominator }
{
}

float Fraction::GetValue()
{
	return (float)m_Numerator / (float)m_Denominator;
}

void Fraction::Draw(const Point2f& position, float size)
{
	const Color4f blue{ 0.0f, 0.0f, 1.0f, 1.0f };
	const Color4f white{ 1.0f, 1.0f, 1.0f, 1.0f };
	Rectf rectangle{ position.x, position.y, size, size };
	for (int i = 0; i < m_Denominator; i++)
	{
		utils::SetColor(blue);
		if (i <= m_Numerator)
			utils::FillRect(rectangle);
		utils::SetColor(white);
		utils::DrawRect(rectangle);
		rectangle.left += size;
	}
}