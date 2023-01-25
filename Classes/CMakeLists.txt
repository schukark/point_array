# CMakeList.txt : CMake project for Code, include source and define
# project specific logic here.
#

# Add source to this project's executable.
# add_executable (Classes "classes.cpp")

project("Classes")


single_executable(src/arrays.cpp)
single_executable(src/classes.cpp)
single_executable(src/inheritance.cpp)
single_executable(src/operators.cpp)
single_executable(src/struct.cpp)
single_executable(src/enum.cpp)
single_executable(src/rule_of_five.cpp)

#add_subdirectory(src)

# TODO: Add tests and install targets if needed.
