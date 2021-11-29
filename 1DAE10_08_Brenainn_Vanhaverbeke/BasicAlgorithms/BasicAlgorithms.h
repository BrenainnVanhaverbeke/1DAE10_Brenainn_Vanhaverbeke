#pragma once

const int g_DefaultArraySize{ 10 };
const int g_LowestRandomNumber{ -10 };
const int g_HighestRandomNumber{ 10 };

int Count(int* pArray, int arrayarraySize, int toCount);
int MinElement(int* pArray, int arraySize);
int MaxElement(int* pArray, int arraySize);
void Swap(int* pArray, int indexToSwap, int indexToSwapWith);
void Shuffle(int* pArray, int arraySize, int amountOfSwaps);
void BubbleSort(int* pArray, int arraySize);

int GetRandomNumber(int lowestValue, int highestValue, bool isInclusive = true);
void SeedRandomArray(int* pArray, int arraySize);
void SeedUniqueValueArray(int* pArray, int size);
void PrintArray(int* pArray, int arraySize);

void TestCount();
void TestMinMax();
void TestSwap();
void TestShuffle();
void TestBubbleSort();