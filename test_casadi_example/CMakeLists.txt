cmake_minimum_required(VERSION 3.5)
project(CasadiOptimizationExample)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

SET(CMAKE_BUILD_TYPE "Debug")  #Release  Debug
#SET(CMAKE_BUILD_TYPE "Release")  #Release  Debug

# Find CasADi
# find_package(Casadi REQUIRED)

#include the header
include_directories("/usr/local/include/casadi/")  
#include_directories("/home/bsi/Workspace/ThirdPart/ipopt/include/coin")               #IPOPT Header
#include_directories("/home/bsi/Workspace/ThirdPart/ipopt/include")                    #IPOPT Header 

#link_directories("/home/bsi/Workspace/GOIII_C/ThirdPart/ipopt/lib")                                #IPOPT library
link_directories("/usr/local/lib/")                                #IPOPT library

# Add executable
add_executable(optimization_example  main.cpp)

# Link libraries
# target_link_libraries(optimization_example casadi)


#include the library

set(IPOPT_LIBs                                                 #IPOPT
coinblas
ipopt
) 

set (Casadi_LIBs
   # FortranHighs
   casadi
   casadi_nlpsol_ipopt
)




target_link_libraries (optimization_example   ${Casadi_LIBs}) 
# target_link_libraries (optimization_example   ${IPOPT_LIBs}) 

# If Ipopt is not found automatically, you might need to specify its path.
# For example:
# find_library(IPOPT_LIBRARY ipopt PATHS /path/to/ipopt/lib NO_DEFAULT_PATH)
# target_link_libraries(optimization_example ${IPOPT_LIBRARY})

