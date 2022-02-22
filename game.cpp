#include "fen.hpp"
#include "board.hpp"
#include "coord.hpp"


class Game
{
public:
    Game(Fen StartingPosition)
    {

    }

private:
    char turn;
    struct CastleStatus{
        bool whiteKingSide;
        bool whiteQueenSide;
        bool blackKingSide;
        bool blackQueenSide;
    } castleIndicators;
    Coord enPassantSquare; 
    int conseqNoPawnMoves;
    int moveNumber;
};

//#define STARTING_FEN_POSITION "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"
