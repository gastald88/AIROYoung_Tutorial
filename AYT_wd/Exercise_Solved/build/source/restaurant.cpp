#include "restaurant.h"
#include "employee.h"

Restaurant::Restaurant() : Restaurant("")
{
}

Restaurant::Restaurant(string _name) : opening_period(ptime(), ptime()), name(_name)
{
}

void Restaurant::python()
{
	//expose two constructors
	//cannot change name

	using namespace boost::python;

	class_<Restaurant, Restaurant*>("Restaurant")
		.def(init<string>())
		.def_readonly("name", &Restaurant::name)
		.def_readwrite("opening_period", &Restaurant::opening_period)
		.def_readwrite("employees", &Restaurant::employees)
		;
}
