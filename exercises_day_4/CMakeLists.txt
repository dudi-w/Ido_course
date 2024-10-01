cmake_minimum_required(VERSION 3.10)

# Project Name
project(ConnectFour)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add all the source files
set(SOURCES
    main.cpp
    connect4management.cpp
    gridPlay.cpp
    humanPlayer.cpp
    randomComputerPlayer.cpp
)

# Add headers (optional, not strictly necessary but good for IDEs)
set(HEADERS
    connect4management.hpp
    gridPlay.hpp
    humanPlayer.hpp
    randomComputerPlayer.hpp
    IFplayer.hpp
)

# Create an executable
add_executable(connect_four_play ${SOURCES} ${HEADERS})

# If you need to link any external libraries, add them here
# For example: target_link_libraries(connect_four_play <library_name>)
