cmake_minimum_required(VERSION 3.23)
project(P2___Graphics)

set(CMAKE_CXX_STANDARD 14)



set(SDL2_DIR ${PROJECT_SOURCE_DIR}/SDL/SDL2-2.24.2/cmake)
set(SDL2_TTF_DIR ${PROJECT_SOURCE_DIR}/SDL/SDL2_ttf-2.20.1/cmake)


find_package(SDL2 REQUIRED)
find_package(SDL2_TTF REQUIRED)


add_executable(P2___Graphics main.cpp src/celda.cc src/empty.cc src/end.cc src/estado.cc src/obstacle.cc src/path.cc src/player.cc src/world.cc src/Visitado_State.cc src/main_render_functions.cc)

target_include_directories(P2___Graphics PUBLIC ${PROJECT_SOURCE_DIR}/SDL/SDL2-2.24.2/include)
target_include_directories(P2___Graphics PUBLIC ${PROJECT_SOURCE_DIR}/SDL/SDL2_ttf-2.20.1/include)

target_link_libraries(P2___Graphics SDL2::SDL2 SDL2::SDL2main SDL2_TTF)

target_link_directories(P2___Graphics PUBLIC $${PROJECT_SOURCE_DIR}/SDL/SDL2-2.24.2/lib/x86)

target_link_directories(P2___Graphics PUBLIC $${PROJECT_SOURCE_DIR}/SDL/SDL2_ttf-2.20.1/lib/x64)



