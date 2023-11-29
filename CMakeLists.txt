


cmake_minimum_required(VERSION 3.26)
project(P5SFML)

set(CMAKE_CXX_STANDARD 20)

add_executable(P5SFML Src/main.cpp
        Src/game.h
        Src/manual.h
        Src/boy.h
        Src/game.cpp
        Src/boy.cpp
        Src/bomb.h
        Src/bomb.cpp
        Src/box.h
        Src/box.cpp)


target_link_libraries(P5SFML
        sfml-graphics
        sfml-window
        sfml-system
)