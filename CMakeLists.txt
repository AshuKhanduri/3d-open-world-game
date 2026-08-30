cmake_minimum_required(VERSION 3.15)
project(OpenWorldGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set policy for FetchContent
if(POLICY CMP0135)
    cmake_policy(SET CMP0135 NEW)
endif()

# Find Raylib
find_package(raylib QUIET)

if (NOT raylib_FOUND)
    message(STATUS "Raylib not found. Building from source...")
    include(FetchContent)
    FetchContent_Declare(raylib
        URL https://github.com/raysan5/raylib/archive/refs/tags/4.5.0.tar.gz
        DOWNLOAD_EXTRACT_TIMESTAMP ON
    )
    FetchContent_MakeAvailable(raylib)
endif()

# Source files
set(SOURCES
    src/main.cpp
    src/player.cpp
    src/npc.cpp
    src/world.cpp
    src/interaction.cpp
)

set(HEADERS
    src/player.h
    src/npc.h
    src/world.h
    src/interaction.h
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Link Raylib
target_link_libraries(${PROJECT_NAME} raylib)

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
