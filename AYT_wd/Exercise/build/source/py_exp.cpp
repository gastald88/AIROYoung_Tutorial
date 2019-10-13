#include "globals.h"
#include "employee.h"
#include "TSP.h"
#include "customer.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(AYT_exercise)//same name of the output file
{
	//put here your xxx::python() function
	Recipe::python();
	Employee::python();
	Cook::python();
	Waiter::python();
	Restaurant::python();
	Customer::python();
	Trip::python();
	Network::python();

	def("TSP", &TSP);


	//Expose some boost date time classes
	//TIME DURATION: represents an amount of time with (H,M,S) interface
	class_<time_duration>("time_duration", init<time_t, time_t, time_t>())
		//operator <<
		.def(self_ns::str(self_ns::self))
		.def("total_seconds", &time_duration::total_seconds)
		.def("seconds", &time_duration::seconds)
		.def("minutes", &time_duration::minutes)
		.def("hours", &time_duration::hours)
		//other operators
		.def(self + self)
		.def(self - self)
		.def(self > self)
		.def(self < self)
		.def(self == self)
		.def(ptime() + self)
		;

	//DATE date with (YYYY,M,D) interface
	class_<date>("date", init<unsigned, unsigned, unsigned>())
		.def(self_ns::str(self_ns::self))
		;

	//TIME time as DATE and TIME DURATION
	class_<ptime>("time", init<date, time_duration>())
		.def(self_ns::str(self_ns::self))
		.def(self > self)
		.def(self < self)
		.def(self == self)
		.def("timeOfDay", &ptime::time_of_day)
		;

	//TIME PERIOD: represents a time interval between two TIMEs
	class_<time_period>("time_period", init<ptime, ptime>())
		.def(self_ns::str(self_ns::self))
		.def("begin", &time_period::begin)
		.def("end", &time_period::end)
		;
}