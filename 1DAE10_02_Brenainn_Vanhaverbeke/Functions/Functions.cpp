#include "pch.h"
#include <iostream>

#define _USE_MATH_DEFINES
#include <cmath>

int main()
{
	// 1. Show my data
	std::cout << "My name is Vanhaverbeke, Brenainn" << std::endl;
	std::cout << "I am in group 1DAE10" << std::endl << std::endl;

	// 2. Show my student history
	std::cout << "Name of my high school: KTA- GITO" << std::endl;
	std::cout << "In the last year I had 2 hours math a week" << std::endl << std::endl;

	// Wait
	std::cout << "Push ENTER to quit\n";
	std::cin.get();

	TestOneParFunctions();
	TestTwoParFunctions();

	return 0;
}

void TestOneParFunctions()
{
	cos(0);
	double angle = 0;
	cos(angle);
	double pi = 3.1415926535;
	double quarterPi = pi / 4;
	std::cout << "Use existing functions with 1 parameter.\n";
	std::cout << "Angle: " << angle << "\n";
	std::cout << "  cos: " << cos(angle) << "\n";
	angle += quarterPi;
	std::cout << "Angle: " << angle << "\n";
	std::cout << "  cos: " << cos(angle) << "\n";
	angle += quarterPi;
	std::cout << "Angle: " << angle << "\n";
	std::cout << "  cos: " << cos(angle) << "\n";
	angle += quarterPi;
	std::cout << "Angle: " << angle << "\n";
	std::cout << "  cos: " << cos(angle) << "\n";
	angle += quarterPi;
	std::cout << "Angle: " << angle << "\n";
	std::cout << "  cos: " << cos(angle) << "\n";
	cos(angle * 2);
}

void TestTwoParFunctions()
{
	double a = 2;
	double b = 8;
	std::cout << pow(a, b) << "\n";
	a = 3;
	b = 4;
	double c = sqrt((pow(a, 2) + pow(b, 2)));
	std::cout << c << "\n";
}