#pragma once
class DaeEllipse
{
public:
	DaeEllipse();
	DaeEllipse(const Point2f& center, float radX, float radY, const Color4f& fillColour);
	void Draw();
	void ActivateTest(const Point2f& position);

private: 
	float m_RadX;
	float m_RadY;
	float m_Area;
	bool m_IsActive;
	Point2f m_Center;
	Color4f m_FillColour;
};

