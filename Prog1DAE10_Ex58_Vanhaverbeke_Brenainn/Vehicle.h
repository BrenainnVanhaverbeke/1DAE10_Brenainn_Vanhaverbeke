#pragma once

class Vehicle
{
public:
	Vehicle(int id, float speed);
	~Vehicle();
	void Update(float elapsedSec, float maxXPosition);
    void Draw();
	void SetYPos(float yPos);
	void Reset();
	bool CheckColision(Point2f chicken);

private:
	float m_Speed;
	bool m_IsActive;
	utils::Texture m_VehicleTexture;
	Point2f m_VehiclePosition;
};

