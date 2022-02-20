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
    char getFenSymbol()
    {
        return fenSymbol;
    }
    piece_ns::Team_t getTeam()
    {
        return team;
    }
    piece_ns::Type_t getType()
    {
        return type;
    }
    int getValue()
    {
        return value;
    }

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
        return kingActionPattern(startPos, endPos);
    }
    bool ValidAttackPattern(BoardCoord startPos, BoardCoord endPos)
    {
        return kingActionPattern(startPos, endPos);
    }

    private:
    //King (and every piece except Pawn) have the exact same movement patterns for movement and attack, therefore define a common method for both of them 
    bool kingActionPattern(BoardCoord startPos, BoardCoord endPos)
    {
        if (std::abs(startPos.X - endPos.X) > 1){
            return false;
        }
        if (std::abs(startPos.Y - endPos.Y) > 1){
            return false;
        }
        return true;
    }
};

class Queen : public Piece
{
    public:
    Queen(piece_ns::Team_t team) : Piece(team)
    {
        this->type = piece_ns::queen;
        this->value = QUEEN_VALUE;
        this->fenSymbol = (piece_ns::white == this->team) ? WHITE_QUEEN_SYMBOL : BLACK_QUEEN_SYMBOL;
    }
    bool ValidMovementPattern(BoardCoord startPos, BoardCoord endPos)
    {
        return queenActionPattern(startPos, endPos);
    }
    bool ValidAttackPattern(BoardCoord startPos, BoardCoord endPos)
    {
        return queenActionPattern(startPos, endPos);
    }

    private:
    bool queenActionPattern(BoardCoord startPos, BoardCoord endPos)
    {
        //diagonal movement 
        if (std::abs(startPos.X - endPos.X) == 
            std::abs(startPos.Y - endPos.Y))
            {
            return true;
            }
        //orthagonal vertical movement
        if (std::abs(startPos.Y - endPos.Y) > 0 &&
            (std::abs(startPos.X - endPos.X) == 0))
            {
            return true;    
            }
        //orthagonal horizontal movement
        if (std::abs(startPos.X - endPos.X) > 0 &&
            (std::abs(startPos.Y - endPos.Y) == 0))
            {
            return true;    
            }
        
        //movement is not diagonal or orthagonal
        return false;
    }
    
};

class Rook : public Piece 
{
    public:
    Rook(piece_ns::Team_t team) : Piece(team)
    {
        this->type = piece_ns::rook;
        this->value = ROOK_VALUE;
        this->fenSymbol = (piece_ns::white == this->team) ? WHITE_ROOK_SYMBOL : BLACK_ROOK_SYMBOL;
    }
    bool ValidMovementPattern(BoardCoord startPos, BoardCoord endPos)
    {
        return rookActionPattern(startPos, endPos);
    }
    bool ValidAttackPattern(BoardCoord startPos, BoardCoord endPos)
    {
        return rookActionPattern(startPos, endPos);
    }

    private:
    bool rookActionPattern(BoardCoord startPos, BoardCoord endPos)
    {
        //orthagonal vertical movement
        if (std::abs(startPos.Y - endPos.Y) > 0 &&
            (std::abs(startPos.X - endPos.X) == 0))
            {
            return true;    
            }
        //orthagonal horizontal movement
        if (std::abs(startPos.X - endPos.X) > 0 &&
            (std::abs(startPos.Y - endPos.Y) == 0))
            {
            return true;    
            }
        
        //movement is not orthagonal
        return false;
    }
    
};

class Bishop : public Piece
{
    public:
    Bishop(piece_ns::Team_t team) : Piece(team)
    {
        this->type = piece_ns::bishop;
        this->value = BISHOP_VALUE;
        this->fenSymbol = (piece_ns::white == this->team) ? WHITE_BISHOP_SYMBOL : BLACK_BISHOP_SYMBOL;
    }
    bool ValidMovementPattern(BoardCoord startPos, BoardCoord endPos)
    {
        return bishopActionPattern(startPos, endPos);
    }
    bool ValidAttackPattern(BoardCoord startPos, BoardCoord endPos)
    {
        return bishopActionPattern(startPos, endPos);
    }

    private:
    bool bishopActionPattern(BoardCoord startPos, BoardCoord endPos)
    {
        //diagonal movement 
        if (std::abs(startPos.X - endPos.X) == 
            std::abs(startPos.Y - endPos.Y))
            {
            return true;
            }
        //movement is not diagonal
        return false;
    }
};

class Knight : public Piece 
{
    public:
    Knight(piece_ns::Team_t team) : Piece(team)
    {
        this->type = piece_ns::knight;
        this->value = KNIGHT_VALUE;
        this->fenSymbol = (piece_ns::white == this->team) ? WHITE_KNIGHT_SYMBOL : BLACK_KNIGHT_SYMBOL;
    }
    bool ValidMovementPattern(BoardCoord startPos, BoardCoord endPos)
    {
        return knightActionPattern(startPos, endPos);
    }
    bool ValidAttackPattern(BoardCoord startPos, BoardCoord endPos)
    {
        return knightActionPattern(startPos, endPos);
    }

    private:
    bool knightActionPattern(BoardCoord startPos, BoardCoord endPos)
    {
        if ((std::abs(startPos.Y - endPos.Y) == 2) &&
            (std::abs(startPos.X - endPos.X) == 1))
        {
            return true;
        }
        if ((std::abs(startPos.Y - endPos.Y) == 1) &&
            (std::abs(startPos.X - endPos.X) == 2))
        {
            return true;
        }
        //movement is not L shaped (2 in one direction, one in another direction)
        return false;
    }
    
};

class Pawn : public Piece 
{
    public:
    Pawn(piece_ns::Team_t team) : Piece(team)
    {
        this->type = piece_ns::pawn;
        this->value = PAWN_VALUE;
        this->fenSymbol = (piece_ns::white == this->team) ? WHITE_PAWN_SYMBOL : BLACK_PAWN_SYMBOL;
    }
    //unlike the other pieces, movement and attack patterns for pawns are different 
    bool ValidMovementPattern(BoardCoord startPos, BoardCoord endPos)
    {
       if ((startPos.X == endPos.X) && 
            (endPos.Y - startPos.Y == 1))
       {
           return true;
       }
       return false;
    }
    bool ValidAttackPattern(BoardCoord startPos, BoardCoord endPos)
    {
        //note, en passant logic should be handled by board Module as the fundlemental movement pattern
        if ((std::abs(endPos.X - startPos.X) == 1) &&
            (endPos.Y - startPos.Y == 1))
            {
                return true;        
            }
        return false;
    }
    private:
    
};
