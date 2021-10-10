// Vanhaverbeke, Brenainn - 1DAE10

#include "pch.h"
#include <iostream>
#include <corecrt_math_defines.h>
#include <chrono>
#include <ctime>

int main()
{
	rgbaToFloat();
	distanceConversion();
	degreesToRadians();
	radiansToDegrees();
	rotationSpeed();
	metersCovered();
	circleCalculations();
	downwardVelocity();
	rectangleCalculations();
	triangleCalculations();
}

void rgbaToFloat()
{
	std::cout << "RGBA in [0, 255]? Separate with spaces. ";
	float red;
	float green;
	float blue;
	float alpha;

	std::cin >> red >> green >> blue >> alpha;

	std::cout << "RGBA in [0.0f, 1.0f]:\n";
	std::cout << red / 255 << "\n";
	std::cout << green / 255 << "\n";
	std::cout << blue / 255 << "\n";
	std::cout << alpha / 255 << "\n\n";
}

void distanceConversion()
{
	float distance;

	std::cout << "Distance in km? ";
	std::cin >> distance;
	std::cout << distance * 1000 << " meters. " << distance * 100000 << " cm.\n\n";
}

void degreesToRadians() 
{
	double radians;
	double degrees;

	std::cout << "Angle in radians? ";
	std::cin >> radians;
	degrees = radians * (180 / M_PI);
	std::cout << degrees << " degrees.\n\n";
}

void radiansToDegrees() 
{
	double degrees;
	double radians;

	std::cout << "Angle in degrees? ";
	std::cin >> degrees;
	radians = degrees * (M_PI / 180);
	std::cout << radians << " radians\n\n";
}

void rotationSpeed() 
{
	double seconds;
	double speed;

	std::cout << "Seconds of one rotation? ";
	std::cin >> seconds;
	speed = 360 / seconds;
	std::cout << speed << " degrees/second\n\n";
}

void metersCovered() 
{
	double speed;
	double minutes;
	double distance;

	std::cout << "Speed (km/h)? ";
	std::cin >> speed;
	speed /= 60;
	std::cout << "Elapsed Time (Minutes)? ";
	std::cin >> minutes;
	distance = (speed * minutes) * 1000;
	std::cout << distance << " meters.\n\n";
}

void downwardVelocity()
{
	double seconds;
	double acceleration = 9.8;
	double velocity; 

	std::cout << "Seconds? ";
	std::cin >> seconds;
	velocity = seconds * acceleration;
	std::cout << "Velocity " << velocity << " m/sec\n\n";
}

void circleCalculations()
{
	double radius;
	double circumference;
	double area;

	std::cout << "Radius of circle? ";
	std::cin >> radius;
	circumference = radius * 2 * M_PI;
	area = radius * radius * M_PI;
	std::cout << "Circumference: " << circumference << "\n";
	std::cout << "Area: " << area << "\n\n";
}

void rectangleCalculations()
{
	double width;
	double height;
	double circumference;
	double area;

	std::cout << "Width and height? ";
	std::cin >> width >> height;
	circumference = (width + height) * 2;
	area = width * height;
	std::cout << "Circumference: " << circumference << "\n";
	std::cout << "Area: " << area << "\n\n";
}

void triangleCalculations()
{
	double base;
	double height;
	double area; 

	std::cout << "Base and height? ";
	std::cin >> base >> height;
	area = (base * height) / 2;
}