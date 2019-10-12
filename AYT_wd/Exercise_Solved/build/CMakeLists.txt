cmake_minimum_required(VERSION 2.8)

project(AYT_exercise)

#general settings
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CONFIGURATION_TYPES Debug Release)

#set output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#find Python

find_package(PythonLibs 2.7.15 EXACT REQUIRED)

IF(PythonLibs_FOUND)
    include_directories(${PYTHON_INCLUDE_DIRS})
ELSE()
    MESSAGE("Python libraries not found")
ENDIF()

#find Boost

#tags of boost libraries
#SET(Boost_USE_STATIC_LIBS OFF)
SET(Boost_NO_SYSTEM_PATHS ON)
#SET(Boost_USE_MULTITHREADED ON)
#SET(Boost_ARCHITECTURE -x64)

#where to find boost components
SET(BOOST_ROOT /home/beatrice/boost_1_69_0/)
SET(BOOST_INCLUDEDIR ${BOOST_ROOT})
SET(BOOST_LIBRARYDIR ${BOOST_ROOT}stage/lib/)


find_package(Boost 1.65 REQUIRED COMPONENTS date_time python27 graph)

IF(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
ELSE()
    MESSAGE("Boost libraries not found")
ENDIF()

#set up source files to compile

set(SOURCE_FILES
	../source/globals.h
    ../source/py_exp.cpp
    ../source/customer.h
    ../source/customer.cpp
    ../source/employee.h
    ../source/employee.cpp
    ../source/recipe.h
    ../source/recipe.cpp
    ../source/restaurant.h
    ../source/restaurant.cpp
    ../source/TSP.h
    ../source/TSP.cpp
    )

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

#Link all libraries to target

target_link_libraries(${PROJECT_NAME}
    ${Boost_LIBRARIES}
    ${PYTHON_LIBRARIES}
    )
