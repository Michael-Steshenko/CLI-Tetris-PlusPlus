cmake_minimum_required(VERSION 3.10)

project(CLI_Tetris++ VERSION 1.0)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# for debugging
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXXFLAGS}")

# Find all .cpp files in src dir
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")
add_executable(tetris.out ${SOURCES})

target_include_directories(tetris.out PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/src"
)