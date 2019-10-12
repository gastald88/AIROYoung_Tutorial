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

}
