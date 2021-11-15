cmake_minimum_required(VERSION 3.20)
project(task2)

Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.0.0-preview3
)

FetchContent_MakeAvailable(Catch2)

add_executable(task2 main.cpp hashtable.cpp hashtable.h)

target_link_libraries(task2 PRIVATE Catch2::Catch2WithMain)

set(CMAKE_CXX_STANDARD 23)