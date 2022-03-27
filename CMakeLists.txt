cmake_minimum_required(VERSION 3.20.0)

project(CPPHESS)

add_executable(${PROJECT_NAME} ./src/main.cpp 
./src/board.cpp 
./src/coord.cpp 
./src/definitions.cpp 
./src/fen.cpp 
./src/game.cpp 
./src/piece.cpp 
./src/terminal_display.cpp)