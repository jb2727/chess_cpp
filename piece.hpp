#include "definitions.hpp"

namespace piece_ns{

typedef enum Team_t
{
    white = 0,
    black = 1
} Team_t;

typedef enum Type_t
{
    king,
    queen,
    rook,
    bishop,
    knight,
    pawn
};
}

class Piece 
{
    public:
    Piece(piece_ns::Team_t team);

    protected:
    char fenSymbol;
    piece_ns::Team_t team;
    piece_ns::Type_t type;
    int value;
    
};

class King : public Piece 
{
    public:
    King(piece_ns::Team_t team);

    private:
    
};

class Queen : public Piece 
{
    public:
    Queen(piece_ns::Team_t team);

    private:
    
};

class Rook : public Piece 
{
    public:
    Rook(piece_ns::Team_t team);

    private:
    
};

class Bishop : public Piece 
{
    public:
    Bishop(piece_ns::Team_t team);

    private:
    
};

class Knight : public Piece 
{
    public:
    Knight(piece_ns::Team_t team);

    private:
    
};

class Pawn : public Piece 
{
    public:
    Pawn(piece_ns::Team_t team);

    private:
    
};