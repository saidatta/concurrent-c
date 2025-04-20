# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project definition
project(concurrent_c_examples VERSION 1.0 LANGUAGES C)

# Set C standard to C23
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON) # Require the standard, don't fallback
set(CMAKE_C_EXTENSIONS OFF)       # Disable compiler-specific extensions

# Set common compiler flags (warnings, debug info)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -g")

# Find required packages (pthreads)
find_package(Threads REQUIRED)

# Define executable targets for examples

# Example 1: Basic thread creation
add_executable(01_threads_basic examples/01_threads_basic.c)
# Link the executable against the pthreads library
target_link_libraries(01_threads_basic PRIVATE Threads::Threads)

# Example 2: Threads with arguments and return values
add_executable(02_threads_args_retval examples/02_threads_args_retval.c)
# Link the executable against the pthreads library
target_link_libraries(02_threads_args_retval PRIVATE Threads::Threads)
