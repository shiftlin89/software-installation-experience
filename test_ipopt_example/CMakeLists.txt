cmake_minimum_required(VERSION 3.0)
project(IpoptExample)


set (CMAKE_CXX_STANDARD 11)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

SET(CMAKE_BUILD_TYPE "Debug")  #Release  Debug
#SET(CMAKE_BUILD_TYPE "Release")  #Release  Debug

SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
# Find IPOPT packag

include_directories("/home/lin/Documents/IPOPT_installation/coin-or/")               #IPOPT Header

link_directories("/usr/lib64")
link_directories("/home/lin/Documents/IPOPT_installation/lib/")                                #IPOPT library

# Add executable
add_executable(a 
           main.cpp
           hs071_nlp.cpp )

# Link IPOPT libraries
 target_link_libraries(a                                                #IPOPT
 ipopt
 coinhsl
 ) 

