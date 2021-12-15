#pragma once
class Fraction
{
public:
	Fraction(int numerator = 1, int denominator = 5);
	//Fraction(int numerator, int denominator);
	void Draw(const Point2f& position, float size);
	float GetValue();

private:
	int m_Numerator;
	int m_Denominator;
};