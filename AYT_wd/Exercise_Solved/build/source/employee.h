#pragma once

#include "recipe.h"

class Restaurant;//fwd declaration

//implement the class Employee
class Employee
{
public:
	//methods
	Employee(string _name);
	virtual ~Employee() = default;
	void setTimePerDay(time_duration _time_per_day);
	time_duration getTimePerDay() const;
	Restaurant* getRestaurant();//throw exception if restaurant is nullptr
	void setRestaurant(Restaurant* _restaurant);
	string getName() const;
	virtual string whatDoIDo();
	static void python();
protected:
	//variables
	string name;
	Restaurant* restaurant;
	time_duration time_per_day;
};

//implement the class Cook derived from Employee
class Cook : public Employee
{
public:
	//variables
	vector<Recipe> known_recipes;//must use setter and getter to expose!
	//methods
	using Employee::Employee;
	static shared_ptr<Employee> create(string _name);
	string whatDoIDo() override;
	void setKnownRecipes(boost::python::list _known_recipes);
	const vector<Recipe> & getKnownRecipes() const;
	static void python();
};

//implement the class Waiter derived from Employee
class Waiter : public Employee
{
public:
	//methods
	using Employee::Employee;
	static Waiter* create(std::string _name);//allocates memory!
	string whatDoIDo() override;
	static void python();
};