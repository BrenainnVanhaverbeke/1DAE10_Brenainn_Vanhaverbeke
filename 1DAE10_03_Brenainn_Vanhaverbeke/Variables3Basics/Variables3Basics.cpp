// Vanhaverbeke, Brenainn - 1DAE10

#include "pch.h"
#include <iostream>

int main()
{
    int decimal = 12;
    int hexadecimal = 0xC;
    int binary = 0b1100;
    std::cout << decimal << ", " << hexadecimal << ", " << binary << "\n";
    int negativeIntOverflow = INT32_MIN - 1;
    int positiveIntOverflow = INT32_MAX + 1;
    unsigned int negativeUintOverflow = 0 - 1;
    unsigned int positiveUintOverflow = UINT32_MAX + 1;
    std::cout << negativeIntOverflow << "\n";
    std::cout << positiveIntOverflow << "\n";
    std::cout << negativeUintOverflow << "\n";
    std::cout << positiveUintOverflow << "\n";
    int a = 0b0011;
    int b = 0b0101;
    int c = a | b;
    std::cout << a << " | " << b << " = " << c << "\n";
    int checkBits;
    std::cin >> checkBits;
    std::cout << "1st bit: " << (checkBits & (1LL << 0)) << "\n";
    std::cout << " 2d bit: " << (checkBits & (1LL << 1)) << "\n";
    std::cout << " 3d bit: " << (checkBits & (1LL << 2)) << "\n";
    std::cout << "4th bit: " << (checkBits & (1LL << 3)) << "\n";
    int assignBit;
    std::cout << "Number to set 3rd bit in? ";
    std::cin >> assignBit;
    std::cout << "This number with 3d bit set " << (assignBit | (1LL << 2)) << "\n";
    unsigned int toShift = 2048;
    std::cout << (toShift >> 1) << "\n";
    std::cout << (toShift << 1) << "\n";
    unsigned int toShift = 0;
    toShift = toShift | 1LL << 0;
    toShift = toShift << 2;
    toShift = toShift | 1LL << 0;
    toShift = toShift << 2;
    toShift = toShift | 1LL << 0;
    toShift = toShift << 1;
    toShift = toShift | 1LL << 0;
    toShift = toShift << 2;
    toShift = toShift | 1LL << 0;
    toShift = toShift << 1;
    toShift = toShift | 1LL << 0;
    toShift = toShift << 2;
    toShift = toShift | 1LL << 0;
    toShift = toShift << 2;
    toShift = toShift | 1LL << 0;
    toShift = toShift << 1;
    toShift = toShift | 1LL << 0;
    toShift = toShift << 1;
    toShift = toShift | 1LL << 0;
    toShift = toShift << 2;
    toShift = toShift | 1LL << 0;
    toShift = toShift << 1;
    toShift = toShift | 1LL << 0;
    toShift = toShift << 1;
    toShift = toShift | 1LL << 0;
    toShift = toShift << 1;
    toShift = toShift | 1LL << 0;
    toShift = toShift << 1;
    toShift = toShift | 1LL << 0;
    toShift = toShift << 1;
    toShift = toShift | 1LL << 0;
    std::cout << toShift << "\n";
}