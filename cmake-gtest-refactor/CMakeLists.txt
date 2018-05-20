cmake_minimum_required(VERSION 3.1)
project(refactoring)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_library(libcompany
    src/PersonData.hpp
    src/PersonData.cpp
    src/Employee.hpp
    src/Employee.cpp
    src/Database.hpp
    src/Database.cpp
    src/Contact.hpp
    src/Contact.cpp
    src/Report.hpp
    src/Report.cpp
    src/work.hpp
    src/work.cpp)

target_include_directories(libcompany PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)


add_executable(main src/main.cpp)
target_link_libraries(main libcompany)

add_subdirectory(lib/gtest)
add_subdirectory(test)

