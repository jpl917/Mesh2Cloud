cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(CONVERTER)

set(CMAKE_BUILD_TYPE "Release")
# Check C++11 or C++0x support
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
#CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
   add_definitions(-DCOMPILEDWITHC11)
   message(STATUS "Using flag -std=c++11.")
elseif(COMPILER_SUPPORTS_CXX0X)
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
   add_definitions(-DCOMPILEDWITHC0X)
   message(STATUS "Using flag -std=c++0x.")
else()
   message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()


find_package(CGAL QUIET COMPONENTS Core )
include( ${CGAL_USE_FILE} )
include( CGAL_CreateSingleSourceCGALProgram )
include_directories("/usr/include/eigen3")


add_library(${PROJECT_NAME} SHARED  Mesh2Cloud.cpp)

add_executable(convert main.cpp)
target_link_libraries(convert ${PROJECT_NAME})
