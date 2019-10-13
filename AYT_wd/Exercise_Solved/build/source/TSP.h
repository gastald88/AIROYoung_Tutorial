/**
 * @file TSP.h
 * @author your name (you@domain.com)
 * @brief this file contains the Network and Trip class to model a Graph on which we solve a 
 * Traveling Salesman Problem
 * @version 0.1
 * @date 2019-10-13
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#pragma once

#include "restaurant.h"

/**
 * @brief a trip represents a set of property related to each arc of the graph  (km, travel_time)
 * 
 */
struct Trip
{
	//variables
	double km;///< space distance in kilometers
	time_duration travel_time;///< time distance
	//methods
	/**
	 * @brief Construct a new Trip object
	 * 
	 */
	Trip();
	/**
	 * @brief Construct a new Trip object
	 * 
	 * @param _km space distance
	 * @param _travel_time time distance
	 */
	Trip(double _km, time_duration _travel_time);
	/**
	 * @brief exposition to Python of this class
	 * 
	 */
	static void python();
};

/*
* a Graph is defined by an adjacency matrix with Trip property related to each arc
* and Restaurant property related to each node
*/ 
typedef boost::adjacency_matrix<boost::directedS, Restaurant, Trip> Graph;
typedef typename Graph::vertex_descriptor Node;
typedef typename Graph::edge_descriptor Arc;

/**
 * @brief the class Network is a wrapper class of Graph to expose it to python.
 * methods with 'C' on comments represents method needed for python to
 * handle such class with python container interface (as list). This is 
 * what the vector_indexing_suite makes behind the scenes
 */
class Network
{
public:
	//variables
	typedef Graph::vertex_iterator iterator;
	Graph graph;
	//methods
	/**
	 * @brief Construct a new Network object
	 * 
	 */
	Network();
	/**
	 * @brief Construct a new Network object
	 * 
	 * @param num_nodes number of nodes of the graph
	 */
	Network(unsigned num_nodes);
	/**
	 * @brief insert an arc in the graph
	 * 
	 * @param from origin node
	 * @param to destination node
	 * @param trip trip data structure assigned to this arc
	 */
	void pushArc(Node from, Node to, Trip trip);
	/**
	 * @brief Get the Arc object
	 * 
	 * @param from origin node
	 * @param to destination node
	 * @return the trip related to the arc with this origin and destination nodes
	 */
	Trip & getArc(Node from, Node to);
	/**
	 * @brief method for the Python access operator (r = N[node])
	 * 
	 * @param node node passed to the access operator
	 * @return reference to the restaurant at that node
	 */
	Restaurant & getitem(Node node);//C
	/**
	 * @brief method for the Python assignment operator (N[node] = r)
	 * 
	 * @param node node passed to the assignment operator
	 * @param r restaurant to assign
	 */
	void setitem(Node node, Restaurant & r);//C
	/**
	 * @brief method for the Python *len()* operator
	 * 
	 * @return the number of nodes in the network
	 */
	size_t size() const;//C
	/**
	 * @brief begin iterator to expose to Python
	 * 
	 * @return iterator to the first element
	 */
	iterator begin();//C
	/**
	 * @brief begin iterator to expose to Python
	 * 
	 * @return iterator to the last element + 1
	 */
	iterator end();//C
	//PYTHON
	/**
	 * @brief exposition to Python of this class
	 * 
	 */
	static void python();
};

/**
 * @brief this function solves the TSP problem on a Network instance.
 * 
 * @param network the network where the TSP has to be solved
 * @return the solution to the TSP on the network
 */
boost::python::list TSP(Network & network);