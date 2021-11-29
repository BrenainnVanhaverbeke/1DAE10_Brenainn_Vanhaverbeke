// Vanhaverbeke, Brenainn - 1DAE10

#include "pch.h"
#include "ArrayBasics.h"
#include "structs.h"
#include <iostream>

int main()
{
	const int arraySize{ 5 };

	int numbers1Array[arraySize]{};
	int numbers2Array[arraySize]{ 10, 20, 30, 40, 50 };
	int numbers3Array[arraySize]{ 5, 10, 15 };

	std::cout << "-- Accessing Elements --" << std::endl;;
	std::cout << "First element: " << numbers2Array[0] << std::endl;
	std::cout << "Last element: " << numbers2Array[4] << std::endl;
	std::cout << "Iterating over elements: " << std::endl;
	for (int i{ 0 }; i < sizeof(numbers2Array) / sizeof(numbers2Array[0]); i++)
	{
		std::cout << numbers2Array[i] << std::endl;
		numbers2Array[i]++;
		std::cout << numbers2Array[i] << std::endl;
	}

	std::cout << "-- Size of arrays --" << std::endl;
	std::cout << "3d Array" << std::endl;
	std::cout << "  Nr of bytes: " << sizeof(numbers3Array) << std::endl;
	std::cout << "  Size of one element: : " << sizeof(numbers3Array[0]) << std::endl;
	std::cout << "  Nr of elements: " << sizeof(numbers3Array) / sizeof(numbers3Array[0]) << std::endl;

	for (int i{ 0 }; i < sizeof(numbers3Array) / sizeof(numbers3Array[0]); i++)
	{
		std::cout << numbers3Array[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "-- References of int elements --" << std::endl;
	for (int i{ 0 }; i < sizeof(numbers3Array) / sizeof(numbers3Array[0]); i++)
	{
		std::cout << &numbers3Array[i] << std::endl;
	}

	std::cout << "-- References of Point2f elements --" << std::endl;
	Point2f pointsArray[arraySize]{};
	for (int i{ 0 }; i < sizeof(pointsArray) / sizeof(pointsArray[0]); i++)
	{
		std::cout << &pointsArray[i] << std::endl;
	}

	std::cout << "-- Passing an array to a function, PrintElements --" << std::endl;
	PrintElements(numbers3Array, arraySize);
	PrintElements(numbers2Array, 2, 4);

	std::cout << "-- 2D arrays --" << std::endl;
	const int rows{ 4 };
	const int columns{ 5 };
	const int linearGridArraySize{ rows * columns };

	int linearGridArray[linearGridArraySize];
	for (int row{ 0 }; row < rows; row++)
	{
		for (int column{ 0 }; column < columns; column++)
		{
			int index{ GetIndex(row, column, columns) };
			linearGridArray[index] = (row + 1) * 10 + column + 1;
		}
	}
	Print2DElements(linearGridArray, rows, columns);
}

void PrintElements(int* pNumbers, int size)
{
	for (int i{ 0 }; i < size; i++)
	{
		std::cout << pNumbers[i] << " ";
	}
	std::cout << std::endl;
}

void PrintElements(int* pNumbers, int startIndex, int endIndex)
{
	for (int i{ startIndex }; i <= endIndex; i++)
	{
		std::cout << pNumbers[i] << " ";
	}
	std::cout << std::endl;
}

void Print2DElements(int* pNumbers, int rows, int columns)
{
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			int index{ GetIndex(row, column, columns) };
			std::cout << pNumbers[index] << " ";
		}
		std::cout << std::endl;
	}
}

int GetIndex(int rowIndex, int columnIndex, int nrOfColumns)
{
	return rowIndex * nrOfColumns + columnIndex;
}