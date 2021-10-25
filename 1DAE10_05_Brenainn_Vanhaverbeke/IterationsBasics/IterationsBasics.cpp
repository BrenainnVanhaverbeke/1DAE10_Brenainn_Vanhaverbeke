// Vanhaverbeke, Brenainn - 1DAE10

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>

int main()
{
	srand(unsigned int(time(nullptr)));
	//Loops();
	//ExamScores();
	//RandomGuess();
	//Trigonometry();
	AsciiTable();
}

void Loops()
{
	std::cout << "-- Even Numbers --\n";
	int count{ 1 };
	while (++count < 24)
	{
		if (count % 2 == 0)
		{
			std::cout << count << " ";
		}
	}
	std::cout << std::endl;
	count = 1;
	do
	{
		if (count % 2 == 0)
		{
			std::cout << count << " ";
		}
	} while (++count < 24);
	std::cout << std::endl;
	for (int i = 1; i < 24; i++)
	{
		if (i % 2 == 0)
		{
			std::cout << i << " ";
		}
	}
}

// I hate everything about this function
void ExamScores()
{
	int ap{ 0 }, a{ 0 }, b{ 0 }, c{ 0 }, d{ 0 }, e{ 0 }, fx{ 0 }, f{ 0 };
	int input{};
	int total{ 0 };
	bool validInput{ true };
	bool endInput{ false };
	std::string inputString{ "Entered scores: " };
	do
	{
		validInput = true;
		std::cout << "Score [0,20] ? ";
		std::cin >> input;
		if (input != -1)
		{
			total += input;
			if (20 < input)
			{
				total -= input;
				validInput = false;
				std::cout << "Wrong score!\n";
			}
			else if (17 < input)
				ap++;
			else if (15 < input)
				a++;
			else if (14 < input)
				b++;
			else if (12 < input)
				c++;
			else if (10 < input)
				d++;
			else if (9 < input)
				e++;
			else if (7 < input)
				fx++;
			else if (-1 < input)
				f++;
			else
			{
				validInput = false;
				total -= input;
				std::cout << "Wrong score!\n";
			}
			if (validInput)
			{
				inputString += std::to_string(input) + ", ";
			}
		}
		else
		{
			inputString.pop_back();
			inputString.pop_back();
			validInput = false;
		}
	} while (input != -1);
	std::cout << "A+: " << ap << std::endl;
	std::cout << "A: " << a << std::endl;
	std::cout << "B: " << b << std::endl;
	std::cout << "C: " << c << std::endl;
	std::cout << "D: " << d << std::endl;
	std::cout << "E: " << e << std::endl;
	std::cout << "FX: " << fx << std::endl;
	std::cout << "F: " << f << std::endl;
	std::cout << "Total score: " << total << std::endl;
	std::cout << inputString << std::endl;
}

void RandomGuess()
{
	int toGuess{}, guess{}, count{ 0 };
	bool validNumber{ false };
	do
	{
		std::cout << "Number to guess? ";
		std::cin >> toGuess;
		validNumber = 0 <= toGuess;
	} while (!validNumber);
	do
	{
		guess = rand();
		count++;
	} while (guess != toGuess);
	std::cout << "Number found after " << count << " guesses.\n";
}

void Trigonometry()
{
	std::cout << "-- Trigonometry --\n";
	std::cout << std::setw(10) << "Degrees" << std::setw(10) << "Radians" << std::setw(10) << "Cos" << std::setw(10) << "Sin";
	for (int degrees = 0; degrees <= 180; degrees += 10)
	{
		float radians{ (float)degrees * ((float)M_PI / 180) };
		std::cout << std::endl;
		std::cout << std::fixed;
		std::cout << std::setw(10) << degrees;
		std::cout << std::setw(10) << std::setprecision(2) << radians;
		std::cout << std::setw(10) << std::setprecision(2) << cosf(radians);
		std::cout << std::setw(10) << std::setprecision(2) << sinf(radians);
	}
}

void AsciiTable()
{
	std::cout << "-- ASCII Table --\n";
	int letterOffset{ 13 };
	for (int i{ 0 }; i < letterOffset; i++)
	{
		int asciiOffset{ 97};
		char firstLetter{ (char)(asciiOffset + i) };
		char secondLetter{ (char)((int)firstLetter + letterOffset) };
		std::cout << std::setw(2) << firstLetter << std::setw(8) << (int)firstLetter;
		std::cout << std::setw(4) << secondLetter << std::setw(8) << (int)secondLetter;
		std::cout << std::endl;
	}
}