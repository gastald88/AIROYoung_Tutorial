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

	if (r1.butter_g > 0 and r2.butter_g > 0)
		i++;
	if (r1.milk_ml > 0 and r2.milk_ml > 0)
		i++;
	if (r1.flour_g > 0 and r2.flour_g > 0)
		i++;
	if (r1.chocolate_g > 0 and r2.chocolate_g > 0)
		i++;
	if (r1.eggs > 0 and r2.eggs > 0)
		i++;

	return i;
}

void Recipe::python()
{
	//expose enumerative types
	//expose operator<<
	//watch static methods
	
	using namespace boost::python;
	
}

ostream & operator<<(ostream & out, const Recipe & r)
{
	out << r.name;
	return out;
}
