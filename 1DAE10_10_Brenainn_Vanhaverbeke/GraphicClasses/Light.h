#pragma once
class Light
{
private:
	bool m_IsOn;
	Rectf m_Rect;
	Color4f m_Colour;

public:
	Light(const Rectf& rectangle, const Color4f& colour);
	void Draw();
	bool IsHit(const Point2f& position);
	bool IsOn();
};