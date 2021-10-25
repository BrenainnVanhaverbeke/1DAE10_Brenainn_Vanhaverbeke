// Vanhaverbeke, Brenainn - 1DAE10

#include "pch.h"
#include <iostream>

int main()
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