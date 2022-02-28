#ifndef PIECE_HPP 
#define PIECE_HPP

#include "definitions.hpp"
#include "coord.hpp"

namespace piece_ns{

enum Team_t
{
    white = 0,
    black = 1,
    noteam
};

enum Type_t
{
    king,
    queen,
    rook,
    bishop,
    knight,
    pawn,
    notype
};
}

class Piece 
{
    public:
    Piece(piece_ns::Team_t team);
    virtual bool ValidMovementPattern(BoardCoord startPos, BoardCoord endPos) = 0;
    virtual bool ValidAttackPattern(BoardCoord startPos, BoardCoord endPos) = 0;
    char getFenSymbol();
    piece_ns::Team_t getTeam();
    piece_ns::Type_t getType();
    int getValue();

    protected:
    char fenSymbol = '\0';
    piece_ns::Team_t team = piece_ns::noteam;
    piece_ns::Type_t type = piece_ns::notype;
    int value = 0;
    
};

class King : public Piece 
{
    public:
    King(piece_ns::Team_t team);
    bool ValidMovementPattern(BoardCoord startPos, BoardCoord endPos);
    bool ValidAttackPattern(BoardCoord startPos, BoardCoord endPos);

    private:
    bool kingActionPattern(BoardCoord startPos, BoardCoord endPos);
    
};

class Queen : public Piece 
{
    public:
    Queen(piece_ns::Team_t team);
    bool ValidMovementPattern(BoardCoord startPos, BoardCoord endPos);
    bool ValidAttackPattern(BoardCoord startPos, BoardCoord endPos);

    private:
    bool queenActionPattern(BoardCoord startPos, BoardCoord endPos);
};

class Rook : public Piece 
{
    public:
    Rook(piece_ns::Team_t team);
    bool ValidMovementPattern(BoardCoord startPos, BoardCoord endPos);
    bool ValidAttackPattern(BoardCoord startPos, BoardCoord endPos);

    private:
    bool rookActionPattern(BoardCoord startPos, BoardCoord endPos);
};

class Bishop : public Piece 
{
    public:
    Bishop(piece_ns::Team_t team);
    bool ValidMovementPattern(BoardCoord startPos, BoardCoord endPos);
    bool ValidAttackPattern(BoardCoord startPos, BoardCoord endPos);

    private:
    bool bishopActionPattern(BoardCoord startPos, BoardCoord endPos);
};

class Knight : public Piece 
{
    public:
    Knight(piece_ns::Team_t team);
    bool ValidMovementPattern(BoardCoord startPos, BoardCoord endPos);
    bool ValidAttackPattern(BoardCoord startPos, BoardCoord endPos);

    private:
    bool knightActionPattern(BoardCoord startPos, BoardCoord endPos);
    
};

class Pawn : public Piece 
{
    public:
    Pawn(piece_ns::Team_t team);
    bool ValidMovementPattern(BoardCoord startPos, BoardCoord endPos);
    bool ValidAttackPattern(BoardCoord startPos, BoardCoord endPos);

    private:
    
};

#endif
