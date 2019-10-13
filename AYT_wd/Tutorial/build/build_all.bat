cmake -A x64 -Dboost_path="C:/Users/Gasta/Documents/Visual Studio 2017/Librerie/boost_1_68_0/" CMakeLists.txt
::cmake --build . --config Release
::copy bin\Release\AYT_tutorial.dll ..\AYT_tutorial.pyd
cmake --build . --config Debug --target install
copy bin\Debug\AYT_tutorial.dll ..\AYT_tutorial.pyd
pause()