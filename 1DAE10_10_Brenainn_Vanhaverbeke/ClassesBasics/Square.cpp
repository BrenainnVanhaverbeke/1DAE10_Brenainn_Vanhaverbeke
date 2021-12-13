#include "pch.h"
#include "Square.h"
#include <iostream>

Square::Square(float size)
	:m_Size{ size }, m_Left{ 0 }, m_Bottom{ 0 }
{

}

Square::Square(float size, float left, float bottom)
	: m_Size{ size }, m_Left{ left }, m_Bottom{ bottom }
{

}

Square::~Square()
{
	std::cout << "Releasing square resources." << std::endl;
}

void Square::Print()
{
	std::cout << "-- Square object --" << std::endl;
	std::cout << "Sidelength: " << m_Size << std::endl;
	std::cout << "Left: " << m_Left << std::endl;
	std::cout << "Bottom: " << m_Bottom << std::endl;
	std::cout << "Area: " << GetArea() << std::endl;
	std::cout << "Perimeter: " << GetPerimeter() << std::endl;
	std::cout << std::endl;
}

void Square::Translate(float deltaLeft, float deltaRight)
{
	m_Left += deltaLeft;
	m_Bottom += deltaRight;
}

void Square::SetSize(float newSize)
{
	m_Size = newSize;
}

float Square::GetArea()
{
	return m_Size * m_Size;
}

float Square::GetPerimeter()
{
	return m_Size * 4;
}