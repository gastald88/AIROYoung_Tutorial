/**
 * @file zoo.h
 * @author Gasta
 * @brief this file contains all the classes used in this tutorial. The scenario is a zoo with 
 * animals of different species.
 * @version 0.1
 * @date 2019-10-12
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#pragma once

#include "globals.h"

//forward declaration
class Zoo;

/**
 * @brief This is a base class for all animals of the zoo
 * 
 */
class Animal
{
public:
	//enum
	enum Environment {Land, Water, Air};
	//variables
	Environment environment;///< environment where the animal mostly live
	int num_paws;///< number of paws of the animal
	//methods
	/**
	 * @brief Get the Name object
	 * 
	 * @return the name
	 */
	string getName() const;
	/**
	 * @brief Set the Name object
	 * 
	 * @param _name the name of the animal
	 */
	void setName(string _name);
	/**
	 * @brief Get the Zoo object
	 * 
	 * @return reference to the zoo
	 */
	Zoo & getZoo();
	/**
	 * @brief Set the Zoo object
	 * 
	 * @param _zoo reference to the zoo
	 */
	void setZoo(Zoo & _zoo);
	/**
	 * @brief method to override for the noise made by the specific 
	 * animal of each derived class
	 * 
	 * @return the noise as string (e.g. "meow", "wof")
	 */
	virtual string makeNoise() const;
	/**
	 * @brief Construct a new Animal object. Thi default constructor is needed by the 
	 * Python exposition of container of Animal (e.g: vector<Animal>)
	 * 
	 */
	Animal() = default;
	/**
	 * @brief Destroy the Animal object
	 * 
	 */
	virtual ~Animal() = default;
	/**
	 * @brief compares two animals. Thi default constructor is needed by the 
	 * Python exposition of container of Animal (e.g: vector<Animal>)
	 * 
	 * @param a another animal
	 * @return true if they have the same name
	 * @return false otherwise
	 */
	bool operator==(const Animal & a) const;
	/**
	 * @brief output stream operator
	 * 
	 * @param os ostream object
	 * @param a animal to output
	 * @return the ostream object with the animal print
	 */
	friend std::ostream & operator<<(std::ostream &os, const Animal & a);
	/**
	 * @brief exposition to Python of this class
	 * 
	 */
	static void python();
protected:
	//variables
	string name;///< name of the animal
	Zoo* zoo;///< zoo where it belongs
};

/**
 * @brief this class extends the Animal class implementing a dog
 * 
 */
class Dog : public Animal
{
public:
	//methods
	using Animal::Animal;
	string makeNoise() const override;
	/**
	 * @brief creates an instance of the dog as a smart pointer
	 * 
	 * @return smart pointer to the new instance
	 */
	static shared_ptr<Animal> create();
	/**
	 * @brief exposition to Python of this class
	 * 
	 */
	static void python();
};

/**
 * @brief this class extends the Animal class implementing a crow
 * 
 */
class Crow : public Animal
{
public:
	//methods
	vector<string> visited_cities;///< cities visited by the crow
	using Animal::Animal;
	string makeNoise() const override;
	/**
	 * @brief creates an instance of the dog as a raw pointer. It allocates
	 * memory that must be managed
	 * 
	 * @return raw pointer to the new instance 
	 */
	static Crow* create();
	/**
	 * @brief exposition to Python of this class
	 * 
	 */
	static void python();
};


/**
 * @brief this is the zoo that contains animals
 * 
 */
class Zoo
{
public:
	string name;///< the name of the zoo. We will expose it in read-only mode
	/**
	 * @brief Construct a new Zoo object
	 * 
	 */
	Zoo();
	/**
	 * @brief Construct a new Zoo object
	 * 
	 * @param _name name of the zoo
	 */
	Zoo(string _name);
	vector<shared_ptr<Animal>> animals;///< container of animals in the zoo
	boost::python::list dogs;///< dogs in the zoo saved as a python list
	/**
	 * @brief exposition to Python of this class
	 * 
	 */
	static void python();
};