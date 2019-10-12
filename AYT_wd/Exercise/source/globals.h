#pragma once

//some conditional compilation definitions for boost::python

#ifdef _WIN32
#define DLL_EXPORT
#ifdef DLL_EXPORT
#define EXPOSE __declspec(dllexport)
#else
#define EXPOSE __declspec(dllimport)
#endif
#define BOOST_PYTHON_STATIC_LIB
#else
#define BOOST_LOG_DYN_LINK 1 // Boost python explodes otherwise
#define EXPOSE 
#endif

#include <string>
#include <vector>
#include <iostream>

//import boost::python tools
#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

//boost date-time classes
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>

//boost graph library
#include <boost/graph/adjacency_matrix.hpp>
#include <boost/graph/metric_tsp_approx.hpp>
#include <boost/graph/adjacency_list.hpp>

using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::vector;
using boost::posix_time::time_duration;
using boost::posix_time::time_period;
using boost::gregorian::date;
using boost::posix_time::ptime;
using std::shared_ptr;