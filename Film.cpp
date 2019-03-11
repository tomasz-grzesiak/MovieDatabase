#include "Film.h"

Film::Film()
{
}

Film::~Film()
{
}

void Film::SetPlace(int a)
{
	placeIMDb = a;
}

int Film::GetPlace()
{
	return placeIMDb;
}

void Film::Display()
{
	std::cout << "Tytul: " << title << std::endl;
	std::cout << "Miejsce w rankingu IMDb: " << placeIMDb << std::endl;
	if (followed)
		std::cout << "Sledzony: tak" << std::endl;
	else
		std::cout << "Sledzony: nie" << std::endl;
}

int Film::GetType()
{
	return 1;
}

