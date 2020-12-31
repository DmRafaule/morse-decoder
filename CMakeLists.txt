cmake_minimum_required(VERSION 3.18)
project(morse-decoder)
file(GLOB SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})