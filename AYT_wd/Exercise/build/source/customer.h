/**
 * @file customer.h
 * @author Gasta
 * @brief this file contains the Customer class
 * @version 0.1
 * @date 2019-10-13
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#pragma once

#include "recipe.h"

/**
 * @brief the customer class represents the agent that goes to a restaurant and 
 * asks for a recipe
 * 
 */
class Customer
{
public:
	//variables
	Recipe desired_meal;
	ptime arrival_time;///< time of arrival at the restaurant of this customer
	//methods
	/**
	 * @brief Construct a new Customer object
	 * 
	 */
	Customer();
	/**
	 * @brief exposition to Python of this class
	 * 
	 */
	static void python();
};