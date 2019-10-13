#pragma once

#include "restaurant.h"

//a trip represents a set of property related to each arc of the graph  (km, travel_time)
struct Trip
{
	//variables
	double km;
	time_duration travel_time;
	//methods
	Trip();
	Trip(double _km, time_duration _travel_time);
	static void python();
};

/*
* a Graph is defined by an adjacency matrix with Trip property related to each arc
* and Restaurant property related to each node
*/ 
typedef boost::adjacency_matrix<boost::directedS, Restaurant, Trip> Graph;
typedef typename Graph::vertex_descriptor Node;
typedef typename Graph::edge_descriptor Arc;

/*
* the class Network is a wrapper class of Graph to expose it to python.
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
	Network();
	Network(unsigned num_nodes);
	void pushArc(Node from, Node to, Trip trip);
	Trip & getArc(Node from, Node to);
	Restaurant & getitem(Node node);//C
	void setitem(Node node, Restaurant & r);//C
	size_t size() const;//C
	iterator begin();//C
	iterator end();//C
	//PYTHON
	static void python();
};

//implement here the function to solve the TSP problem
//takes a network as argument, returns a python list
boost::python::list TSP(Network & network);