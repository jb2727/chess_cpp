#include "definitions.hpp"
#include <stdexcept>

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