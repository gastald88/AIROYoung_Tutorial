/**
 * @file recipe.h
 * @author Gasta
 * @brief this files contains the recipe class
 * @version 0.1
 * @date 2019-10-13
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#pragma once

#include "globals.h"

/**
 * @brief this class is a recipe for cooking. It contains some main characteristic of dishes, like where to keep it,
 * how to cook it, etc.
 * 
 */
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
	double butter_g;///< grams of butter
	double milk_ml;///< milliliters of milk
	double flour_g;///< grams of flour
	double chocolate_g;///< grams of chocolate
	int eggs;///< number of eggs
	//methods
	/**
	 * @brief Construct a new Recipe object. This method is needed by the 
	 * Python exposition of container of Recipe (e.g: vector<Recipe>)
	 * 
	 */
	Recipe();
	/**
	 * @brief Construct a new Recipe object
	 * 
	 * @param _name name of the recipe
	 */
	Recipe(string _name);
	/**
	 * @brief compares two recipes. This method is needed by the 
	 * Python exposition of container of Recipe (e.g: vector<Recipe>)
	 * 
	 * @param r the other recipe
	 * @return true if they have the same name
	 * @return false otherwise
	 */
	bool operator==(const Recipe & r) const;
	/**
	 * @brief output stream operator
	 * 
	 * @param os the output stream
	 * @param r the recipe to output
	 * @return the output stream with the recipe
	 */
	friend std::ostream & operator<<(std::ostream &os, const Recipe & r);
	/**
	 * @brief this method compares the duration of cooking of two recipes
	 * 
	 * @param r the second recipe
	 * @return true if this recipe cooks slower than the second recipe
	 * @return false otherwise
	 */
	bool cooksSlowerThan(Recipe & r) const;
	/**
	 * @brief this method count the number of common ingredients between two recipes
	 * 
	 * @param r1 the first recipe
	 * @param r2 the second recipe
	 * @return the number of ingredients
	 */
	static int numCommonIngredients(Recipe & r1, Recipe & r2);
	/**
	 * @brief exposition to Python of this class
	 * 
	 */
	static void python();
};