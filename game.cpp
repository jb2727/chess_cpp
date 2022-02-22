#include "fen.hpp"
#include "board.hpp"
#include "coord.hpp"
#include <memory>

using namespace std;

class Game
{
public:
    Game(Fen StartingPosition)
    {
        castle.reset(new CastleStatus); //setting castle to point to the struct, this is not necessary since CastleStatus has a default constructor, but still doing it anyway to be consistent 
        constructInternalParams(StartingPosition);
    }

private:
    void constructInternalParams(Fen boardDescription)
    
    {
        this->turn = boardDescription.GetTurnIndicator();
        this->conseqNoPawnMoves = boardDescription.GetConseqNoPawnMoves();
        this->moveNumber = boardDescription.GetMoveNumber();
        //note to self, I'm unsure whether this is the cleanest way of doing this, think about this tomorrow morning after I've had some stimulants
        CastleStatus castleObject = *(boardDescription.GetCastling());
        castle.reset(&castleObject);
        Coord enPassantSquareObject = *(boardDescription.GetEnPassantSquare());
        enPassantSquare.reset(&enPassantSquareObject);
    }

    char turn;
    unique_ptr<CastleStatus> castle;
    unique_ptr<Coord> enPassantSquare; 
    int conseqNoPawnMoves;
    int moveNumber;
};

//#define STARTING_FEN_POSITION "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"
