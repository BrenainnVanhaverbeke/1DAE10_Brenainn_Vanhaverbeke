// Name, firstname
// 1DAExx

// Include directives
#include "pch.h"
#include <iostream>
#include <ctime>
#include <string> 

#pragma region Function declarations
// Function declarations
void ShowMultiplyTable();
void GuessNumber();
void GetNumber();

void Wait();
#pragma endregion Function declarations

int main()
{
	std::cout << "== ErrorSolving - name, firstname - 1DAExx ==\n";
	// rand seed
	srand(unsigned int(time(nullptr)));

	ShowMultiplyTable();
	GuessNumber();
	GetNumber();
	Wait();
}

#pragma region Function definitions
// Function definitions



void ShowMultiplyTable()
{
	std::cout << "\n-- ShowMultiplyTable function --\n";

	int table{ 5 };
	std::cout << "Multiply " << table << " table\n";
	for (int times{ 0 }; times <= 10; ++times)
	{
		std::cout << table << " x " << times << " = " << table * times << std::endl;
	}
}

void GuessNumber()
{
	std::cout << "\n-- GuessNumber function --\n";

	int randNr{};
	int guess{};
	std::cout << "Number in [0, 10] ? ";
	std::cin >> guess;
	int trials{ 0 };
	do
	{
		randNr = rand() % 10 + 1;
		trials++;
	} while (guess != randNr);

	std::cout << "You entered the right number " << randNr << " after " << trials << " guesses!\n";
	std::cin.ignore();
}


void GetNumber()
{
	std::cout << "\n-- GetNumber function --\n";

	const int min{ 5 };
	const int max{ 10 };
	int nr{};
	bool wrongInput{ false };
	do
	{
		std::string questionMsg{ "Enter a number in the interval [" +
			std::to_string(min) + ", " + std::to_string(max) + "] " };
		std::cout << questionMsg;
		std::cin >> nr;
		wrongInput = min <= nr && nr <= max;
		if (!wrongInput)
		{
			std::string errorMsg{ "Sorry, but this is not a correct number\n" };
			std::cout << errorMsg;
		}
	} while (!wrongInput);
	std::cout << "You entered the number " << nr << '\n';

	std::cin.ignore();
}

void Wait()
{
	std::cout << "Press ENTER to quit";
	std::cin.get();
}
#pragma endregion Function definitions
