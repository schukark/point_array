# CMakeList.txt : CMake project for Code, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Code "Calculator.cpp" "Calculator.h" "FirstCppApp.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Code PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
