#pragma once

class Tile
{
public:
	Tile(const Rectf& destinationRectangle, const std::string& imagePath, int nrOfAnimals);


	void Draw();
	void CheckActivation(const Point2f& mousePosition);
	bool CheckHit(const Point2f& mousePosition);
	int GetCurrentAnimal();
	void Deactivate();
	void Randomise();

private:
	int m_NrOfAnimals;
	int m_CurrentAnimal;
	bool m_IsMouseOver;
	bool m_IsActive;
	std::string m_ImagePath;
	Rectf m_DestinationRectangle;
	Rectf m_HitboxLeft;
	Rectf m_HitboxRight;

	void InitialiseHitboxes();
	void DrawOnActive();
	Rectf GetSourceRectangle(const utils::Texture& forTexture, float sideLength);
};