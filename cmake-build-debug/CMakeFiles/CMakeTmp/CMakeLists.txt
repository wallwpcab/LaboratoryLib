cmake_minimum_required(VERSION 3.20.2.0)
project(CMAKE_TRY_COMPILE CXX)
set(CMAKE_VERBOSE_MAKEFILE 1)
set(CMAKE_CXX_FLAGS "")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_DEFINITIONS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${EXE_LINKER_FLAGS}")
include_directories(${INCLUDE_DIRECTORIES})
set(CMAKE_SUPPRESS_REGENERATION 1)
link_directories(${LINK_DIRECTORIES})
cmake_policy(SET CMP0065 OLD)
cmake_policy(SET CMP0083 OLD)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "E:/LaboratoryLib/cmake-build-debug/CMakeFiles/CMakeTmp")
add_executable(cmTC_957e2 "E:/LaboratoryLib/cmake-build-debug/CMakeFiles/CMakeTmp/testCXXCompiler.cxx")
target_link_libraries(cmTC_957e2 ${LINK_LIBRARIES})
