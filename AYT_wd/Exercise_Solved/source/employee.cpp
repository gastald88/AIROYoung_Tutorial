#include "employee.h"
#include "restaurant.h"

void Employee::python()
{
	//Do not expose the constructor for this class
	//Expose protected variables by their getter and setter methods
	//tell python its going to run into shared_ptr<Employee>

	using namespace boost::python;

	class_<Employee, shared_ptr<Employee>>("Employee", no_init)
		.add_property("name", &Employee::getName)
		.add_property("time_per_day", &Employee::getTimePerDay, &Employee::setTimePerDay)
		.add_property("restaurant", make_function(&Employee::getRestaurant, return_internal_reference<>()), &Employee::setRestaurant)
		.def("whatDoIDo", &Employee::whatDoIDo)
		;
}

string Employee::getName() const
{
	return name;
}

Employee::Employee(string _name) : name(_name), restaurant(nullptr)
{
}

shared_ptr<Employee> Cook::create(string _name)
{
	return std::make_shared<Cook>(_name);
}

string Cook::whatDoIDo()
{
	return "I am a cook!";
}

void Cook::setKnownRecipes(boost::python::list _known_recipes)
{
	known_recipes.clear();
	for (int i = 0; i < len(_known_recipes); i++)
	{
		Recipe r = boost::python::extract<Recipe>(_known_recipes[i]);
		known_recipes.push_back(r);
	}
}

const vector<Recipe>& Cook::getKnownRecipes() const
{
	return known_recipes;
}

void Cook::python()
{
	//expose also the vector of recipes
	//remember that create is static
	//no constructor allowed
	//watch returning internal reference

	using namespace boost::python;

	class_<vector<Recipe>>("recipe_container")
		.def(vector_indexing_suite<vector<Recipe>>())
		;

	class_<Cook, bases<Employee>>("Cook", no_init)
		.add_property("known_recipes", make_function(&Cook::getKnownRecipes, return_internal_reference<>()), &Cook::setKnownRecipes)
		.def("create", &Cook::create)
		.staticmethod("create")
		;
}

void Employee::setTimePerDay(time_duration _time_per_day)
{
	time_per_day = _time_per_day;
}

time_duration Employee::getTimePerDay() const
{
	return time_per_day;
}

Waiter* Waiter::create(std::string _name)
{
	return new Waiter(_name);
}

string Waiter::whatDoIDo()
{
	return "I am a Waiter!";
}

void Waiter::python()
{
	//remember that create is static
	//no constructor allowed

	using namespace boost::python;

	class_<Waiter, bases<Employee>>("Waiter", no_init)
		.def("create", &Waiter::create, return_value_policy<manage_new_object>())
		.staticmethod("create")
		;
}

Restaurant* Employee::getRestaurant()
{
	return restaurant;
}

void Employee::setRestaurant(Restaurant* _restaurant)
{
	restaurant = _restaurant;
}

string Employee::whatDoIDo()
{
	throw std::runtime_error("method not implemented");
}
