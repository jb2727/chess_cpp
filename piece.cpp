#include <string>
#include "piece.hpp"
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

#define KING_VALUE 100
#define QUEEN_VALUE 9 
#define ROOK_VALUE 5
#define BISHOP_VALUE 3
#define KNIGHT_VALUE 3
#define PAWN_VALUE 1

class Piece 
{
    public:
    Piece(piece_ns::Team_t team)
    {
        this->team = team;
    }

    protected:
    char fenSymbol;
    piece_ns::Team_t team;
    piece_ns::Type_t type;
    int value;
    
};


class King : Piece 
{
    public:
    King(piece_ns::Team_t team) : Piece(team)
    {
        this->type = piece_ns::king;
        this->value = KING_VALUE;
        this->fenSymbol = (piece_ns::white == this->team) ? : 'k'
    }
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
