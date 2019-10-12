#!/bin/bash
cmake -DCMAKE_BUILD_TYPE=Release CMakeLists.txt
cmake --build .
cp lib/libAYT_exercise.so ../AYT_exercise.so
