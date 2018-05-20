cmake_minimum_required(VERSION 3.1)
project(gtest_example)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_library(libstuff
    src/example.cpp)

target_include_directories(libstuff PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)


add_executable(main src/main.cpp)
target_link_libraries(main libstuff)


add_executable(io_cstdio src/io/cstdio.cpp)
add_executable(io_iostream src/io/iostream.cpp)
add_executable(io_manips src/io/manips.cpp)
add_executable(io_exceptions src/io/exceptions.cpp)

add_executable(exceptions src/exceptions.cpp)
add_executable(guarantees src/guarantees.cpp)
add_executable(templates src/templates.cpp)
add_executable(resources src/resources.cpp)
add_executable(iters src/iters.cpp)
add_executable(algos src/algos.cpp)

#add_subdirectory(lib/gtest)
#add_subdirectory(test)

