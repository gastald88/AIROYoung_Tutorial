#pragma once

#include "recipe.h"

//implement a Customer class
class Customer
{
public:
	//variables
	Recipe desired_meal;
	ptime arrival_time;
	//methods
	Customer();
	static void python();
};