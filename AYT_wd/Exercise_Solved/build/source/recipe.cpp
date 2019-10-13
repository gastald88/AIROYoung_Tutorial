#include "recipe.h"

Recipe::Recipe() : Recipe("")
{
}

Recipe::Recipe(string _name) : butter_g(0), milk_ml(0), flour_g(0), chocolate_g(0), eggs(0), name(_name), conservation(Anywhere), cooking(Pot), cooking_duration()
{
}

bool Recipe::operator==(const Recipe & r) const
{
	return this->name == r.name;
}

bool Recipe::cooksSlowerThan(Recipe & r) const
{
	return this->cooking_duration < r.cooking_duration;
}

int Recipe::numCommonIngredients(Recipe & r1, Recipe & r2)
{
	int i = 0;

	if (r1.butter_g > 0 && r2.butter_g > 0)
		i++;
	if (r1.milk_ml > 0 && r2.milk_ml > 0)
		i++;
	if (r1.flour_g > 0 && r2.flour_g > 0)
		i++;
	if (r1.chocolate_g > 0 && r2.chocolate_g > 0)
		i++;
	if (r1.eggs > 0 && r2.eggs > 0)
		i++;

	return i;
}

void Recipe::python()
{
	//expose enumerative types
	//expose operator<<
	//watch static methods
	
	using namespace boost::python;

	enum_<CookingType>("CookingType")
		.value("Oven", CookingType::Oven)
		.value("Pan", CookingType::Pan)
		.value("Pot", CookingType::Pot)
		;

	enum_<Conservation>("Conservation")
		.value("Anywhere", Conservation::Anywhere)
		.value("Fridge", Conservation::Fridge)
		.value("Refrigerator", Conservation::Refrigerator)
		;

	class_<Recipe>("Recipe", init<string>())
		.def(self_ns::str(self_ns::self))
		.def_readwrite("name", &Recipe::name)
		.def_readwrite("conservation", &Recipe::conservation)
		.def_readwrite("cooking_duration", &Recipe::cooking_duration)
		.def_readwrite("cooking", &Recipe::cooking)
		.def_readwrite("butter_g", &Recipe::butter_g)
		.def_readwrite("milk_ml", &Recipe::milk_ml)
		.def_readwrite("flour_g", &Recipe::flour_g)
		.def_readwrite("chocolate_g", &Recipe::chocolate_g)
		.def_readwrite("eggs", &Recipe::eggs)
		.def("cooksSlowerThan", &Recipe::cooksSlowerThan)
		.def("numCommonIngredients", &Recipe::numCommonIngredients)
		.staticmethod("numCommonIngredients")
		;
}

ostream & operator<<(ostream & out, const Recipe & r)
{
	out << r.name;
	return out;
}
