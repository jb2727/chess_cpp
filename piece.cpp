#include <string>
#include "piece.hpp"

typedef enum Team_t
{
    white = 0,
    black = 1
} Team_t;

typedef enum Type_t
{
    King,
    Queen,
    Rook,
    Bishop,
    Knight,
    Pawn
};

class Piece 
{
    public:
    Piece()
    {

    }

    private:
    char fenSymbol;
    Team_t team;
    Type_t type;
    int value;
    
};


class King : Piece 
{
    public:

    private:
    
};

class Queen : Piece
{
    public:

    private:
    
};

class Rook : Piece 
{
    public:

    private:
    
};

class Bishop : Piece
{
    public:

    private:
    
};

class Knight : Piece 
{
    public:

    private:
    
};

class Pawn : Piece 
{
    public:

    private:
    
};
