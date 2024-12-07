cmake_minimum_required(VERSION 3.30)
project(cli_game)

set(CMAKE_CXX_STANDARD 20)

add_executable(cli_game main.cpp
        Classes/Player/Player.cpp
        Classes/AbstractClasses/GamePiece/GamePiece.cpp
        Classes/AbstractClasses/Character/Character.cpp
        Classes/Enemy/Enemy.cpp
        Classes/Ability/Ability.cpp
        Classes/AbstractClasses/Item/Item.cpp)

