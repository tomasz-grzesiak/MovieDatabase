#pragma once
#include "Set.h"
#include "Film.h"
#include "Stream.h"
#include "Series.h"
#include <iostream>

class Menu
{
public:
	Menu();
	~Menu();
	void Display();
	MovieishEntity* Add();
};

