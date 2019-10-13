#include "TSP.h"

Network::Network() : Network(0)
{
}

Network::Network(unsigned num_nodes) : graph(num_nodes)
{
}

Restaurant & Network::getitem(Node node)
{
	if (node >= size())
		throw std::runtime_error("index " + std::to_string(node) + " out of range");
	return graph[node];
}
void Network::setitem(Node node, Restaurant & loc)
{
	if (node >= size())
		throw std::runtime_error("index " + std::to_string(node) + " out of range");
	graph[node] = loc;
}
void Network::pushArc(Node from, Node to, Trip trip)
{
	Arc e;
	bool inserted;
	boost::tie(e,inserted) = add_edge(from, to, graph);
	if (!inserted)
		throw std::runtime_error("could not insert arc between " + std::to_string(from) + " to " + std::to_string(to));
	graph[e] = trip;
}
Trip & Network::getArc(Node from, Node to)
{
	std::pair<Arc, bool> arc = edge(from, to, graph);
	if (!arc.second)
		throw std::runtime_error("no arc between " + std::to_string(from) + " to " + std::to_string(to));
	return graph[arc.first];
}
size_t Network::size() const
{
	return num_vertices(graph);
}
Network::iterator Network::begin()
{
	return vertices(graph).first;
}
Network::iterator Network::end()
{
	return vertices(graph).second;
}
void Network::python()
{
	//expose pushArc and getArc methods
	using namespace boost::python;

	class_<Network>("Network")
		.def(init<unsigned>())
		.def("__len__", &Network::size)//C
		.def("__setitem__", &Network::setitem)//C
		.def("__getitem__", make_function(&Network::getitem, return_internal_reference<>()))//C
		.def("__iter__", boost::python::iterator<Network>())//C
		.def("pushArc", &Network::pushArc)
		.def("getArc", make_function(&Network::getArc, return_internal_reference<>()))
		;
}

Trip::Trip() : Trip(0, time_duration())
{
}

Trip::Trip(double _km, time_duration _travel_time) : km(_km), travel_time(_travel_time)
{
}

void Trip::python()
{
	//plain exposition of variables
	using namespace boost::python;
	class_<Trip>("Trip", init<double, time_duration>())
		.def_readwrite("km", &Trip::km)
		.def_readwrite("travel_time", &Trip::travel_time)
		;
}

boost::python::list TSP(Network & network)
{
	using namespace boost;

	boost::python::list l;

	Graph & g = network.graph;
	vector<Node> tour;//solution of TSP
	double len = 0;//length of the tour

	auto vertex_indices = get(vertex_index, g);
	auto w_map = get(&Trip::km, g);//property map of Trip::km that I want to pass to metric_tsp_approx
	auto tour_visitor = make_tsp_tour_len_visitor(g, std::back_inserter(tour), len, w_map);

	//run
	metric_tsp_approx(g, w_map, vertex_indices, tour_visitor);

	for (vector<Node>::iterator itr = tour.begin(); itr != tour.end(); ++itr)
		l.append(*itr);
	
	return l;
}
