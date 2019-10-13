#pragma once

#include "globals.h"

//implement the Recipe class
class Recipe
{
public:
	//enumerative types
	enum CookingType {Oven, Pan, Pot};
	enum Conservation { Anywhere, Fridge, Refrigerator };
	//variables
	string name;
	CookingType cooking;
	Conservation conservation;
	time_duration cooking_duration;
	double butter_g;
	double milk_ml;
	double flour_g;
	double chocolate_g;
	int eggs;
	//methods
	Recipe();//for vector suite
	Recipe(string _name);
	bool operator==(const Recipe & r) const;//for vector suite
	friend std::ostream & operator<<(std::ostream &os, const Recipe & r);
	bool cooksSlowerThan(Recipe & r) const;
	static int numCommonIngredients(Recipe & r1, Recipe & r2);
	static void python();
};