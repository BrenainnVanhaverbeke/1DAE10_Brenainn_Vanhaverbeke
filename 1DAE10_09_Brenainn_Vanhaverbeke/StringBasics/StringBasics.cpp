// Vanhaverbeke, Brenainn - 1DAE10

#include "pch.h"

int main()
{
	const std::string theMetamorphosis{ "One morning, when Gregor Samsa woke from troubled dreams, he found himself transformed in his bed into a horrible vermin. He lay on his armour-like back, and if he lifted his head a little he could see his brown belly, slightly domed and divided by arches into stiff sections. The bedding was hardly able to cover it and seemed ready to slide off any moment. His many legs, pitifully thin compared with the size of the rest of him, waved about helplessly as he looked." };
	std::cout << "--- Original string: ---" << std::endl << std::endl;
	std::cout << theMetamorphosis << std::endl << std::endl;
	std::cout << "--- The Metamorphosis statistics: ---" << std::endl << std::endl;
	DisplayStringStatistics(theMetamorphosis);
	std::cout << "--- The Metamorphosis seperated by '_' ---" << std::endl << std::endl;
	PrintStringSeperatedWithCharacter(theMetamorphosis, '_');
	std::cout << "--- First and last letter of The Metamorphosis ---" << std::endl << std::endl;
	PrintFirstAndLastLetterOfString(theMetamorphosis);
	std::cout << "--- Finding string in The Metamorphosis ---" << std::endl << std::endl;
	std::string userInput{};
	std::cout << "Please insert a string to find in The Metamorphosis: ";
	std::cin >> userInput;
	FindInString(theMetamorphosis, userInput);
	std::cout << "Finding your string in reverse order: " << std::endl;
	ReverseFindInString(theMetamorphosis, userInput);
	std::cout << "Replacing your string with '*': " << std::endl;
	ReplaceInString(theMetamorphosis, userInput, '*');
	std::cout << "Erasing your string: " << std::endl;
	EraseInString(theMetamorphosis, userInput);
}

void DisplayStringStatistics(const std::string& s)
{
	const size_t stringLength{ s.length() };
	const size_t stringSize{ s.size() };
	const size_t stringCapacity{ s.capacity() };
	std::cout << "Length: " << stringLength << std::endl;
	std::cout << "Size: " << stringSize << std::endl;
	std::cout << "Capacity: " << stringCapacity << std::endl;
	std::cout << std::endl;
}

void PrintStringSeperatedWithCharacter(const std::string& s, char seperator)
{
	const size_t stringSize{ s.size() };
	const char* pStringChars{ s.c_str() };
	for (size_t i{ 0 }; i < stringSize; ++i)
	{
		std::cout << s[i];
		if (i < stringSize - 1)
			std::cout << seperator;
	}
	std::cout << std::endl << std::endl;
}

void PrintFirstAndLastLetterOfString(const std::string& s)
{
	const size_t stringSize{ s.size() };
	std::cout << "First character using []: " << s[0] << std::endl;
	std::cout << "Last character using []: " << s[stringSize - 1] << std::endl;
	std::cout << "First character using at: " << s.at(0) << std::endl;
	std::cout << "Last character using at: " << s.at(stringSize - 1) << std::endl;
	std::cout << std::endl;
}

void FindInString(const std::string& toSearchIn, const std::string& toSearch)
{
	size_t position{ 0 };
	std::cout << "Occurances of '" << toSearch << "' at: " << std::endl;
	do
	{
		position = toSearchIn.find(toSearch, position);
		if (position != std::string::npos)
		{
			std::cout << position << " ";
			position++;
		}
	} while (position != std::string::npos);
	std::cout << std::endl << std::endl;
}

void ReverseFindInString(const std::string& toSearchIn, const std::string& toSearch)
{
	size_t position{ toSearchIn.size() - 1 };
	std::cout << "Occurances of '" << toSearch << "' at: " << std::endl;
	do
	{
		position = toSearchIn.rfind(toSearch, position);
		if (position != std::string::npos)
		{
			std::cout << position << " ";
			position--;
		}
	} while (position != std::string::npos);
	std::cout << std::endl << std::endl;
}

void ReplaceInString(std::string toReplaceIn, const std::string& toReplace, char replacingWith)
{
	size_t position{};
	std::string replacementString{};
	for (size_t i = 0; i < toReplace.size(); i++)
		replacementString += replacingWith;
	do
	{
		position = toReplaceIn.find(toReplace, position);
		if (position != std::string::npos)
		{
			toReplaceIn.replace(position, toReplace.size(), replacementString);
			position++;
		}
	} while (position != std::string::npos);
	std::cout << toReplaceIn << std::endl;
	std::cout << std::endl;
}

void EraseInString(std::string toEraseIn, const std::string& toErase)
{
	size_t position{};
	do
	{
		position = toEraseIn.find(toErase, position);
		if (position != std::string::npos)
		{
			toEraseIn.erase(position, toErase.size());
			position++;
		}
	} while (position != std::string::npos);
	std::cout << toEraseIn << std::endl;
	std::cout << std::endl;
}