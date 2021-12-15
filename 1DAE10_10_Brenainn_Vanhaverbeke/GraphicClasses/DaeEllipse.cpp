#include "pch.h"
#include "DaeEllipse.h"
#include <iostream>

DaeEllipse::DaeEllipse()
	: DaeEllipse(Point2f{ 0,0 }, 0.0f, 0.0f, Color4f{ 0.0f, 0.0f, 0.0f, 0.0f })
{
}

DaeEllipse::DaeEllipse(const Point2f& center, float radX, float radY, const Color4f& fillColour)
	: m_Center{ center }, m_RadX{ radX }, m_RadY{ radY }, m_FillColour{ fillColour }, m_Area{ utils::g_Pi * radX * radY }
	, m_IsActive{ false }
{
}

void DaeEllipse::Draw()
{
	m_FillColour.a = 0.5f;
	if (m_IsActive)
		m_FillColour.a = 1.0f;
	utils::SetColor(m_FillColour);
	utils::FillEllipse(m_Center, m_RadX, m_RadY);
}

void DaeEllipse::ActivateTest(const Point2f& position)
{
	float differenceX{ powf(position.x - m_Center.x, 2) / powf(m_RadX, 2) };
	float differencY{ powf(position.y - m_Center.y, 2) / powf(m_RadY, 2) };
	m_IsActive = differenceX + differencY <= 1;
	if (m_IsActive)
		std::cout << "This elipse's area: " << m_Area << std::endl;
}