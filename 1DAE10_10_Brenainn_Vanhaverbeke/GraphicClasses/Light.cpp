#include "pch.h"
#include "Light.h"

Light::Light(const Rectf& rectangle, const Color4f& colour)
	: m_Rect{ rectangle }, m_Colour{ colour }, m_IsOn{ false }
{
}

void Light::Draw()
{
	const Color4f turnedOff{ 0.75f, 0.75f, 0.75f, 1.0f };
	const Color4f border{ 1.0f, 1.0f, 1.0f, 1.0f };
	utils::SetColor(turnedOff);
	if (m_IsOn)
		utils::SetColor(m_Colour);
	utils::FillRect(m_Rect);
	utils::SetColor(border);
	utils::DrawRect(m_Rect, 3.0f);
}

bool Light::IsHit(const Point2f& mousePosition)
{
	if (utils::IsPointInRectangle(m_Rect, mousePosition))
	{
		m_IsOn = !m_IsOn;
		return true;
	}
	return false;
}

bool Light::IsOn()
{
	return m_IsOn;
}