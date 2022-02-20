#include <string>
#include "piece.hpp"
#include "definitions.hpp"
#include "coord.hpp"
#include <cmath>


/**
 * Does having seperate constructors for each Piece make sense? I guess so because this keeps the definitions all in one place, the objects creating 
 * each piece only need to know what Piece they want, not all of the details of these pieces (which they would do if we only had a single Piece class 
 * and specified their details via the contructors) 
 * Additionally, having each piece as a seperate class means that we can specifiy different movement and attack patterns for them 
 * 
 */





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
    bool ValidMovementPattern(BoardCoord startPos, BoardCoord endPos);
    bool ValidAttackPattern(BoardCoord startPos, BoardCoord endPos);
    protected:
    char fenSymbol;
    piece_ns::Team_t team;
    piece_ns::Type_t type;
    int value;
    
};


class King : public Piece 
{
    public:
    King(piece_ns::Team_t team) : Piece(team)
    {
        this->type = piece_ns::king;
        this->value = KING_VALUE;
        this->fenSymbol = (piece_ns::white == this->team) ? WHITE_KING_SYMBOL : BLACK_KING_SYMBOL;
    }
    //check the post you made on the internet about this!!!
    bool ValidMovementPattern(BoardCoord startPos, BoardCoord endPos)
    {
        if (std::abs(startPos.X - endPos.X) > 1){
            return false;
        }
        if (std::abs(startPos.Y - endPos.Y) > 1){
            return false;
        }
        return true;
    }
    bool ValidAttackPattern(BoardCoord startPos, BoardCoord endPos);
    private:
    
};

class Queen : Piece
{
    public:
    Queen(piece_ns::Team_t team) : Piece(team)
    {
        this->type = piece_ns::queen;
        this->value = QUEEN_VALUE;
        this->fenSymbol = (piece_ns::white == this->team) ? WHITE_QUEEN_SYMBOL : BLACK_QUEEN_SYMBOL;
    }
    private:
    
};

class Rook : Piece 
{
    public:
    Rook(piece_ns::Team_t team) : Piece(team)
    {
        this->type = piece_ns::rook;
        this->value = ROOK_VALUE;
        this->fenSymbol = (piece_ns::white == this->team) ? WHITE_ROOK_SYMBOL : BLACK_ROOK_SYMBOL;
    }
    private:
    
};

class Bishop : Piece
{
    public:
    Bishop(piece_ns::Team_t team) : Piece(team)
    {
        this->type = piece_ns::bishop;
        this->value = BISHOP_VALUE;
        this->fenSymbol = (piece_ns::white == this->team) ? WHITE_BISHOP_SYMBOL : BLACK_BISHOP_SYMBOL;
    }
    private:
    
};

class Knight : Piece 
{
    public:
    Knight(piece_ns::Team_t team) : Piece(team)
    {
        this->type = piece_ns::knight;
        this->value = KNIGHT_VALUE;
        this->fenSymbol = (piece_ns::white == this->team) ? WHITE_KNIGHT_SYMBOL : BLACK_KNIGHT_SYMBOL;
    }
    private:
    
};

class Pawn : Piece 
{
    public:
    Pawn(piece_ns::Team_t team) : Piece(team)
    {
        this->type = piece_ns::pawn;
        this->value = PAWN_VALUE;
        this->fenSymbol = (piece_ns::white == this->team) ? WHITE_PAWN_SYMBOL : BLACK_PAWN_SYMBOL;
    }
    private:
    
};
