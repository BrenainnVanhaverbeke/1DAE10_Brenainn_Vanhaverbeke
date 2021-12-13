#pragma once

#include "pch.h"

class Square
{
public:
	Square(float size);
	Square(float size, float left, float bottom);
	~Square();
	void Print();
	void Translate(float deltaLeft, float deltaBottom);
	void SetSize(float newSize);

private:
	float GetArea();
	float GetPerimeter();
	float m_Size;
	float m_Left;
	float m_Bottom;
};

