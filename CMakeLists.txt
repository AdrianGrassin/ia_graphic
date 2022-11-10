cmake_minimum_required(VERSION 3.23)
project(P2___Graphics)

set(CMAKE_CXX_STANDARD 14)



set(SDL2_DIR ${PROJECT_SOURCE_DIR}/SDL/SDL2-2.24.2/cmake)
find_package(SDL2 REQUIRED)


add_executable(P2___Graphics main.cpp src/celda.cc src/empty.cc src/end.cc src/estado.cc src/obstacle.cc src/path.cc src/player.cc src/world.cc src/Visitado_State.cc)

target_link_libraries(P2___Graphics SDL2::SDL2 SDL2::SDL2main)


target_include_directories(P2___Graphics PUBLIC ${PROJECT_SOURCE_DIR}/SDL/SDL2-2.24.2/include)
target_link_directories(P2___Graphics PUBLIC $${PROJECT_SOURCE_DIR}/SDL/SDL2-2.24.2/lib/x86)

target_link_libraries(P2___Graphics SDL2::SDL2main SDL2::SDL2)
