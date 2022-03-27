#ifndef COORD_HPP
#define COORD_HPP

#include "definitions.hpp"
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <array>

using namespace std;

struct Coord 
{
    public:
    int getAbsXDiff(Coord newPos);
    int getAbsYDiff(Coord newPos);
    static array<int,2> convertStringCoordsToInts(char x_axis, char y_axis);
    int X;
    int Y;
    
};

//version of Coord that enforces board boundary limitations 
struct BoardCoord : public Coord
{
    public:
    BoardCoord(int X, int Y);
    BoardCoord(char xAxis, char yAxis);
    private:
    void setCoords(int X, int Y);
};

struct EnPassantCoord : public BoardCoord 
{
    public: 
    EnPassantCoord(int X, int Y, bool enPassant);
    EnPassantCoord(char xAxis, char yAxis, bool enPassant);
    bool enPassant;
};

#endif
