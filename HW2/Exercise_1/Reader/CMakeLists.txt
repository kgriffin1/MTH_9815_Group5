cmake_minimum_required(VERSION 3.28.0)

project(Reader)

# Set the Boost root directory
set(BOOST_ROOT "/mnt/c/local/boost_1_82_0")
set(Boost_NO_SYSTEM_PATHS ON)

# Find Boost
find_package(Boost 1.82.0 REQUIRED)

# If Boost is found, include the directories
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(${PROJECT_NAME} main.cpp)
endif()
