// Vanhaverbeke, Brenainn - 1DAE10

#include "pch.h"
#include "BasicAlgorithms.h"
#include <iostream>

int main()
{
	srand(unsigned int(time(nullptr)));
	TestCount();
	TestMinMax();
	TestSwap();
	TestShuffle();
	TestBubbleSort();
}


void TestCount()
{
	const int iterations{ 5 };
	std::cout << "-- Testing Count() --" << std::endl;
	for (int i{ 0 }; i < iterations; i++)
	{
		int toCount{ GetRandomNumber(g_LowestRandomNumber, g_HighestRandomNumber) };
		int testArray[g_DefaultArraySize]{};
		SeedRandomArray(testArray, g_DefaultArraySize);
		PrintArray(testArray, g_DefaultArraySize);
		std::cout << "Number \"" << toCount << "\" occurs " << Count(testArray, g_DefaultArraySize, toCount)
			<< " times in this array." << std::endl;
		std::cout << std::endl;
	}
}

int Count(int* pArray, int arraySize, int toCount)
{
	int counted{};
	for (int i{ 0 }; i < arraySize; i++)
	{
		if (toCount == pArray[i])
			counted++;
	}
	return counted;
}

void TestMinMax()
{
	const int iterations{ 5 };
	for (int i{ 0 }; i < iterations; i++)
	{
		int testArray[g_DefaultArraySize]{};
		SeedRandomArray(testArray, g_DefaultArraySize);
		PrintArray(testArray, g_DefaultArraySize);
		std::cout << MinElement(testArray, g_DefaultArraySize) << " is the smallest value in this array" << std::endl;
		std::cout << MaxElement(testArray, g_DefaultArraySize) << " is the biggest value in this array" << std::endl;;
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int MinElement(int* pArray, int arraySize)
{
	int smallest{ INT_MAX };
	for (int i{ 0 }; i < arraySize; i++)
	{
		if (pArray[i] < smallest)
			smallest = pArray[i];
	}
	return smallest;
}

int MaxElement(int* pArray, int arraySize)
{
	int biggest{ INT_MIN };
	for (int i{ 0 }; i < arraySize; i++)
	{
		if (biggest < pArray[i])
			biggest = pArray[i];
	}
	return biggest;
}

void TestSwap()
{
	const int iterations{ 5 };
	int toSwap{};
	int swapWith{};
	for (int i{ 0 }; i < iterations; i++)
	{
		int testArray[g_DefaultArraySize]{};
		SeedRandomArray(testArray, g_DefaultArraySize);
		std::cout << "Before swapping" << std::endl;
		PrintArray(testArray, g_DefaultArraySize);
		do
		{
			toSwap = GetRandomNumber(0, g_DefaultArraySize, false);
			swapWith = GetRandomNumber(0, g_DefaultArraySize, false);
		} while (toSwap == swapWith);
		Swap(testArray, toSwap, swapWith);
		std::cout << "After swapping element " << toSwap << " and element " << swapWith << std::endl;
		PrintArray(testArray, g_DefaultArraySize);
	}
	std::cout << std::endl;
}

void Swap(int* pArray, int toSwap, int swapWith)
{
	pArray[toSwap] = pArray[toSwap] + pArray[swapWith];
	pArray[swapWith] = pArray[toSwap] - pArray[swapWith];
	pArray[toSwap] = pArray[toSwap] - pArray[swapWith];
}

void TestShuffle()
{
	const int iterations{ 5 };
	for (int i{ 0 }; i < iterations; i++)
	{
		int testArray[g_DefaultArraySize]{};
		SeedUniqueValueArray(testArray, g_DefaultArraySize);
		int amountOfSwaps{ GetRandomNumber(10, 100) };
		std::cout << "Before shuffling" << std::endl;
		PrintArray(testArray, g_DefaultArraySize);
		Shuffle(testArray, g_DefaultArraySize, amountOfSwaps);
		std::cout << "After swapping " << amountOfSwaps << " times" << std::endl;
		PrintArray(testArray, g_DefaultArraySize);
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Shuffle(int* pArray, int arraySize, int amountOfSwaps)
{
	int toSwap{};
	int swapWith{};
	for (int i{ 0 }; i < amountOfSwaps; i++)
	{
		do
		{
			toSwap = GetRandomNumber(0, g_DefaultArraySize, false);
			swapWith = GetRandomNumber(0, g_DefaultArraySize, false);
		} while (toSwap == swapWith);
		Swap(pArray, toSwap, swapWith);
	}
}

void TestBubbleSort()
{
	const int iterations{ 5 };
	for (int i{ 0 }; i < iterations; i++)
	{
		int testArray[g_DefaultArraySize]{};
		SeedRandomArray(testArray, g_DefaultArraySize);
		std::cout << "Before sort" << std::endl;
		PrintArray(testArray, g_DefaultArraySize);
		BubbleSort(testArray, g_DefaultArraySize);
		std::cout << "After sort" << std::endl;
		PrintArray(testArray, g_DefaultArraySize);
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void BubbleSort(int* pArray, int arraySize)
{
	if (arraySize == 1)
		return;
	for (int i{ 0 }; i < arraySize - 1; i++)
	{
		if (pArray[i + 1] < pArray[i])
			Swap(pArray, i, i + 1);
	}
	BubbleSort(pArray, arraySize - 1);
}

void SeedUniqueValueArray(int* pArray, int size)
{
	for (int i{ 0 }; i < size; i++)
	{
		pArray[i] = i + 1;
	}
}

void SeedRandomArray(int* pArray, int size)
{
	for (int i{ 0 }; i < size; i++)
	{
		pArray[i] = GetRandomNumber(g_LowestRandomNumber, g_HighestRandomNumber, true);
	}
}

int GetRandomNumber(int lowestValue, int highestValue, bool isInclusive)
{
	int amountOfValues{ highestValue - lowestValue };
	if (isInclusive)
		amountOfValues++;
	return (rand() % amountOfValues) + lowestValue;
}

void PrintArray(int* pArray, int size)
{
	for (int i{ 0 }; i < size; i++)
	{
		std::cout << pArray[i] << " ";
	}
	std::cout << std::endl;
}

