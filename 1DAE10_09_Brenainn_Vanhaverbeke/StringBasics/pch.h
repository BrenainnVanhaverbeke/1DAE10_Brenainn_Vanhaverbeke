// Vanhaverbeke, Brenainn - 1DAE10

#ifndef PCH_H
#define PCH_H
#include <iostream>

void DisplayStringStatistics(const std::string& s);
void PrintStringSeperatedWithCharacter(const std::string& s, char seperator);
void PrintFirstAndLastLetterOfString(const std::string& s);
void FindInString(const std::string& toSearchIn, const std::string& toSearch);
void ReverseFindInString(const std::string& toSearchIn, const std::string& toSearch);
void ReplaceInString(std::string toReplaceIn, const std::string& toReplace, char replacingWith);
void EraseInString(std::string toDeleteIn, const std::string& toDelete);

#endif PCH_H