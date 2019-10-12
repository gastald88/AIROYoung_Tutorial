cmake -A x64 CMakeLists.txt
::cmake --build . --config Release
::copy bin\Release\AYT_tutorial.dll ..\AYT_tutorial.pyd
cmake --build . --config Debug
copy bin\Debug\AYT_tutorial.dll ..\AYT_tutorial.pyd
pause()