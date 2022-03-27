#include "coord.hpp"
#include <map>
#include <array>

using namespace std;

//perhaps these should be made static and go into Coord? 
map<char, int> x_AxisCharToIndex = 
{
    {'a', 0},
    {'b', 1},
    {'c', 2},
    {'d', 3},

    {'e', 4},
    {'f', 5},
    {'g', 6},
    {'h', 7}
};

map<char, int> y_AxisCharToIndex = 
{
    {'1', 0},
    {'2', 1},
    {'3', 2},
    {'4', 3},

    {'5', 4},
    {'6', 5},
    {'7', 6},
    {'8', 7}
};


int Coord::getAbsXDiff(Coord newPos)
{
    return abs(this->X - newPos.X);
}
int Coord::getAbsYDiff(Coord newPos)
{
    return abs(this->Y - newPos.Y);
}
array<int,2> Coord::convertStringCoordsToInts(char x_axis, char y_axis)
    {
        array<int,2> indexes;
        indexes.at(0) = x_AxisCharToIndex.at(x_axis);
        indexes.at(1) = y_AxisCharToIndex.at(y_axis);
        return indexes;
    }

BoardCoord::BoardCoord(int X, int Y) 

{  
    setCoords(X,Y);
}
BoardCoord::BoardCoord(char xAxis, char yAxis)

{
    array<int,2> indexes = convertStringCoordsToInts(xAxis, yAxis);
    setCoords(indexes.at(0), indexes.at(1));
}

void BoardCoord::setCoords(int X, int Y)
{
    if (X > BOARD_WIDTH || Y > BOARD_LENGTH) 
    {
        std::ostringstream error_message;

        error_message << "invalid arguments, coordinates: " << X << "and" << Y << 
        "must be less than the board's width: " << BOARD_WIDTH << 
        "and the board's length:" << BOARD_LENGTH << "respectively" << std::endl;

        throw invalid_argument(error_message.str());
    }
    this->X = X;
    this->Y = Y;
}



EnPassantCoord::EnPassantCoord(int X, int Y, bool enPassant) : BoardCoord(X, Y)
{
    this->enPassant = enPassant;
}
EnPassantCoord::EnPassantCoord(char xAxis, char yAxis, bool enPassant) : BoardCoord(xAxis, yAxis){
    this->enPassant = enPassant;
}
