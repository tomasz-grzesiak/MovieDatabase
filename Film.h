#pragma once
#include "MovieishEntity.h"

class Film :
	public MovieishEntity
{
private:
	int placeIMDb;
public:
	Film();
	~Film();
	void SetPlace(int);
	int GetPlace();
	void Display();
	int GetType();
};

