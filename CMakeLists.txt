cmake_minimum_required(VERSION 3.0)
project(evosim)

set(CMAKE_CXX_STANDARD 23)

add_executable(evosim src/main.cpp src/world.cpp src/world.h src/creature.h src/creature.cpp)

include(FindPkgConfig)

pkg_search_module(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIRS})
target_link_libraries(evosim ${SDL2_LIBRARIES} ${SDL2TTF_LIBRARIES})
