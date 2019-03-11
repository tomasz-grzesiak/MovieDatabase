#include "Stream.h"

Stream::Stream()
{
	followed = true;
}


Stream::~Stream()
{
}

void Stream::SetDate(int a, int b)
{
	day = a;
	month = b;
}

void Stream::Display()
{
	std::cout << "Tytul: " << title << std::endl;
	std::cout << "Data: " << day << "." << month << std::endl;
	if(followed)
		std::cout << "Sledzony: tak" << std::endl;
	else
		std::cout << "Sledzony: nie" << std::endl;
}

int Stream::GetType()
{
	return 2;
}
int Stream::GetMonth()
{
	return month;
}

int Stream::GetDay()
{
	return day;
}