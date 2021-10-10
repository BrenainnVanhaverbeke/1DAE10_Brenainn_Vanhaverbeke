// Vanhaverbeke, Brenainn - 1DAE10

#include "pch.h"
#include <iostream>

int main()
{
    int number = 5;
    char letter = 'C';
    bool binaryValue = false;
    float floatingPointValue = 0.1f;
    double preciseFloatingPointValue = 0.2f;

    std::cout << number;
    std::cout << letter;
    std::cout << binaryValue;
    std::cout << floatingPointValue;
    std::cout << preciseFloatingPointValue;
    std::cout << number + 4;
    std::cout << floatingPointValue + 0.2f;
    std::cout << letter + 'D';
    std::cout << number + letter + "potatomancy";
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
