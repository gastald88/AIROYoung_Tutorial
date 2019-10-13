#include "customer.h"

Customer::Customer()
{
}

void Customer::python()
{
	//plain exposition of the variables

	using namespace boost::python;

	class_<Customer>("Customer")
		.def_readwrite("arrival_time", &Customer::arrival_time)
		.def_readwrite("desired_meal", &Customer::desired_meal)
		;
}
