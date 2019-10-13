/**
 * @file restaurant.h
 * @author Gasta
 * @brief this file contains the restaurant class
 * @version 0.1
 * @date 2019-10-13
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#pragma once
#include "globals.h"

/**
 * @brief this is the restaurant class, where cooks and waiters work
 * 
 */
class Restaurant
{
public:
	//variables
	string name;
	time_period opening_period;///< time interval in a day in which the restaurant is open
	boost::python::list employees;///< the employees of the restaurant
	//methods
	/**
	 * @brief Construct a new Restaurant object
	 * 
	 */
	Restaurant();
	/**
	 * @brief Construct a new Restaurant object
	 * 
	 * @param _name the name of the restaurant
	 */
	Restaurant(string _name);
	/**
	 * @brief exposition to Python of this class
	 * 
	 */
	static void python();
};