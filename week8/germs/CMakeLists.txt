# Created by the script cgal_create_cmake_script
# This is the CMake script for compiling a CGAL application.


project( germs_ )

cmake_minimum_required(VERSION 2.8.10)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
find_package(CGAL QUIET COMPONENTS Core )

if ( CGAL_FOUND )

  include( ${CGAL_USE_FILE} )

  include( CGAL_CreateSingleSourceCGALProgram )

  create_single_source_cgal_program( "germsv2.cpp" )
    create_single_source_cgal_program( "germsv5.cpp" )

else()
  
    message(STATUS "This program requires the CGAL library, and will not be compiled.")
  
endif()

