#include "coord.hpp"

struct Coord 
{
    public:
    int X;
    int Y;
};

//version of Coord that enforces board boundary limitations 
struct BoardCoord : public Coord
{
    public:
    BoardCoord(int X, int Y) 
    {  
        if (X > BOARD_WIDTH || Y > BOARD_LENGTH) 
        {
            throw std::invalid_argument("invalid argument"); 

        }
        this->X = X;
        this->Y = Y;
    } 
};

