#!/bin/bash
cmake -DCMAKE_BUILD_TYPE=Release -Dboost_path="" CMakeLists.txt
cmake --build . --target install
cp lib/libAYT_tutorial.so ../AYT_tutorial.so
