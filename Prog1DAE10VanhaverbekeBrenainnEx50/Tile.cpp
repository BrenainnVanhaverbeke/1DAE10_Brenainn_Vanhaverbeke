#include "pch.h"		
#include "Tile.h"
#include <iostream>

Tile::Tile(const Rectf& destinationRectangle, const std::string& imagePath, int nrOfAnimals)
	: m_DestinationRectangle{ destinationRectangle }, m_ImagePath{ imagePath }, m_NrOfAnimals{ nrOfAnimals }
	, m_IsMouseOver{ false }, m_IsActive{ false }
{
	Randomise();
	InitialiseHitboxes();
}

void Tile::InitialiseHitboxes()
{
	Rectf hitbox{ m_DestinationRectangle.left, m_DestinationRectangle.bottom
		, m_DestinationRectangle.width / 4, m_DestinationRectangle.height / 4 };
	m_HitboxLeft = hitbox;
	hitbox.left += m_DestinationRectangle.width - hitbox.width;
	m_HitboxRight = hitbox;
}

void Tile::Draw()
{
	const float sideLength{ 128.0f };

	utils::Texture spriteSheet{};
	if (utils::TextureFromFile(m_ImagePath, spriteSheet))
	{
		Rectf sourceRectangle{ GetSourceRectangle(spriteSheet, sideLength) };
		utils::DrawTexture(spriteSheet, m_DestinationRectangle, sourceRectangle);
		DeleteTexture(spriteSheet);
		if (m_IsMouseOver)
			DrawOnActive();
	}
	else
		std::cout << "Something went horribly wrong, abandon all hope.";
}

void Tile::DrawOnActive()
{
	const Color4f overlayColour{ 0.0f, 0.0f, 0.0f, 0.3f };
	const Color4f borderColour{ 1.0f, 0.0f, 0.0f, 1.0f };
	utils::SetColor(overlayColour);
	utils::FillRect(m_DestinationRectangle);
	utils::SetColor(borderColour);
	utils::DrawRect(m_HitboxLeft);
	utils::DrawRect(m_HitboxRight);
}

void Tile::CheckActivation(const Point2f& mousePosition)
{
	if (m_IsActive)
		m_IsMouseOver = utils::IsPointInRectangle(m_DestinationRectangle, mousePosition);
}

bool Tile::CheckHit(const Point2f& mousePosition)
{
	if (m_IsActive)
	{
		if (utils::IsPointInRectangle(m_HitboxLeft, mousePosition))
		{
			if (--m_CurrentAnimal < 0)
				m_CurrentAnimal = m_NrOfAnimals - 1;
			return true;
		}
		else if (utils::IsPointInRectangle(m_HitboxRight, mousePosition))
		{
			m_CurrentAnimal = (m_CurrentAnimal + 1) % m_NrOfAnimals;
			return true;
		}
	}
	return false;
}

int Tile::GetCurrentAnimal()
{
	return m_CurrentAnimal;
}

Rectf Tile::GetSourceRectangle(const utils::Texture& forTexture, float sideLength)
{
	Rectf sourceRectangle{};
	sourceRectangle.left = float(m_CurrentAnimal * sideLength);
	sourceRectangle.bottom = sideLength;
	sourceRectangle.width = sideLength;
	sourceRectangle.height = sideLength;
	return sourceRectangle;
}

void Tile::Deactivate()
{
	m_IsMouseOver = false;
	m_IsActive = false;
}

void Tile::Randomise()
{
	m_IsActive = true;
	m_CurrentAnimal = (int)utils::GetRandomNumber(0, m_NrOfAnimals, false);
}