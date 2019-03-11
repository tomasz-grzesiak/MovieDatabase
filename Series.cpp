#include "Series.h"

Series::Series()
{
}

Series::~Series()
{
}

void Series::SetSeasonCtr(int a)
{
	season_couter = a;
}

int Series::GetSeasonCtr()
{
	return season_couter;
}

void Series::Display()
{
	std::cout << "Tytul: " << title << std::endl;
	std::cout << "Liczba sezonow: " << season_couter << std::endl;
	if (followed)
		std::cout << "Sledzony: tak" << std::endl;
	else
		std::cout << "Sledzony: nie" << std::endl;
}

int Series::GetType()
{
	return 0;
}