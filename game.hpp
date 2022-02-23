#ifndef GAME_HPP
#define GAME_HPP

#include "fen.hpp"
#include "board.hpp"
#include "coord.hpp"
#include <memory>

using namespace std;

class Game
{
public:
    Game(Fen StartingPosition);

private:
    void constructInternalParams(Fen boardDescription);
    char turn;
    unique_ptr<CastleStatus> castle;
    unique_ptr<Coord> enPassantSquare;
    int conseqNoPawnMoves;
    int moveNumber;
    unique_ptr<Board> board;
};

#endif
