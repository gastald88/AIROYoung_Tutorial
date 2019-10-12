cmake_minimum_required(VERSION 3.4)

project(AYT_tutorial)

#general settings
set(CMAKE_CONFIGURATION_TYPES Debug Release)

#set output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#find Python

find_package(PythonLibs 2.7.15 EXACT REQUIRED)

#find Boost

#tags of boost libraries
SET(Boost_USE_STATIC_LIBS ON)
SET(Boost_NO_SYSTEM_PATHS ON)
SET(Boost_USE_MULTITHREADED ON)
SET(Boost_ARCHITECTURE -x64)

#where to find boost components

#set(Boost_DEBUG ON)

if(boost_path)
	MESSAGE("setting custom boost root:")
	MESSAGE(${boost_path})
	SET(BOOST_ROOT ${boost_path})
	SET(BOOST_INCLUDEDIR ${BOOST_ROOT})
	SET(BOOST_LIBRARYDIR ${BOOST_ROOT}stage/lib/)
endif()

find_package(Boost 1.65 REQUIRED COMPONENTS date_time python27 graph)

IF(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
ELSE()
    MESSAGE("Boost libraries not found")
ENDIF()

#set up source files to compile

set(SOURCE_FILES
	source/globals.h
    source/py_exp.cpp
    source/zoo.h
    source/zoo.cpp
    )

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

#properties
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 14)
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")

#some boost things to be careful
if(${Boost_USE_STATIC_LIBS})
target_compile_definitions(${PROJECT_NAME}
	PRIVATE
		BOOST_PYTHON_STATIC_LIB
	)
else()#only when using boost::log
target_compile_definitions(${PROJECT_NAME}
	PRIVATE
		BOOST_LOG_DYN_LINK
	)
endif()

#include directories
target_include_directories(${PROJECT_NAME}
	PRIVATE
		${Boost_INCLUDE_DIRS}
		${PYTHON_INCLUDE_DIRS}
	)

#link libraries
target_link_libraries(${PROJECT_NAME}
	PRIVATE
	    ${Boost_LIBRARIES}
	    ${PYTHON_LIBRARIES}
    )

install(TARGETS ${PROJECT_NAME}
    CONFIGURATIONS Debug
    RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/Debug/bin
    LIBRARY DESTINATION ${CMAKE_SOURCE_DIR}/Debug/lib
    ARCHIVE DESTINATION ${CMAKE_SOURCE_DIR}/Debug/lib/static
    )

install(TARGETS ${PROJECT_NAME}
    CONFIGURATIONS Release
    RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/Release/bin
    LIBRARY DESTINATION ${CMAKE_SOURCE_DIR}/Release/lib
    ARCHIVE DESTINATION ${CMAKE_SOURCE_DIR}/Release/lib/static
    )