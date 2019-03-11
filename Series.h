#pragma once
#include "MovieishEntity.h"

class Series :
	public MovieishEntity
{
private:
	int season_couter;
public:
	Series();
	~Series();
	void SetSeasonCtr(int);
	int GetSeasonCtr();
	void Display();
	int GetType();
};

