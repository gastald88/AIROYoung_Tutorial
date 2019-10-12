# AIROYoung_Tutorial

In this repository there are easy examples or exercise concerning the main functionalities of [Boost Python](https://www.boost.org/doc/libs/1_71_0/libs/python/doc/html/index.html).

*Boost Python* is a library in the [Boost](https://www.boost.org/) suite which allows a very simple way to interface your C++ code to Python. 
## Structure

The tutorial is structured as follows:
```
    AYT_wd
    ├───Exercise
    │   ├───build
    │   │   └───source
    │   └───python_scripts
    │   ├───data
    ├───Exercise_Solved
    │   ├───build
    │   │   └───source
    │   └───python_scripts
    │   ├───data
    ├───Tutorial
    │   ├───build
    │   │   └───source
    │   └───python_scripts
    └───utils
```
1. In the **Tutorial** folder there is the (Python and C++) source code for a Python package to model an example concerning all the main Boost Python instruction for base and medium user;

2. In the **Exercise** folder there is the the (Python and C++) source code for a Python package to model an exercise with empty implementation (TODO) of methods for the exposition to Python;

3. In the **Exercise_Solved** folder there is the same C++ source code of **Exercise** with the implementation.
4. In the **utils** folder there are some miscellaneous Python functions used by the notebooks

Given any of the previous folder, the inner structure is the same for the three of them:
```
    folder
    ├───build
    │   │ CMakeLists.txt
    │   │ build_all.bat
    │   │ build_all.sh
    │   └─── source
    └───python_scripts
    └───data
```
In the ***build*** folder there is a ***source*** subdirectory containing the C++ files to compile in a Python module through Boost Python. The file *build_all.bat/sh* (depending on the platform) calls the build system configuration file *CMakeLists.txt* and creates the Python package, then it copies it in the parent directory. These files must be customized by the client, in particular one must decide the configuration/build type (Debug or Release) and must set up the Boost root directory. The folder ***python_scripts*** and ***data*** contain respectively additional files written in Python and data loaded for example purpose in the notebooks in the root folder.
Once the package is built and in the ***folder*** directory, one should start the *JuPyter* server. It is very important that *the JuPyter server is launched in the AYT_wd folder*.

## Setup

The tutorial needs to install some Python required packages, so you may prefer to use a Python virtual environment by *virtualenv*. That said, you just need to install what follows:
* Boost C++ Libraries (>= 1.66);
* CMake (>= 3.14);
* Python (== 2.7.15).

Depending on some characteristics of the Boost libraries you may need to change some directives in the CMakeLists.txt, but they are very easy to understand:

    #tags of boost libraries
    SET(Boost_USE_STATIC_LIBS ON) #set to ON if you compiled boost as static libraries
    SET(Boost_NO_SYSTEM_PATHS ON) #do not modify this
    SET(Boost_USE_MULTITHREADED ON) #set to ON if you compiled boost with the multithreaded option
    SET(Boost_ARCHITECTURE -x64) #set to ON if you compiled boost for x64 platform

If you have any troubles finding the Boost libraries, add to the CMakeLists.txt file the command `set(Boost_DEBUG ON)` for a more verbose output.

CMake will automatically find a C++ compiler, but in case of any troubles refer to the [CMake]([https://cmake.org](https://cmake.org/)) documentation.

At this point, you just need the following steps to run the code:
1. [*optional]* make use of a python virtual environment;
2. execute `pip install -r requirements.txt`;
3. choose one package to build and execute the `build_all.bat/sh` file;
4. launch a JuPyter server from the AYT_wd folder ([*optional*] in the same virtual environment as in 1);
5. open the notebook and execute each cell one by one to analyze the output.