#include "definitions.hpp"
#include <stdexcept>
#include <iostream>
#include <sstream>

struct Coord 
{
    int getAbsXDiff(Coord newPos);
    int getAbsYDiff(Coord newPos);
    public:
    int X;
    int Y;
};

//version of Coord that enforces board boundary limitations 
struct BoardCoord : Coord
{
    public:
    BoardCoord(int X, int Y);
};