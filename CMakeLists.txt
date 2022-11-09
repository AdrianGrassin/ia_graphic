cmake_minimum_required(VERSION 3.23)
project(ia_graphic)

set(CMAKE_CXX_STANDARD 14)

add_executable(ia_graphic src/main.cpp src/world.cc src/celda.cc src/obstacle.cc src/player.cc src/path.cc src/empty.cc src/end.cc)
