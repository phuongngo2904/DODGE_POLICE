cmake_minimum_required(VERSION 3.15)
project(DODGE_POLICE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_executable(DODGE_POLICE main.cpp Game/Game.h Game/Game.cpp Game/PauseGame.h Game/PauseGame.cpp
            Game/Welcome_Screen.h Game/Welcome_Screen.cpp
            Enemy_cars/Object.h Enemy_cars/Enemy.h Enemy_cars/Enemy.cpp 
            Player_car/MyCar.h Player_car/MyCar.cpp Player_car/CarInfo.h constants.h)

include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(DODGE_POLICE sfml-system sfml-window sfml-graphics sfml-audio sfml-network)