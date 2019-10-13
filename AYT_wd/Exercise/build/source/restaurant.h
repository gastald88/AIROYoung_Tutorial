#pragma once
#include "globals.h"

//implement the Restaurant class
class Restaurant
{
public:
	//variables
	string name;
	time_period opening_period;
	boost::python::list employees;
	//methods
	Restaurant();
	Restaurant(string _name);
	static void python();
};