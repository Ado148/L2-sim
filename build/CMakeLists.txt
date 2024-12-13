cmake_minimum_required(VERSION 3.16.0)

project(L2_sim)

set(EXEC main)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -pedantic")


file(GLOB SOURCES "../src/*.cpp")

add_executable(${EXEC} ${SOURCES})

find_package(Threads REQUIRED)

target_link_libraries(main PRIVATE Threads::Threads)


