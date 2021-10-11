// Vanhaverbeke, Brenainn - 1DAE10

#include "pch.h"
#include <iostream>

int main()
{
	//moduloOperation();
	//randomNumbers();
	//charConversion();
	//randomLetter();
	//roundingOperations();
	//aspectRatio();
	//syntacticSugar();
	return 0;
}

void moduloOperation()
{
	int number;
	std::cout << "Insert number: ";
	std::cin >> number;
	std::cout << number % 2;
}

void randomNumbers()
{
	srand(int(time(nullptr)));
	std::cout << rand() % 50 << "\n";
	std::cout << rand() % 70 + 10 << "\n";
	std::cout << rand() % 40 - 20 << "\n";
	std::cout << rand() % 4 - 2 << "\n";
	std::cout << float(rand() % 500 + 500) / 100.0f << "\n";
	std::cout << float(rand() % 1000 - 500) / 100.0f << "\n";
}

void charConversion()
{
	char character;
	std::cout << "Letter? ";
	std::cin >> character;
	std::cout << "Letter " << character << ". ASCII value " << (int)character;
}

void randomLetter()
{
	srand(int(time(nullptr)));
	char base = 'a';
	int offset = rand() % 26;
	char randomLetter = (char)base + offset;
	std::cout << "Random letter " << randomLetter << ". ASCII value " << (int)randomLetter;
}

void roundingOperations()
{
	float f1 = 5.44f;
	float f2 = 5.45f;
	float f3 = 5.51f;
	std::cout << f1 << ", rounded: " << round(f1) << ", int cast: " << (int)f1 << "\n";
	std::cout << f2 << ", rounded: " << round(f2) << ", int cast: " << (int)f2 << "\n";
	std::cout << f3 << ", rounded: " << round(f3) << ", int cast: " << (int)f3 << "\n";
}

void aspectRatio(float x, float y)
{
	std::cout << "The aspect ratio of (" << x << " x " << y << " is: " << x / y;
}

void syntacticSugar()
{
	int i = 10;
	int j{ ++i };
	std::cout << "i: " << i << ", j: " << j << "\n";
	int k = 10;
	int l{ k++ };
	std::cout << "k: " << k << ", l: " << l << "\n";
}