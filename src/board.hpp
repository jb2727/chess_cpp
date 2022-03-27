#ifndef BOARD_HPP 
#define BOARD_HPP

#include <array>
#include <vector>
#include <string>
#include <algorithm>
#include "piece.hpp"
#include "fen.hpp"
#include "definitions.hpp"
#include "coord.hpp"

using namespace std;



class Board
{

    public:
    Board(Fen * startState);
    void movePiece(BoardCoord startPos, BoardCoord endPos);
    void setBoard(Fen * input);

    private:
    array<array<Piece* , 8>, 8> boardMap;
    bool piecesInbetween(BoardCoord startPos, BoardCoord endPos);
    
};

#endif
