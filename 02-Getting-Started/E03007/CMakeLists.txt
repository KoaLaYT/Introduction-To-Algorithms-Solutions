add_library("E03007" solution.cpp)

add_executable("E03007_Test" solution_test.cpp)
target_link_libraries("E03007_Test" PRIVATE "E03007" GTest::gtest GTest::gtest_main)