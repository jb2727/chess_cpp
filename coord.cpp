#include "coord.hpp"

struct Coord 
{
    public:
    int getAbsXDiff(Coord newPos)
    {
        return std::abs(this->X - newPos.X);
    }
    int getAbsYDiff(Coord newPos)
    {
        return std::abs(this->Y - newPos.Y);
    }
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
            std::ostringstream error_message;

            error_message << "invalid arguments, coordinates: " << X << "and" << Y << 
            "must be less than the board's width: " << BOARD_WIDTH << 
            "and the board's length:" << BOARD_LENGTH << "respectively" << std::endl;

            throw std::invalid_argument(error_message.str());
        }
        this->X = X;
        this->Y = Y;
    } 
};

