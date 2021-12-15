#pragma once
class Light
{
private:
	bool m_IsOn;
	Rectf m_Rect;
	Color4f m_Colour;

public:
	Light(const Rectf& rectangle = Rectf{ 0, 0, 0, 0 }, const Color4f& colour = Color4f{ 0.0f, 0.0f, 0.0f, 0.0f });
	void Draw();
	bool IsHit(const Point2f& position);
	bool IsOn();
};