## This file is always in the main directory along side the test folder and the 
## main.cpp file

## Specify mininum version of CMAKE
cmake_minimum_required(VERSION 2.8)

## Project's Name
project(bagDynamic_proj)


## Check for Windows ##
if (WIN32) # true if windows (32 and 64 bit)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif ()


## For your own tests that you write in main.cpp
set(SOURCE_FILES main.cpp)

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)

add_executable(main_executable.o ${SOURCE_FILES})

target_link_libraries(main_executable.o bagDynamic_proj)
