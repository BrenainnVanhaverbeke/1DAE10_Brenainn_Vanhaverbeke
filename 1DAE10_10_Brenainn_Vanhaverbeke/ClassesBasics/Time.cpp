#include "pch.h"
#include "Time.h"
#include <iostream>
#include <iomanip>

Time::Time(unsigned int seconds)
	: Time(0, 0, seconds)
{

}

Time::Time(unsigned int minutes, unsigned int seconds)
	: Time(0, minutes, seconds)
{
}

Time::Time(unsigned int hours, unsigned int minutes, unsigned int seconds)
	: m_Seconds{ seconds + (minutes * 60) + (hours * 3600) }
{
}

void Time::Print()
{
	std::cout << std::setfill('0') << std::setw(2) << GetHours() << ':';
	std::cout << std::setfill('0') << std::setw(2) << GetMinutes() << ':';
	std::cout << std::setfill('0') << std::setw(2) << GetSeconds() << std::endl;

}

unsigned int Time::GetSeconds()
{
	return (m_Seconds - (3600 * GetHours()) - (60 * GetMinutes()));
}

unsigned int Time::GetMinutes()
{
	return (m_Seconds - (3600 * GetHours())) / 60;
}

unsigned int Time::GetHours()
{
	return m_Seconds / 3600;
}

void Time::AddSeconds(unsigned int seconds)
{
	m_Seconds += seconds;
}

void Time::AddMinutes(unsigned int minutes)
{
	m_Seconds += minutes * 60;
}

void Time::AddHours(unsigned int hours)
{
	m_Seconds += hours * 3600;
}