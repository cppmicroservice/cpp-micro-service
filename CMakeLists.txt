cmake_minimum_required(VERSION 3.12)
project(MMM)

# Set C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Specify the directory containing nlohmann JSON library
set(JSON_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/lib/json-develop/single_include)

# Find nlohmann JSON library header file
find_path(JSON_INCLUDE NAMES "nlohmann/json.hpp" PATHS ${JSON_INCLUDE_DIR})

# Include directory containing nlohmann JSON library header file
include_directories(${JSON_INCLUDE})

include_directories(include)

# Add your source files
set(SOURCES
    src/main.cpp
    src/Customer.cpp
    src/Item.cpp
    src/MongoDBIntegration.cpp
    src/BillingSystem.cpp
    # Add source files
)

# Define the executable
add_executable(MMM ${SOURCES})

