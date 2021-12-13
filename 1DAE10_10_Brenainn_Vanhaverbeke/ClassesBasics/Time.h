#pragma once
class Time
{
public:
	Time(unsigned int seconds);
	Time(unsigned int minutes, unsigned int seconds);
	Time(unsigned int hours, unsigned int minutes, unsigned int seconds);
	void Print();
	unsigned int GetSeconds();
	unsigned int GetMinutes();
	unsigned int GetHours();
	void AddSeconds(unsigned int seconds);
	void AddMinutes(unsigned int minutes);
	void AddHours(unsigned int hours);

private:
	unsigned int m_Seconds;
};