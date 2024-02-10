cmake_minimum_required(VERSION 3.0)
project(ball)

find_package(raylib CONFIG REQUIRED)

file(GLOB SOURCES "*.cc")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(COPY "./res" DESTINATION ".")

add_executable(ball ${SOURCES})
target_link_libraries(ball PRIVATE raylib)