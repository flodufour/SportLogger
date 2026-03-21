cmake_minimum_required(VERSION 3.10)
project(SportLogger)

file(GLOB SOURCES "src/*.cpp")

add_executable(SportLogger ${SOURCES})
