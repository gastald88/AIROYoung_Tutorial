/**
 * @file globals.h
 * @author Gasta
 * @brief inclusion of some boost and std classes
 * @version 0.1
 * @date 2019-10-12
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#pragma once

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