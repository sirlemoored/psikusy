# Setting minimum required CMake version
cmake_minimum_required(VERSION 3.14)

# Project name
project(tl)

# Setting global C standard (can also set it target-wise)
set (CMAKE_C_STANDARD 11)

# Compiler flags depending on the compiler used
if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Listing all source files belonging to this project
set(FILES_SOURCE
    src/main.c
    src/anagram.c
    src/palindrome.c
    )

# Setting executable name depending on build mode
if(CMAKE_BUILD_TYPE STREQUAL "Debug" OR CMAKE_BUILD_TYPE STREQUAL "")
    set (EXEC_NAME ${PROJECT_NAME}_dbg)
else()
    set (EXEC_NAME ${PROJECT_NAME})
endif()

# Adding executable target
add_executable(${EXEC_NAME} ${FILES_SOURCE})

# Including directories for main target
target_include_directories(${EXEC_NAME} PUBLIC include)