// Applications.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
    //rgbaToFloat();
    //distanceConversion();
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
    std::cout << alpha / 255 << "\n";
}

void distanceConversion() 
{
    std::cout << "Distance in km? ";
    float distance;
    std::cin >> distance;
    std::cout << distance * 1000 << " meters. " << distance * 100000 << " cm.";
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
