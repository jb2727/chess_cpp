#include "definitions.hpp"
#include <stdexcept>
#include <iostream>
#include <sstream>

struct Coord 
{
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