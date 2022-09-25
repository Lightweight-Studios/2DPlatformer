
# Building
## Dependencies
* C++20
* CMake 3.23+
* SDL2

## Instructions
1. Create build directory 'build' at same level as src, doc, tests AKA {PROJECT_PATH}
2. cd {PROJECT_PATH}/build
3. cmake ..
4. cmake --build ./

## Known Issues
* The first attempt to cmake --build will fail, rerun the build to correct the issue
* The SDL2.dll must be manually copied to be colocated with the 2DPlatformer.exe file to run