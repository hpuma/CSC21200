add_subdirectory(lib/gtest-1.7.0)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


add_executable(runTests.o test.cpp)

target_link_libraries(runTests.o gtest gtest_main)
target_link_libraries(runTests.o bagDynamic_proj)
