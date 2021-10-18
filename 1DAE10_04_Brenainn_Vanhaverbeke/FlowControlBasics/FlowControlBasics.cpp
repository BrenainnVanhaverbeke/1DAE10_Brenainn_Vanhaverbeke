// Vanhaverbeke, Brenainn - 1DAE10

#include "pch.h"
#include <iostream>
#include <format>

int main()
{
	srand(unsigned int(time(nullptr)));
	//PrintTruthTables();
	//CompareTwoNumbers();
	//CalculatePrice();
	//ConvertDayNumber();
	//CheckLeapYear();
	//ConvertSeconds();
	//UseActorState();
	UsePoint2f();
}

void PrintTruthTables()
{
	bool a{ true };
	bool b{ true };
	std::cout << "true && true is " << std::boolalpha << (a && b) << std::endl;
	b = false;
	std::cout << "true && false is " << std::boolalpha << (a && b) << std::endl;
	a = false;
	b = true;
	std::cout << "false && true is " << std::boolalpha << (a && b) << std::endl;
	b = false;
	std::cout << "false && false is " << std::boolalpha << (a && b) << std::endl;
	a = true;
	b = true;
	std::cout << "true || true is " << std::boolalpha << (a || b) << std::endl;
	b = false;
	std::cout << "true || false is " << std::boolalpha << (a || b) << std::endl;
	a = false;
	b = true;
	std::cout << "false || true is " << std::boolalpha << (a || b) << std::endl;
	b = false;
	std::cout << "false || false is " << std::boolalpha << (a || b) << std::endl;
}

void CompareTwoNumbers()
{
	int number1 = rand() % 11;
	int number2 = rand() % 11;
	std::cout << "First number is " << number1 << std::endl;
	std::cout << "Second number is " << number2 << std::endl;
	if (number1 < number2)
	{
		std::cout << "Second number is larger than first one.\n";
	}
	else if (number1 == number2)
	{
		std::cout << "They are the same number.\n";
	}
	else
	{
		std::cout << "First number is larger than the second one.\n";
	}
}

void CalculatePrice()
{
	float nrOfBallpoints;
	float pricePerUnit;
	std::cout << "-- Calculate Price --\n";
	std::cout << "Nr of ballpoints? ";
	std::cin >> nrOfBallpoints;
	if (nrOfBallpoints < 20)
	{
		pricePerUnit = 4.00f;
	}
	else if (20 <= nrOfBallpoints && nrOfBallpoints < 50)
	{
		pricePerUnit = 3.50f;
	}
	else if (50 <= nrOfBallpoints && nrOfBallpoints <= 100)
	{
		pricePerUnit = 3.25f;
	}
	else
	{
		pricePerUnit = 3.10f;
	}
	std::cout << "Price per unit is " << pricePerUnit << std::endl;
	std::cout << "Total price is " << nrOfBallpoints * pricePerUnit << std::endl;
}

void ConvertDayNumber()
{
	int dayNumber;
	std::cout << "Day number [1, 7] ? ";
	std::cin >> dayNumber;
	if (1 == dayNumber)
		std::cout << "Start of the week. \n";
	else if (2 <= dayNumber && dayNumber <= 4)
		std::cout << "Middle of the week. \n";
	else if (5 == dayNumber)
		std::cout << "Nearly weekend. \n";
	else if (dayNumber == 6 || dayNumber == 7)
		std::cout << "Weekend. \n";
	else
		std::cout << "Wrong day number. \n";
	switch (dayNumber)
	{
	case 1:
		std::cout << "Monday.\n";
		break;
	case 2:
		std::cout << "Tuesday.\n";
		break;
	case 3:
		std::cout << "Wednesday.\n";
		break;
	case 4:
		std::cout << "Thursday.\n";
		break;
	case 5:
		std::cout << "Friday.\n";
		break;
	case 6:
		std::cout << "Saturday.\n";
		break;
	case 7:
		std::cout << "Sunday.\n";
		break;
	default:
		std::cout << "Wrong day number.\n";
		break;
	}
}

void CheckLeapYear()
{
	int year;
	int daysInFebruary;
	std::cout << "-- Check leap year --\n";
	std::cout << "Year? ";
	std::cin >> year;
	if (year % 4 == 0 && year % 100 != 0)
	{
		daysInFebruary = 29;
	}
	else
	{
		daysInFebruary = 28;
		if (year % 400 == 0)
		{
			daysInFebruary = 29;
		}
	}
	std::cout << year << ": " << daysInFebruary << std::endl;
}

void ConvertSeconds()
{
	int days;
	int hours;
	int minutes;
	int seconds;
	int secondsInDay{ 86400 };
	int secondsInHour{ 3600 };
	int secondsInMinute{ 60 };
	std::cout << "-- Convert Seconds --\n";
	std::cout << "Number of seconds? ";
	std::cin >> seconds;
	days = seconds / secondsInDay;
	seconds -= days * secondsInDay;
	hours = seconds / secondsInHour;
	seconds -= hours * secondsInHour;
	minutes = seconds / secondsInMinute;
	seconds -= minutes * secondsInMinute;
	std::cout << days << " days.\n";
	std::cout << hours << " hours.\n";
	std::cout << minutes << " minutes.\n";
	std::cout << seconds << " seconds.\n";
}

void UseActorState()
{
	enum class ActorState
	{
		running,
		flying,
		falling
	};
	ActorState state{ (ActorState)(rand() % 3) };
	switch (state)
	{
	case ActorState::running:
		std::cout << "Actor is running.\n";
		break;
	case ActorState::flying:
		std::cout << "Actor is flying.\n";
		break;
	case ActorState::falling:
		std::cout << "Actor is falling.\n";
		break;
	default:
		break;
	}
}

void UsePoint2f()
{
	struct Point2f
	{
		float x{};
		float y{};
	};
	Point2f p1;
	Point2f p2{};
	Point2f p3{ 26, 25 };
	std::cout << "p2: [" << p2.x << ", " << p2.y << "]\n";
	std::cout << "p3: [" << p3.x << ", " << p3.y << "]\n";
	p1.x = 20;
	p1.y = 3;
	p2.x = 30;
	p2.y = 40;
	p3.x = 27;
	p3.y = 24;
	std::cout << "Values after changing the members.\n";
	std::cout << "p1: [" << p1.x << ", " << p1.y << "]\n";
	std::cout << "p2: [" << p2.x << ", " << p2.y << "]\n";
	std::cout << "p3: [" << p3.x << ", " << p3.y << "]\n";
}