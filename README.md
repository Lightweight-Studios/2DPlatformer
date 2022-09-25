
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
* Only debug builds supported currently

# Contributing
## Style Guide
This is a loose style guide to follow for consistency. It is not the only way to do things.

* Use spaces, not tabs (three spaces for indentation)
* As much as possible limit any lines length to 100 characters
* Define a functions return value, name, and (at minimum) first input on a single line
   * Only template definitions and arguments after the first should be on separate lines
* Use #pragma once at the start of ever header file
* Prefer name-spacing feature set classes to reusing terms across numerous class definitions
* Class names should use camel case with capital letters, EG: MyClass
* Start class names with the letter "I" if they are an interface class with solely pure virtual functions EG: IMyInterfaceClass
* Function names should use underscore separated camel case EG: MyClass::some_func()
* Variable names should use underscores to separate words, EG: my_varx
* If a variable is a static, prefix it with 's ' if it is global 'g ' if it is a class member 'm', optionally if its an input, output, or input and output use 'i', 'o', or 'io' respectively 
   * Follow all letter prefixes with an underscore  EG: i_my_input
* Constants should follow the format of being entirely capitalized and underscore separated EG: MY_CONSTANT