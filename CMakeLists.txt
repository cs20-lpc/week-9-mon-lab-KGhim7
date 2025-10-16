cmake_minimum_required(VERSION 3.20)
project(week_9_mon_lab_KGhim7 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(week_9_mon_lab_KGhim7
        main.cpp
        LinkedQueue.hpp
        LinkedQueue.tpp
        Queue.hpp
)

target_include_directories(week_9_mon_lab_KGhim7 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
