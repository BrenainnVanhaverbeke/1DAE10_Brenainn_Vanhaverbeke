#include "pch.h"
#include "ClassesBasics.h"
#include <iostream>
#include "Square.h"
#include "Time.h"

int main()
{
	DoSquareTests();
	DoTimeTests();
}

void DoSquareTests()
{
	Square* pSquare{ new Square{5} };
	Square* pOtherSquare{ new Square{10, 5, 5} };
	pSquare->Print();
	pOtherSquare->Print();
	pSquare->SetSize(42);
	pSquare->Translate(4.0f, -3.0f);
	pSquare->Print();
	delete pSquare;
	delete pOtherSquare;
	pSquare = nullptr;
	pOtherSquare = nullptr;
}

void DoTimeTests()
{
	Time* pTime{ new Time{23, 16, 20} };
	Time* pTime2{ new Time{59, 59} };
	Time* pTime3{ new Time{450} };
	std::cout << pTime->GetHours() << std::endl;
	std::cout << pTime->GetMinutes() << std::endl;
	std::cout << pTime->GetSeconds() << std::endl;
	pTime->Print();
	std::cout << pTime2->GetHours() << std::endl;
	std::cout << pTime2->GetMinutes() << std::endl;
	std::cout << pTime2->GetSeconds() << std::endl;
	pTime2->Print();
	pTime3->Print();
	pTime3->AddHours(1);
	pTime3->AddMinutes(20);
	pTime3->Print();
	delete pTime;
	delete pTime2;
	delete pTime3;
	pTime = nullptr;
	pTime2 = nullptr;
	pTime3 = nullptr;
}