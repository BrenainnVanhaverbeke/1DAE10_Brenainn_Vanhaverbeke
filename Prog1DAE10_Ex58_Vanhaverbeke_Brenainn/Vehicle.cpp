#include "pch.h"
#include "Vehicle.h"
#include "MyUtils.h"
#include <iostream>

Vehicle::Vehicle(int id, float speed)
	:m_Speed{ speed }, m_IsActive{ false }, m_VehiclePosition{ Point2f{0, 0} }
{
	m_IsActive = false;
	std::string imagePath{ "Resources/car-truck" + std::to_string(id) + ".bmp" };
	if (!utils::TextureFromFile(imagePath, m_VehicleTexture))
		std::cout << "Dun fucked loading vehicle " << imagePath << ". Shit's fucked, abandon all hope." << std::endl;
}

Vehicle::~Vehicle()
{
	utils::DeleteTexture(m_VehicleTexture);
}

void Vehicle::Update(float elapsedSec, float maxXPosition)
{
	if (m_IsActive)
	{
		m_VehiclePosition.x += m_Speed * elapsedSec;
		if (maxXPosition < m_VehiclePosition.x)
			m_VehiclePosition.x = -m_VehicleTexture.width;
	}
}

void Vehicle::Draw()
{
	utils::DrawTexture(m_VehicleTexture, m_VehiclePosition);
}

void Vehicle::SetYPos(float yPos)
{
	m_VehiclePosition.y = yPos;
}

void Vehicle::Reset()
{
	m_VehiclePosition.x = GetRandomNumber(-300, 0);
	m_Speed = GetRandomNumber(20, 200);
	m_IsActive = true;
}

bool Vehicle::CheckColision(Point2f chicken)
{
	Rectf vehicleRect{ m_VehiclePosition.x, m_VehiclePosition.y, m_VehicleTexture.width, m_VehicleTexture.height };
	if (IsPointInRectangle(vehicleRect, chicken))
	{
		m_IsActive = false;
		return true;
	}
	return false;
}