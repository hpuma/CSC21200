## Note; This file always accompanies the source files that are being tested.

## The name of the project can be changed to anything.
project(bagDynamic_proj)

## Header files of source code.
set(HEADER_FILES bagDynamic.h)

## Implementation files of source code.
set(SOURCE_FILES bagDynamic.cpp)

## The name of the project goes first.
add_library(bagDynamic_proj ${SOURCE_FILES} ${HEADER_FILES})
