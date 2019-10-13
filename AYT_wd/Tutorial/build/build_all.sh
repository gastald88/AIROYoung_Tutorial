#!/bin/bash
cmake -DCMAKE_BUILD_TYPE=Release -Dboost_path="C:/Users/Gasta/Documents/Visual Studio 2017/Librerie/boost_1_68_0/" CMakeLists.txt
cmake --build . --target install
cp bin/Release/AYT_tutorial.so ../
#cmake -DCMAKE_BUILD_TYPE=Debug -Dboost_path="C:/Users/Gasta/Documents/Visual Studio 2017/Librerie/boost_1_68_0/" CMakeLists.txt
#cmake --build . --target install
#cp bin/Debug/AYT_tutorial.so ../