cmake_minimum_required(VERSION 3.23)
project(P2___Graphics)

set(CMAKE_CXX_STANDARD 14)

set(SDL2_LIB_DIR D:/Clase/3/IA/P2-Graphics/SDL/SDL2-2.24.2/lib/x86)
set(SDL2_INCLUDE_DIR D:/Clase/3/IA/P2-Graphics/SDL/SDL2-2.24.2/include)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})


add_executable(P2___Graphics main.cpp src/sdl_functions_own.cc)

target_link_libraries(${PROJECT_NAME} SDL2main SDL2)
