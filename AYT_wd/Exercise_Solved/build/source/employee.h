/**
 * @file employee.h
 * @author Gasta
 * @brief this file contains the base class for employees and the derived classes Cook and Waiter
 * @version 0.1
 * @date 2019-10-13
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#pragma once

#include "recipe.h"

class Restaurant;//fwd declaration

/**
 * @brief this is a base class for employees working in a restaurant
 * 
 */
class Employee
{
public:
	//methods
	/**
	 * @brief Construct a new Employee object
	 * 
	 * @param _name the name of the employee
	 */
	Employee(string _name);
	/**
	 * @brief Destroy the Employee object
	 * 
	 */
	virtual ~Employee() = default;
	/**
	 * @brief Set the Time Per Day object
	 * 
	 * @param _time_per_day the time in a day worked by this employee
	 */
	void setTimePerDay(time_duration _time_per_day);
	/**
	 * @brief Get the Time Per Day object
	 * 
	 * @return the time in a day worked by this employee 
	 */
	time_duration getTimePerDay() const;
	/**
	 * @brief Get the Restaurant object
	 * 
	 * @return pointer to the restaurant where the employee works
	 */
	Restaurant* getRestaurant();
	/**
	 * @brief Set the Restaurant object
	 * 
	 * @param _restaurant the restaurant where the employee works
	 */
	void setRestaurant(Restaurant* _restaurant);
	/**
	 * @brief Get the Name object
	 * 
	 * @return the name of the employee 
	 */
	string getName() const;
	/**
	 * @brief this method is to be overridden. it let the employee say his role in the restaurant
	 * 
	 * @return the role in the restaurant of the employee 
	 */
	virtual string whatDoIDo();
	/**
	 * @brief exposition to Python of this class
	 * 
	 */
	static void python();
protected:
	//variables
	string name;
	Restaurant* restaurant;///< restaurant where the employee works
	time_duration time_per_day;///< the time in a day worked by this employee 
};

/**
 * @brief the class Cook derived from Employee
 * 
 */
class Cook : public Employee
{
public:
	//methods
	using Employee::Employee;
	/**
	 * @brief creates an instance of Cook
	 * 
	 * @param _name the name of the cook
	 * @return smart pointer to the cook instance
	 */
	static shared_ptr<Employee> create(string _name);
	string whatDoIDo() override;
	/**
	 * @brief Set the Known Recipes object
	 * 
	 * @param _known_recipes a python list containing the recipes known by the cook
	 */
	void setKnownRecipes(boost::python::list _known_recipes);
	/**
	 * @brief Get the Known Recipes object
	 * 
	 * @return the vector of recipes known by the cook
	 */
	const vector<Recipe> & getKnownRecipes() const;
	/**
	 * @brief exposition to Python of this class
	 * 
	 */
	static void python();
private:
	//variables
		vector<Recipe> known_recipes;///< the vector of recipes known by the cook
};

/**
 * @brief the class Waiter derived from Employee
 * 
 */
class Waiter : public Employee
{
public:
	//methods
	using Employee::Employee;
	/**
	 * @brief creates an instance of Waiter
	 * 
	 * @param _name the name of the waiter
	 * @return raw pointer to the created instance. It allocates memory to be managed
	 */
	static Waiter* create(std::string _name);
	string whatDoIDo() override;
	/**
	 * @brief exposition to Python of this class
	 * 
	 */
	static void python();
};