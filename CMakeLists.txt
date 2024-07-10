cmake_minimum_required(VERSION 3.10)

project(MyUnitTestProject)

# Add your executable
add_executable(test_example test_example.c)
add_executable(test_file test_file.c file.c)

# Include directories for the target
target_include_directories(test_example PRIVATE "C:/Program Files (x86)/cmocka/include")
target_include_directories(test_file PRIVATE "C:/Program Files (x86)/cmocka/include")

# Locate cmocka
find_package(cmocka REQUIRED)

# Link against cmocka
target_link_libraries(test_example PRIVATE "C:/Program Files (x86)/cmocka/lib/cmocka.lib")
target_link_libraries(test_file PRIVATE "C:/Program Files (x86)/cmocka/lib/cmocka.lib")

# Enable testing
enable_testing()

# Register the test
add_test(NAME test_example COMMAND test_example)
add_test(NAME test_example2 COMMAND test_file)
