add_library("E03002" solution.cpp)

add_executable("E03002_Test" solution_test.cpp)
target_link_libraries("E03002_Test" PRIVATE "E03002" GTest::gtest GTest::gtest_main)