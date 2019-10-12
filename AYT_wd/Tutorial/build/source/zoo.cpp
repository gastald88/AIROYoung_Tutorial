#include "zoo.h"

string Animal::getName() const
{
	return name;
}

void Animal::setName(string _name)
{
	name = _name;
}

Zoo & Animal::getZoo()
{
	if (zoo == nullptr)
		throw std::runtime_error("zoo is NULL");
	return *zoo;
}

void Animal::setZoo(Zoo & _zoo)
{
	zoo = &_zoo;
}

string Animal::makeNoise() const
{
	throw std::runtime_error("method is not implemented");
}

bool Animal::operator==(const Animal & a) const
{
	return this->name == a.name;
}

void Animal::python()
{
	using namespace boost::python;

	enum_<Environment>("Environment")
		.value("Land", Land)
		.value("Water", Water)
		.value("Air", Air)
		;

	class_<Animal, shared_ptr<Animal>>("Animal")//default constructor is exposed. Other type of constructor exposition will be shown later
		.def_readwrite("environment", &Animal::environment)
		.def_readwrite("num_paws", &Animal::num_paws)
		.add_property("name", &Animal::getName, &Animal::setName)//getter and setter can be used implicitely by properties (they behave like member variables)
		.add_property("zoo", make_function(&Animal::getZoo, return_internal_reference<>()), &Animal::setZoo)//must specify the return policy when returning references
		.def("makeNoise", &Animal::makeNoise)//this is not abstract but it throws an exception. If you need to expose an abstract class, things are tricky, but doable
		.def(self_ns::str(self_ns::self))//easy exposition of the ostream operator
		.def(self == self)//easy exposition of operators
		;
}

std::ostream & operator<<(std::ostream & os, const Animal & a)
{
	os << a.name;
	return os;
}

string Dog::makeNoise() const
{
	return "wof!";
}

shared_ptr<Animal> Dog::create()
{
	return std::make_shared<Dog>();
}

void Dog::python()
{
	using namespace boost::python;

	//, shared_ptr<Animal>

	class_<Dog, bases<Animal>>("Dog", no_init)//inherit all exposition of animal. Forbid any constructor
		.def("create", &Dog::create).staticmethod("create")//need to mark the static methods
		;
}

string Crow::makeNoise() const
{
	return "cra!";
}

Crow * Crow::create()
{
	return new Crow();
}

void Crow::python()
{
	using namespace boost::python;

	class_<vector<string>>("string_container")//easy exposition of vectors
		.def(vector_indexing_suite<vector<string>>())
		;

	class_<Crow, bases<Animal>>("Crow")//inherit all exposition of animal
		.def_readwrite("visited_cities", &Crow::visited_cities)//the vector registered to Python right above
		.def("create", &Crow::create, return_value_policy<manage_new_object>()).staticmethod("create")//specify return value policy
		;
}

Zoo::Zoo() : Zoo("")
{
}

Zoo::Zoo(string _name) : name(_name)
{
}

void Zoo::python()
{
	using namespace boost::python;

	class_<vector<shared_ptr<Animal>>>("animal_container")
		.def(vector_indexing_suite<vector<shared_ptr<Animal>>, true>())//true is needed to tell the exposed container to consider the sub-classes
		;

	class_<Zoo>("Zoo")//default constructor exposed
		.def(init<string>())//another constructor exposed
		.def_readonly("name", &Zoo::name)//name exposed only for read mode
		.def_readwrite("dogs", &Zoo::dogs)//of course python lists are exposed with no extra work
		.def_readwrite("animals", &Zoo::animals)//the vector registered to Python right above
		;
}
