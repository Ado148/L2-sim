cmake_minimum_required(VERSION 3.16.0)

project(L2_sim)

set(EXEC main)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -pedantic")

file(GLOB HEADERS "${CMAKE_SOURCE_DIR}/includes/*.hpp")
file(GLOB SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_executable(${EXEC} ${SOURCES})

find_package(Threads REQUIRED)
target_link_libraries(main PRIVATE Threads::Threads)

# set install dir
set(CMAKE_INSTALL_PREFIX "$ENV{HOME}/L2_sim") 

# install the binary to /L2_sim/bin
install(TARGETS ${EXEC} RUNTIME DESTINATION bin)

# install the headers to /L2_sim/include
install(FILES ${HEADERS} DESTINATION includes)

install(FILES "${CMAKE_SOURCE_DIR}/scripts/parser.sh"  
              "${CMAKE_SOURCE_DIR}/scripts/flat_drawer.py"
        DESTINATION scripts
        PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ)