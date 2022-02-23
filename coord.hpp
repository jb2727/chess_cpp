#ifndef COORD_HPP
#define COORD_HPP

#include "definitions.hpp"
#include <stdexcept>
#include <iostream>
#include <sstream>

struct Coord 
{
    public:
    int getAbsXDiff(Coord newPos);
    int getAbsYDiff(Coord newPos);
    int X;
    int Y;
};

//version of Coord that enforces board boundary limitations 
struct BoardCoord : Coord
{
    public:
    BoardCoord(int X, int Y);
    BoardCoord(char xAxis, int yAxis);
};

struct EnPassantCoord : public BoardCoord 
{
    public: 
    EnPassantCoord(int X = 0, int Y = 0);
    EnPassantCoord(char xAxis, int yAxis);
    bool enPassant;


};

#endif
