/**
 * @file py_exp.cpp
 * @author Gasta
 * @brief this file contains the Python exposition environment. It calls all the xxx::python() methods (just a design choice of mine, not a requirement)
 * @version 0.1
 * @date 2019-10-13
 * 
 * @copyright Copyright (c) 2019
 * 
 */
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