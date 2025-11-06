cmake_minimum_required(VERSION 3.10)
project(FiguresProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable testing
enable_testing()

# Include directories
include_directories(include)

# Main executable
add_executable(main
    src/main.cpp
    src/Figure.cpp
    src/FigureArray.cpp
    src/PointArray.cpp
    src/Triangle.cpp
    src/Square.cpp
    src/Rectangle.cpp
)

# Test executable
add_executable(tests
    tests/main_test.cpp
    tests/test_figure.cpp
    src/Figure.cpp
    src/FigureArray.cpp
    src/PointArray.cpp
    src/Triangle.cpp
    src/Square.cpp
    src/Rectangle.cpp
)

# Find and link GoogleTest
find_package(GTest REQUIRED)
target_link_libraries(tests GTest::GTest GTest::Main)

# Add test
add_test(NAME FiguresTests COMMAND tests)