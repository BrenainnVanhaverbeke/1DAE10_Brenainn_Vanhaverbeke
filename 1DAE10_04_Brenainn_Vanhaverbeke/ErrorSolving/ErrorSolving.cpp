// Vanhaverbeke, Brenainn - 1DAE10

#include <ctime>
#include <string> 
#include "pch.h"
#include <iostream>

#pragma region Function declarations

// Function declarations
void DetermineSkill();
void GetColorCodes();
void Wait();

#pragma endregion Function declarations


int main()
{
	std::cout << "== ErrorSolving - Vanhaverbeke, Brenainn - 1DAE10 ==\n";
	// rand seed
	srand(unsigned int(time(nullptr)));

	DetermineSkill();
	GetColorCodes();
	//Wait();
}

#pragma region Function definitions
// Function definitions
void GetColorCodes()
{
	enum Colours
	{
		Magenta,
		Yellow,
		Cyan
	};
	std::cout << "\n-- GetColorCodes function --\n";
	std::string menu{ "\nMake your choice\n1.Magenta\n2.Yellow\n3.Cyan\n?" };
	bool quit{ false };
	int choice{};
	std::cout << menu;
	std::cin >> choice;
	switch ((Colours)(choice -1))
	{
	case Magenta:
		std::cout << "Magenta 0xFF00FF\n";
		break;
	case Yellow:
		std::cout << "Yellow 0xFFFF00\n";
		break;
	case Cyan:
		std::cout << "Cyan 0x00FFFF\n";
		break;
	default:
		std::cout << "Wrong choice\n";
		GetColorCodes();
		break;
	}

	std::cin.ignore();
}


void DetermineSkill()
{
	std::cout << "\n-- DetermineSkill function --\n";

	int years{};
	std::cout << "Your years of experience ? ";
	std::cin >> years;
	std::string level{};
	if (years < 5)
	{
		level = "Junior level";
	}
	else if (years < 10)
	{
		level = "Intermediate level";
	}
	else
	{
		level = "Senior level";
	}
	std::cout << level << std::endl;

	std::cin.ignore();
}

void Wait()
{
	std::cout << "Press ENTER to quit";
	std::cin.get();
}