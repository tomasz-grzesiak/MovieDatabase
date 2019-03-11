#pragma once
#include "MovieishEntity.h"
#include <ctime>

class Stream :
	public MovieishEntity
{
private:
	int month;
	int day;
public:
	Stream();
	~Stream();
	void SetDate(int, int);
	void Display();
	int GetType();
	int GetMonth();
	int GetDay();
};