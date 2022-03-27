#include "game.hpp"
#include "fen.hpp"
#include "board.hpp"
#include "coord.hpp"
#include <memory>

using namespace std;


Game::Game(Fen * StartingPosition)
{
    castle.reset(new CastleStatus); //setting castle to point to the struct, this is not necessary since CastleStatus has a default constructor, but still doing it anyway to be consistent 
    constructInternalParams(StartingPosition);
    board.reset(new Board(StartingPosition));

}

void Game::constructInternalParams(Fen * boardDescription) 
{
    this->turn = boardDescription->GetTurnIndicator();
    this->conseqNoPawnMoves = boardDescription->GetConseqNoPawnMoves();
    this->moveNumber = boardDescription->GetMoveNumber();
    //note to self, I'm unsure whether this is the cleanest way of doing this, think about this tomorrow morning after I've had some stimulants
    //cloning an object and then getting the pointer of it since we're storing variable references via pointers for the sake of consistency 
    CastleStatus castleObject = *(boardDescription->GetCastling());
    castle.reset(&castleObject);
    Coord enPassantSquareObject = *(boardDescription->GetEnPassantSquare());
    enPassantSquare.reset(&enPassantSquareObject);
}



