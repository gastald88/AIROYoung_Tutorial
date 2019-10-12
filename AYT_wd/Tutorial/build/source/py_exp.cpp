#include "zoo.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(AYT_tutorial)//same name of the output file
{
	//put here your xxx::python() function
	Animal::python();
	Dog::python();
	Crow::python();
	Zoo::python();
}